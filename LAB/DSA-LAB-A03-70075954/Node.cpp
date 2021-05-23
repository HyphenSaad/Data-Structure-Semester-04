#ifndef NODE_FOR_SINGLY
#define NODE_FOR_SINGLY

namespace Saadin {
   template <class T>
   class Node {
   private:
      T m_Data;
      Saadin::Node<T>* m_Next;

   public:
      Node();
      Node(const T&);
      Node(const T&, Saadin::Node<T>*);
      void SetData(const T&);
      void SetNext(Saadin::Node<T>*);
      T GetData() const;
      Saadin::Node<T>* GetNext() const;
   };
}

template <class T>
Saadin::Node<T>::Node() {
   this->m_Data = 0;
   this->m_Next = NULL;
}

template <class T>
Saadin::Node<T>::Node(const T& Data) {
   this->m_Data = Data;
   this->m_Next = NULL;
}

template <class T>
Saadin::Node<T>::Node(const T& Data, Saadin::Node<T>* Next) {
   this->m_Data = Data;
   this->m_Next = Next;
}

template <class T>
void Saadin::Node<T>::SetData(const T& Data) {
   this->m_Data = Data;
}

template <class T>
void Saadin::Node<T>::SetNext(Saadin::Node<T>* Next) {
   this->m_Next = Next;
}

template <class T>
T Saadin::Node<T>::GetData() const {
   return this->m_Data;
}

template <class T>
Saadin::Node<T>* Saadin::Node<T>::GetNext() const {
   return this->m_Next;
}

#endif