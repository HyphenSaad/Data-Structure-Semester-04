#include <iostream>
////////////////////////////////////////////////////////////////////////////////////////////////
class Node {
private:
   int m_Data;
   Node* m_Next;
public:
   Node();
   Node(const int&);
   Node(const int&, Node*);
   void SetData(const int&);
   void SetNext(Node*);
   int GetData()const;
   Node* GetNext()const;
};
////////////////////////////////////////////////////////////////////////////////////////////////
Node::Node() : m_Data(0), m_Next(NULL) {}
Node::Node(const int& Data) : m_Data(Data), m_Next(NULL) {}
Node::Node(const int& Data, Node* Next) : m_Data(Data), m_Next(Next) {}
void Node::SetData(const int& Data) { this->m_Data = Data; }
void Node::SetNext(Node* Next) { this->m_Next = Next; }
int Node::GetData()const { return this->m_Data; }
Node* Node::GetNext()const { return this->m_Next; }
////////////////////////////////////////////////////////////////////////////////////////////////
class Singly {
private:
   Node* m_Head, * m_Current;
   int m_Size;
   bool IsCurrentAtLast = false;

public:
   Singly();
   void InsertAtPosition(const int&, const int&);
   void InsertAtCurrent(const int&);
   void InsertAtStart(const int&);
   void InsertAtEnd(const int&);

   void DeleteFromStart();
   void DeleteFromEnd();
   void DeleteFromCurrent();
   void DeleteFromPosition(const int&);

   Node* GetFromStart();
   Node* GetFromEnd();
   Node* GetFromCurrent();
   Node* GetFromPosition(const int&);

   void SetCurrentAtStart();
   void SetCurrentAtEnd();

   void Sort(bool Ascending);
   bool Search(const int&);

   bool IsEmpty() const;
   int Size() const;
   void Display() const;
};
////////////////////////////////////////////////////////////////////////////////////////////////
Singly::Singly() : m_Head(NULL), m_Current(NULL), m_Size(0) {}
////////////////////////////////////////////////////////////////////////////////////////////////
void Singly::InsertAtPosition(const int& Data, const int& Position) {
   if (Position < 0 || Position > this->m_Size) {
      std::cout << "Invalid Position!" << std::endl;
      return;
   }

   if (this->IsEmpty() || Position == 0) {
      this->InsertAtStart(Data);
      return;
   }

   this->IsCurrentAtLast = Position == this->m_Size;

   Node* Hold = this->m_Head;
   for (int i = 1; i < Position; i++) {
      Hold = Hold->GetNext();
   }

   Node* Packet = new Node(Data, Hold->GetNext());
   Hold->SetNext(Packet);
   this->m_Current = Packet;
   ++(this->m_Size);
}
////////////////////////////////////////////////////////////////////////////////////////////////
void Singly::InsertAtCurrent(const int& Data) {
   if (this->IsEmpty() || this->m_Head == this->m_Current) {
      this->InsertAtStart(Data);
      return;
   }

   Node* Packet = new Node(Data, this->m_Current->GetNext());
   this->m_Current->SetNext(Packet);
   this->m_Current = Packet;
   ++(this->m_Size);
}
////////////////////////////////////////////////////////////////////////////////////////////////
void Singly::InsertAtStart(const int& Data) {
   this->m_Head = new Node(Data, this->m_Head);
   this->m_Current = this->m_Head;
   ++(this->m_Size);
}
////////////////////////////////////////////////////////////////////////////////////////////////
void Singly::InsertAtEnd(const int& Data) {
   if (this->IsEmpty()) {
      this->InsertAtStart(Data);
      return;
   }

   Node* Hold = this->m_Head;
   while (Hold->GetNext() != NULL) {
      Hold = Hold->GetNext();
   }

   Node* Packet = new Node(Data);
   Hold->SetNext(Packet);
   this->m_Current = Packet;
   ++(this->m_Size);
}
////////////////////////////////////////////////////////////////////////////////////////////////
void Singly::DeleteFromStart() {
   Node* Hold = this->m_Head;
   this->m_Head = Hold->GetNext();
   delete Hold;
   this->m_Current = this->m_Head;
   --(this->m_Size);
}
////////////////////////////////////////////////////////////////////////////////////////////////
void Singly::DeleteFromEnd() {
   Node* Hold = this->m_Head;
   for (int i = 2; i < this->m_Size; ++i) {
      Hold = Hold->GetNext();
   }

   delete Hold->GetNext();
   Hold->SetNext(NULL);
   --(this->m_Size);
}
////////////////////////////////////////////////////////////////////////////////////////////////
void Singly::DeleteFromCurrent() {
   if (this->m_Current == this->m_Head) {
      this->DeleteFromStart();
      return;
   }

   if (this->IsCurrentAtLast) {
      this->DeleteFromEnd();
      return;
   }

   Node* Hold = this->m_Current->GetNext();
   this->m_Current->SetNext(Hold->GetNext());
   delete Hold;
   --(this->m_Size);
}
////////////////////////////////////////////////////////////////////////////////////////////////
void Singly::DeleteFromPosition(const int& Position) {
   if (Position < 0 || Position > this->m_Size) {
      std::cout << "Invalid Position!" << std::endl;
      return;
   }

   if (Position == 0) {
      this->DeleteFromStart();
      return;
   }

   if (IsCurrentAtLast) {
      this->DeleteFromEnd();
      return;
   }

   Node* Hold = this->m_Head;
   for (int i = 2; i < Position; i++) {
      Hold = Hold->GetNext();
   }

   Node* K = Hold->GetNext();
   Hold->SetNext(K->GetNext());
   delete K;
   --(this->m_Size);
}
////////////////////////////////////////////////////////////////////////////////////////////////
Node* Singly::GetFromStart() {
   return this->m_Head;
}
////////////////////////////////////////////////////////////////////////////////////////////////
Node* Singly::GetFromEnd() {
   Node* Hold = this->m_Current;
   this->SetCurrentAtEnd();
   Node* Temp = this->m_Current;
   this->m_Current = Hold;
   return Temp;
}
////////////////////////////////////////////////////////////////////////////////////////////////
Node* Singly::GetFromCurrent() {
   return this->m_Current;
}
////////////////////////////////////////////////////////////////////////////////////////////////
Node* Singly::GetFromPosition(const int& Position) {
   if (Position < 0 || Position > this->m_Size) {
      std::cout << "Invalid Position!" << std::endl;
      return NULL;
   }

   if (Position == 0) {
      return this->GetFromStart();
   }

   if (IsCurrentAtLast) {
      return this->GetFromEnd();
   }

   Node* Hold = this->m_Head;
   for (int i = 1; i < Position; i++) {
      Hold = Hold->GetNext();
   }
   return Hold->GetNext();
}
////////////////////////////////////////////////////////////////////////////////////////////////
void Singly::SetCurrentAtStart() {
   this->m_Current = this->m_Head;
}
////////////////////////////////////////////////////////////////////////////////////////////////
void Singly::SetCurrentAtEnd() {
   Node* Hold = this->m_Head;
   while (Hold->GetNext() != NULL) {
      Hold = Hold->GetNext();
   }
   this->m_Current = Hold;
}
////////////////////////////////////////////////////////////////////////////////////////////////
void Singly::Sort(bool Ascending = true) {
   Node* Hold = this->m_Head;
   while (Hold != NULL) {
      Node* Suppose = Hold;
      Node* NextSupposed = Hold->GetNext();

      while (NextSupposed != NULL) {
         if (Ascending ?
            Suppose->GetData() > NextSupposed->GetData() :
            Suppose->GetData() < NextSupposed->GetData()) {
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
////////////////////////////////////////////////////////////////////////////////////////////////
bool Singly::Search(const int& Value) {
   Node* Hold = this->m_Head;
   while (Hold != NULL) {
      if (Hold->GetData() == Value) {
         return true;
      }
      Hold = Hold->GetNext();
   }
   return false;
}
////////////////////////////////////////////////////////////////////////////////////////////////
bool Singly::IsEmpty() const {
   return this->m_Head == NULL;
}
////////////////////////////////////////////////////////////////////////////////////////////////
int Singly::Size() const {
   return this->m_Size;
}
////////////////////////////////////////////////////////////////////////////////////////////////
void Singly::Display() const {
   Node* Hold = this->m_Head;
   while (Hold != NULL) {
      std::cout << "Data:\t" << Hold->GetData() << std::endl;
      Hold = Hold->GetNext();
   }
}
////////////////////////////////////////////////////////////////////////////////////////////////
int main() {
   Singly List;
   List.Display();
   List.InsertAtPosition(11, 0);
   List.InsertAtPosition(12, 1);
   List.InsertAtCurrent(13);
   List.InsertAtCurrent(14);
   List.InsertAtStart(10);
   List.InsertAtEnd(15);
   List.InsertAtCurrent(16);
   List.InsertAtPosition(55, 0);
   List.InsertAtPosition(66, 8);
   List.SetCurrentAtStart();
   List.InsertAtCurrent(77);
   List.SetCurrentAtEnd();
   List.InsertAtCurrent(88);
   List.DeleteFromEnd();
   List.DeleteFromStart();
   List.SetCurrentAtEnd();
   List.DeleteFromCurrent();
   List.InsertAtPosition(97, 2);
   List.DeleteFromPosition(1);

   List.Sort();
   List.Display();

   std::cout << std::endl
      << "At Start:\t\t" << List.GetFromStart()->GetData() << std::endl
      << "At End:\t\t\t" << List.GetFromEnd()->GetData() << std::endl;

   List.SetCurrentAtStart();

   std::cout << "At Current:\t\t" << List.GetFromCurrent()->GetData() << std::endl
      << "At Position 02:\t\t" << List.GetFromPosition(2)->GetData() << std::endl
      << std::endl;

   for (int i = 0; i < List.Size(); ++i) {
      std::cout << "@index[" << i << "]\t" << List.GetFromPosition(i)->GetData() << std::endl;
   }

   system("PAUSE");
   return EXIT_SUCCESS;
}