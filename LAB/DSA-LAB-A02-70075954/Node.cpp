#include <iostream>

namespace Saadin {
   class Node {
   private:
      int m_Data;
      Saadin::Node* m_Next;
   public:
      Node();
      Node(const int&);
      Node(const int&, Saadin::Node*);
      void SetData(const int&);
      void SetNext(Saadin::Node*);
      int GetData() const;
      Saadin::Node* GetNext() const;
   };
}

Saadin::Node::Node() {
   this->m_Data = 0;
   this->m_Next = NULL;
}

Saadin::Node::Node(const int& Data) {
   this->m_Data = Data;
   this->m_Next = NULL;
}

Saadin::Node::Node(const int& Data, Saadin::Node* Next) {
   this->m_Data = Data;
   this->m_Next = Next;
}

void Saadin::Node::SetData(const int& Data) {
   this->m_Data = Data;
}

void Saadin::Node::SetNext(Saadin::Node* Next) {
   this->m_Next = Next;
}

int Saadin::Node::GetData() const {
   return this->m_Data;
}

Saadin::Node* Saadin::Node::GetNext() const {
   return this->m_Next;
}