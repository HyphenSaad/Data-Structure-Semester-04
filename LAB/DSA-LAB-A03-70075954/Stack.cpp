#ifndef SAADIN_STACK
#define SAADIN_STACK

#include "Singly.cpp"

namespace Saadin {
   template <class T>
   class Stack {
   private:
      Singly<T>* m_Stack;
      int m_Height;

   public:
      Stack();
      ~Stack();

      void Push(const T&);
      void Pop();
      T Peek() const;
      bool IsEmpty() const;
   };
}

template <class T>
Saadin::Stack<T>::Stack() {
   this->m_Stack = new Singly<T>();
   this->m_Height = 0;
}

template <class T>
Saadin::Stack<T>::~Stack() {
   this->m_Stack->Clear();
   delete m_Stack;
}

template <class T>
void Saadin::Stack<T>::Push(const T& Data) {
   this->m_Stack->InsertAtStart(Data);
   ++(this->m_Height);
}

template <class T>
void Saadin::Stack<T>::Pop() {
   if (this->m_Height == 0) return;
   this->m_Stack->DeleteFromStart();
   --(this->m_Height);
}

template <class T>
T Saadin::Stack<T>::Peek() const {
   return this->m_Stack->Fetch();
}

template <class T>
bool Saadin::Stack<T>::IsEmpty() const {
   return this->m_Height == 0;
}

#endif