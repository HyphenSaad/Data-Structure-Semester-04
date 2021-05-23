#ifndef SAADIN_NODE
#define SAADIN_NODE


namespace Saadin {
   template <class _T_>
   class Node {
   private:
      _T_ m_Data;
      Saadin::Node<_T_>* m_Next;
      Saadin::Node<_T_>* m_Previous;

   public:
      Node();
      Node(const _T_&);
      Node(const _T_&, Saadin::Node<_T_>*);
      Node(const _T_&, Saadin::Node<_T_>*, Saadin::Node<_T_>*);

      void SetData(const _T_&);
      void SetNext(Saadin::Node<_T_>*);
      void SetPrevious(Saadin::Node<_T_>*);

      _T_ GetData() const;
      Saadin::Node<_T_>* GetNext() const;
      Saadin::Node<_T_>* GetPrevious() const;
   };
}

template <class _T_>
Saadin::Node<_T_>::Node() {
   this->m_Data = 0;
   this->m_Next = NULL;
   this->m_Previous = NULL;
}

template <class _T_>
Saadin::Node<_T_>::Node(const _T_& Data) {
   this->m_Data = Data;
   this->m_Next = NULL;
   this->m_Previous = NULL;
}

template <class _T_>
Saadin::Node<_T_>::Node(const _T_& Data, Saadin::Node<_T_>* Next) {
   this->m_Data = Data;
   this->m_Next = Next;
   this->m_Previous = NULL;
}

template <class _T_>
Saadin::Node<_T_>::Node(const _T_& Data, Saadin::Node<_T_>* Next, Saadin::Node<_T_>* Previous) {
   this->m_Data = Data;
   this->m_Next = Next;
   this->m_Previous = Previous;
}

template <class _T_>
void Saadin::Node<_T_>::SetData(const _T_& Data) {
   this->m_Data = Data;
}

template <class _T_>
void Saadin::Node<_T_>::SetNext(Saadin::Node<_T_>* Next) {
   this->m_Next = Next;
}

template <class _T_>
void Saadin::Node<_T_>::SetPrevious(Saadin::Node<_T_>* Previous) {
   this->m_Previous = Previous;
}

template <class _T_>
_T_ Saadin::Node<_T_>::GetData() const {
   return this->m_Data;
}

template <class _T_>
Saadin::Node<_T_>* Saadin::Node<_T_>::GetNext() const {
   return this->m_Next;
}

template <class _T_>
Saadin::Node<_T_>* Saadin::Node<_T_>::GetPrevious() const {
   return this->m_Previous;
}

#endif