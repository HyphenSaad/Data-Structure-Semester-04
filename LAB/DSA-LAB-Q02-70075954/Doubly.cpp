#include <iostream>
#include "Node.cpp"
////////////////////////////////////////////////////////////////////////////////////////////////
namespace Saadin {
   class Doubly;
}
////////////////////////////////////////////////////////////////////////////////////////////////
class Saadin::Doubly {
private:
   Saadin::Node* m_Head;
   int m_Size;

public:
   Doubly();

   void InsertAtStart(const Saadin::Employee&);
   void InsertAtLast(const Saadin::Employee&);
   void DeleteFromPosition(const int&);
   void DeleteFromLast();

   void SearchByID(const int&);
   int GetSize() const;
   void Display() const;
};
////////////////////////////////////////////////////////////////////////////////////////////////
Saadin::Doubly::Doubly() {
   this->m_Size = 0;
   this->m_Head = NULL;
}
////////////////////////////////////////////////////////////////////////////////////////////////
void Saadin::Doubly::InsertAtStart(const Saadin::Employee& Data) {
   Saadin::Node* Packet = new Saadin::Node(Data, this->m_Head);
   if (this->m_Head != NULL) this->m_Head->SetPrevious(Packet);
   this->m_Head = Packet;
   ++(this->m_Size);
}
////////////////////////////////////////////////////////////////////////////////////////////////
void Saadin::Doubly::InsertAtLast(const Saadin::Employee& Data) {
   if (this->m_Head == NULL) {
      this->InsertAtStart(Data);
      return;
   }

   Saadin::Node* Hold = this->m_Head;
   while (Hold->GetNext() != NULL) Hold = Hold->GetNext();

   Saadin::Node* Packet = new Saadin::Node(Data, NULL, Hold);
   Hold->SetNext(Packet);
   ++(this->m_Size);
}
////////////////////////////////////////////////////////////////////////////////////////////////
void Saadin::Doubly::DeleteFromPosition(const int& Position) {
   if (Position < 0 || Position > this->m_Size) {
      std::cout << "Invalid Position!" << std::endl;
      return;
   }
   --(this->m_Size);

   Saadin::Node* Hold = this->m_Head;

   if (Position == 0) {
      this->m_Head = Hold->GetNext();
      this->m_Head->SetPrevious(NULL);
      delete Hold;
      return;
   }

   for (int i = 0; i < Position;++i) Hold = Hold->GetNext();

   Hold->GetPrevious()->SetNext(Hold->GetNext());
   if (Hold->GetNext() != NULL) Hold->GetNext()->SetPrevious(Hold->GetPrevious());
   delete Hold;
}
////////////////////////////////////////////////////////////////////////////////////////////////
void Saadin::Doubly::DeleteFromLast() {
   this->DeleteFromPosition(this->m_Size - 1);
}
////////////////////////////////////////////////////////////////////////////////////////////////
void Saadin::Doubly::SearchByID(const int& ID) {
   Saadin::Node* Hold = this->m_Head;
   while (Hold != NULL) {
      Saadin::Employee Data = Hold->GetData();
      if (Data.ID == ID) {
         std::cout << " > ID:\t\t" << Data.ID << std::endl
            << " > Name:\t" << Data.Name << std::endl
            << std::endl;
         return;
      }
      Hold = Hold->GetNext();
   }
   std::cout << " > Record Not Found!" << std::endl;
}
////////////////////////////////////////////////////////////////////////////////////////////////
int Saadin::Doubly::GetSize() const {
   return this->m_Size;
}
////////////////////////////////////////////////////////////////////////////////////////////////
void Saadin::Doubly::Display() const {
   if (this->m_Head == NULL) {
      std::cout << " > EMPTY!" << std::endl;
      return;
   }

   Saadin::Node* Hold = this->m_Head;
   for (int i = 0; Hold != NULL; ++i) {
      Saadin::Employee Data = Hold->GetData();
      std::cout << "@position[" << i << "]" << std::endl
         << " > ID:\t\t" << Data.ID << std::endl
         << " > Name:\t" << Data.Name << std::endl
         << std::endl;
      Hold = Hold->GetNext();
   }
}
////////////////////////////////////////////////////////////////////////////////////////////////