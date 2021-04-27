#include "List.h"
#define DEFAULT_INITIAL_LENGTH 0

void Hyphen::List::ShowLogs(bool Option) { this->m_ShowLogs = Option; }
void Hyphen::List::Display() const {
   for (int i = 0; i < this->m_Length;++i) {
      std::cout << "value @index[" << i << "] is:\t" << this->m_List[i] << std::endl;
   }
}

void Hyphen::List::CreateList() {
   // To Prevent List From Being Creating; If, it's already created. [Guard Clause]
   if (this->m_List != nullptr) {
      if (this->m_ShowLogs) std::cout << "List Has Been Already Created!" << std::endl;
      return;
   }

   this->m_List = new int[DEFAULT_INITIAL_LENGTH];
   this->m_Length = DEFAULT_INITIAL_LENGTH;

   // To Handle Garbagge Values.
   for (int i = 0; i < this->m_Length; ++i) this->m_List[i] = 0;
}

bool Hyphen::List::Copy(const List* SourceList) {
   // To Prevent From Copying, An Empty List. [Guard Clause]
   if (SourceList->m_List == nullptr) {
      if (this->m_ShowLogs) std::cout << "Source List is Empty!" << std::endl;
      return false;
   }

   // To Delete Exiting List. [Guard Clause]
   if (this->m_List != nullptr) {
      delete[] m_List;
      this->m_List = nullptr;
   }

   this->m_Length = SourceList->m_Length;
   this->m_List = new int[this->m_Length];

   for (int i = 0; i < this->m_Length;++i) {
      this->m_List[i] = SourceList->m_List[i];
   }

   return true;
}

void Hyphen::List::Clear() {
   // To Prevent Empty List From Being Cleared. [Guard Clause]
   if (this->m_List == nullptr) {
      if (this->m_ShowLogs) std::cout << "Can't Clear, Empty List!" << std::endl;
      return;
   }

   delete[] m_List;
   this->m_Length = 0;
   this->m_List = nullptr;
}

void Hyphen::List::Insert(const int& Value, const int& Position) {
   // To Validate Position. [Guard Clause]
   if (Position < 0 || Position > this->m_Length) {
      if (this->m_ShowLogs) std::cout << "Invalid Position, For Insertion!" << std::endl;
      return;
   }

   ++(this->m_Length);
   int* Hold = new int[this->m_Length];
   for (int i = 0, j = 0; i < this->m_Length; ++i) {
      Hold[i] = (i == Position) ? Value : this->m_List[j++];
   }
   delete[] m_List;
   this->m_List = Hold;
}

void Hyphen::List::Remove(const int& Position) {
   // To Validate Position. [Guard Clause]
   if (Position < 0 || Position > this->m_Length || this->m_Length == 0) {
      if (this->m_ShowLogs) std::cout << "Invalid Position, For Removal!" << std::endl;
      return;
   }

   int* Hold = new int[this->m_Length - 1];
   for (int i = 0, j = 0; i < this->m_Length; ++i) {
      if (i != Position) Hold[j++] = this->m_List[i];
   }
   delete[] m_List;
   this->m_List = Hold;
   --(this->m_Length);
}

int Hyphen::List::Get(const int& Position) const {
   // To Validate Position. [Guard Clause]
   if (Position < 0 || Position > this->m_Length) {
      if (this->m_ShowLogs) std::cout << "Invalid Position, To Get Value!" << std::endl;
      return 0;
   }

   return this->m_List[Position];
}

void Hyphen::List::Update(const int& Value, const int& Position) {
   // To Validate Position. [Guard Clause]
   if (Position < 0 || Position > this->m_Length) {
      if (this->m_ShowLogs) std::cout << "Invalid Position, To Update Value!" << std::endl;
      return;
   }

   this->m_List[Position] = Value;
}

bool Hyphen::List::Find(const int& Value) const {
   bool IsThere = false;
   for (int i = 0; i < this->m_Length; ++i) {
      IsThere = (Value == this->m_List[i]);
   }
   return IsThere;
}

int Hyphen::List::Length() const {
   return this->m_Length;
}