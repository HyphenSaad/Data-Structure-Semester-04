#ifndef SINGLY_FOR_STACK
#define SINGLY_FOR_STACK

#include "Node.cpp"

namespace Saadin {
   template <class T>
   class Singly {
   private:
      Saadin::Node<T>* m_Head;
      int m_Size;

   public:
      Singly();
      ~Singly();

      void InsertAtStart(const T&);
      void DeleteFromStart();
      void Clear();
      T Fetch() const;
   };
}

template <class T>
Saadin::Singly<T>::Singly() {
   this->m_Size = 0;
   this->m_Head = NULL;
}

template <class T>
Saadin::Singly<T>::~Singly() {
   this->Clear();
}

template <class T>
void Saadin::Singly<T>::InsertAtStart(const T& Data) {
   this->m_Head = new Node<T>(Data, this->m_Head);
   ++(this->m_Size);
}

template <class T>
void Saadin::Singly<T>::DeleteFromStart() {
   Node<T>* Hold = this->m_Head;
   this->m_Head = Hold->GetNext();
   delete Hold;
   --(this->m_Size);
}

template <class T>
void Saadin::Singly<T>::Clear() {
   Saadin::Node<T>* Hold = this->m_Head;
   while (Hold != NULL) {
      Saadin::Node<T>* Temp = Hold;
      Hold = Hold->GetNext();
      delete Temp;
   }
}

template <class T>
T Saadin::Singly<T>::Fetch() const {
   return this->m_Head->GetData();
}

#endif