// DSA-LAB-QUIZ-01
// STUDNET NAME: Saad Mansoor
// SAP-ID:       70075954
// COURSE:       Data Structures & Algorithms
// DATED:        March 31, 2021 - Wednesday
// BSCS-4/C1 - Department of Computer Science & Information Technology
// University of Lahore, Gujrat Campus
#include <iostream>
#include <string>
////////////////////////////////////////////////////////////////////////////////////////////////
struct Employee {
   std::string Name;
   int Age;
   float Salary;
   int ID;
};
////////////////////////////////////////////////////////////////////////////////////////////////
class Node {
private:
   Employee m_Data;
   Node* m_Next;
public:
   Node();
   Node(const Employee&);
   Node(const Employee&, Node*);
   void SetData(const Employee&);
   void SetNext(Node*);
   Employee GetData() const;
   Node* GetNext() const;
};
////////////////////////////////////////////////////////////////////////////////////////////////
Node::Node() : m_Data({ "Not Specified Yet", -1, -1.0f, -1 }), m_Next(NULL) {}
Node::Node(const Employee& Data) : m_Data(Data), m_Next(NULL) {}
Node::Node(const Employee& Data, Node* Next) : m_Data(Data), m_Next(Next) {}
void Node::SetData(const Employee& Data) { this->m_Data = Data; }
void Node::SetNext(Node* Next) { this->m_Next = Next; }
Employee Node::GetData()const { return this->m_Data; }
Node* Node::GetNext()const { return this->m_Next; }
////////////////////////////////////////////////////////////////////////////////////////////////
class Singly {
private:
   Node* m_Head;
   int m_Size;

public:
   Singly();
   void InsertAtStart(const Employee&);
   void InsertAtLast(const Employee&);
   void DeleteFromPosition(const int&);
   void SearchByID(const int&);
   int GetSize() const;
   void Display() const;
};
////////////////////////////////////////////////////////////////////////////////////////////////
int main() {
   Singly List;
   List.InsertAtStart({ "Saad Mansoor", 21, 25000, 69 });
   List.InsertAtStart({ "Ali Ahsan", 20, 35000, 33 });
   List.InsertAtLast({ "Umar Asghar", 21, 55000, 77 });
   List.Display();

   std::cout << "AFTER DELETING POSTION 2" << std::endl;
   List.DeleteFromPosition(2);
   List.Display();

   std::cout << "LET'S SEARCH RECORD FOR ID 69" << std::endl;
   List.SearchByID(69);

   system("PAUSE");
   return EXIT_SUCCESS;
}
////////////////////////////////////////////////////////////////////////////////////////////////
Singly::Singly() :m_Size(0), m_Head(NULL) {}
////////////////////////////////////////////////////////////////////////////////////////////////
void Singly::InsertAtStart(const Employee& Data) {
   this->m_Head = new Node(Data, this->m_Head);
   ++(this->m_Size);
}
////////////////////////////////////////////////////////////////////////////////////////////////
void Singly::InsertAtLast(const Employee& Data) {
   if (this->m_Head == NULL) {
      this->InsertAtStart(Data);
      return;
   }

   Node* Hold = this->m_Head;
   while (Hold->GetNext() != NULL) {
      Hold = Hold->GetNext();
   }

   Node* Packet = new Node(Data);
   Hold->SetNext(Packet);
   ++(this->m_Size);
}
////////////////////////////////////////////////////////////////////////////////////////////////
void Singly::DeleteFromPosition(const int& Position) {
   if (Position < 0 || Position > this->m_Size) {
      std::cout << "Invalid Position!" << std::endl;
      return;
   }

   --(this->m_Size);

   if (Position == 0) {
      Node* Hold = this->m_Head;
      this->m_Head = Hold->GetNext();
      delete Hold;
      return;
   }

   Node* Hold = this->m_Head;
   for (int i = 0; i < Position - 1;++i) {
      Hold = Hold->GetNext();
   }

   Node* Keep = Hold->GetNext()->GetNext();
   delete Hold->GetNext();
   Hold->SetNext(Keep);
}
////////////////////////////////////////////////////////////////////////////////////////////////
void Singly::SearchByID(const int& ID) {
   Node* Hold = this->m_Head;
   while (Hold != NULL) {
      Employee Data = Hold->GetData();
      if (Data.ID == ID) {
         std::cout << " > ID:\t\t" << Data.ID << std::endl
            << " > Name:\t" << Data.Name << std::endl
            << " > Salary:\t" << Data.Salary << " rupees" << std::endl
            << " > Age:\t\t" << Data.Age << " years" << std::endl
            << std::endl;
      }
      Hold = Hold->GetNext();
   }
   std::cout << "Record Not Found!" << std::endl;
}
////////////////////////////////////////////////////////////////////////////////////////////////
int Singly::GetSize() const {
   return this->m_Size;
}
////////////////////////////////////////////////////////////////////////////////////////////////
void Singly::Display() const {
   Node* Hold = this->m_Head;
   for (int i = 0; Hold != NULL; ++i) {
      Employee Data = Hold->GetData();
      std::cout << "@position[" << i << "]" << std::endl
         << " > ID:\t\t" << Data.ID << std::endl
         << " > Name:\t" << Data.Name << std::endl
         << " > Salary:\t" << Data.Salary << " rupees" << std::endl
         << " > Age:\t\t" << Data.Age << " years" << std::endl
         << std::endl;
      Hold = Hold->GetNext();
   }
}
////////////////////////////////////////////////////////////////////////////////////////////////