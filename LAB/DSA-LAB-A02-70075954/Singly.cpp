#include <iostream>
#include "Node.cpp"

namespace Saadin {
   class Singly {
   private:
      Saadin::Node* m_Head;
      int m_Size;

   public:
      Singly();

      void InsertAtStart(const int&);
      void InsertAtLast(const int&);
      void InsertAtPosition(const int&, const int&);

      void DeleteFromStart();
      void DeleteFromPosition(const int&);
      void DeleteFromEnd();

      bool Search(const int&);
      void Sort(bool);

      int GetSize() const;
      bool IsEmpty() const;
      void Display() const;
   };
}

Saadin::Singly::Singly() {
   this->m_Size = 0;
   this->m_Head = NULL;
}

void Saadin::Singly::InsertAtStart(const int& Data) {
   this->m_Head = new Node(Data, this->m_Head);
   ++(this->m_Size);
}

void Saadin::Singly::InsertAtLast(const int& Data) {
   if (this->m_Head == NULL) {
      this->InsertAtStart(Data);
      return;
   }

   Saadin::Node* Hold = this->m_Head;
   while (Hold->GetNext() != NULL) {
      Hold = Hold->GetNext();
   }

   Saadin::Node* Packet = new Saadin::Node(Data);
   Hold->SetNext(Packet);
   ++(this->m_Size);
}

void Saadin::Singly::InsertAtPosition(const int& Data, const int& Position) {
   if (Position < 0 || Position > this->m_Size) {
      return;
   }

   if (this->IsEmpty() || Position == 0) {
      this->InsertAtStart(Data);
      return;
   }

   Node* Hold = this->m_Head;
   for (int Saadin_i = 1; Saadin_i < Position; Saadin_i++) {
      Hold = Hold->GetNext();
   }

   Node* Packet = new Node(Data, Hold->GetNext());
   Hold->SetNext(Packet);
   ++(this->m_Size);
}

void Saadin::Singly::DeleteFromStart() {
   Node* Hold = this->m_Head;
   this->m_Head = Hold->GetNext();
   delete Hold;
   --(this->m_Size);
}

void Saadin::Singly::DeleteFromPosition(const int& Position) {
   if (Position < 0 || Position > this->m_Size) {
      return;
   }

   --(this->m_Size);

   if (Position == 0) {
      Saadin::Node* Hold = this->m_Head;
      this->m_Head = Hold->GetNext();
      delete Hold;
      return;
   }

   Saadin::Node* Hold = this->m_Head;
   for (int Saadin_i = 0; Saadin_i < Position - 1;++Saadin_i) {
      Hold = Hold->GetNext();
   }

   Saadin::Node* Keep = Hold->GetNext()->GetNext();
   delete Hold->GetNext();
   Hold->SetNext(Keep);
}

void Saadin::Singly::DeleteFromEnd() {
   Node* Hold = this->m_Head;
   for (int Saadin_i = 2; Saadin_i < this->m_Size; ++Saadin_i) {
      Hold = Hold->GetNext();
   }

   delete Hold->GetNext();
   Hold->SetNext(NULL);
   --(this->m_Size);
}

bool Saadin::Singly::Search(const int& ID) {
   Saadin::Node* Hold = this->m_Head;
   while (Hold != NULL) {
      if (Hold->GetData() == ID) {
         return true;
      }
      Hold = Hold->GetNext();
   }
   return false;
}

void Saadin::Singly::Sort(bool Ascending = true) {
   Saadin::Node* Hold = this->m_Head;
   while (Hold != NULL) {
      Saadin::Node* Suppose = Hold;
      Saadin::Node* NextSupposed = Hold->GetNext();

      while (NextSupposed != NULL) {
         if (Ascending
            ? Suppose->GetData() > NextSupposed->GetData()
            : Suppose->GetData() < NextSupposed->GetData()) {
            Suppose = NextSupposed;
         }
         NextSupposed = NextSupposed->GetNext();
      }

      int Temp = Hold->GetData();
      Hold->SetData(Suppose->GetData());
      Suppose->SetData(Temp);
      Hold = Hold->GetNext();
   }
}

int Saadin::Singly::GetSize() const {
   return this->m_Size;
}

bool Saadin::Singly::IsEmpty() const {
   return this->m_Head == NULL;
}

void Saadin::Singly::Display() const {
   Saadin::Node* Hold = this->m_Head;
   for (int Saadin_i = 0; Hold != NULL; ++Saadin_i) {
      std::cout << ' ' << char(175) << " @position[" << Saadin_i << "]:\t" << Hold->GetData() << std::endl;
      Hold = Hold->GetNext();
   }
}