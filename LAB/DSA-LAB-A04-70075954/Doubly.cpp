#ifndef SAADIN_DOUBLY_LIST
#define SAADIN_DOUBLY_LIST

#include "Node.cpp"

namespace Saadin {
   template <class _T_>
   class Doubly {
   private:
      Saadin::Node<_T_>* m_Head;
      unsigned short m_Size;

   public:
      Doubly();
      ~Doubly();

      void InsertAtStart(const _T_&);
      void InsertAtEnd(const _T_&);
      void InsertAtIndex(const _T_&, const unsigned short&);

      void DeleteFromStart();
      void DeleteFromEnd();
      void DeleteFromIndex(const unsigned short&);

      _T_ GetFromStart() const;
      _T_ GetFromEnd() const;
      _T_ GetFromIndex(const unsigned short&) const;

      unsigned short GetSize();
      bool IsEmpty();
      void Display();
   };
}

template <class _T_>
Saadin::Doubly<_T_>::Doubly() {
   this->m_Head = NULL;
   this->m_Size = 0;
}

template <class _T_>
Saadin::Doubly<_T_>::~Doubly() {
   Saadin::Node<_T_>* Hold = this->m_Head;
   for (short i = 0; i < this->m_Size; ++i) {
      Saadin::Node<_T_>* Temp = Hold;
      Hold = Hold->GetNext();
      delete Temp;
   }
}

template <class _T_>
void Saadin::Doubly<_T_>::InsertAtStart(const _T_& Data) {
   Saadin::Node<_T_>* Packet = new Node<_T_>(Data, this->m_Head, NULL);

   if (this->m_Head != NULL) this->m_Head->SetPrevious(Packet);
   this->m_Head = Packet;

   ++(this->m_Size);
}

template <class _T_>
void Saadin::Doubly<_T_>::InsertAtEnd(const _T_& Data) {
   if (this->m_Head == NULL) {
      this->InsertAtStart(Data); return;
   }

   Saadin::Node<_T_>* Hold = this->m_Head;
   while (Hold->GetNext() != NULL) Hold = Hold->GetNext();


   Saadin::Node<_T_>* Packet = new Node<_T_>(Data);
   Hold->SetNext(Packet);
   Packet->SetPrevious(Hold);
   ++(this->m_Size);
}

template <class _T_>
void Saadin::Doubly<_T_>::InsertAtIndex(const _T_& Data, const unsigned short& Position) {
   if (Position > (this->m_Size + 1)) return;
   if (Position == 1) {
      this->InsertAtStart(Data); return;
   }

   Saadin::Node<_T_>* Hold = this->m_Head;
   for (int i = 0; i < Position - 2; ++i) {
      if (Hold != NULL) Hold = Hold->GetNext();
   }

   if (Hold == NULL) return;
   Saadin::Node<_T_>* Packet = new Node<_T_>(Data, Hold->GetNext(), Hold);
   Hold->SetNext(Packet);
   if (Packet->GetNext() != NULL) Packet->GetNext()->SetPrevious(Packet);

   ++(this->m_Size);
}

template <class _T_>
void Saadin::Doubly<_T_>::DeleteFromStart() {
   if (this->m_Head == NULL) return;

   Saadin::Node<_T_>* Hold = this->m_Head;
   this->m_Head = this->m_Head->GetNext();
   delete Hold;
   if (this->m_Head != NULL) this->m_Head->SetPrevious(NULL);

   --(this->m_Size);
}

template <class _T_>
void Saadin::Doubly<_T_>::DeleteFromEnd() {
   if (this->m_Head == NULL) return;
   if (this->m_Head->GetNext() == NULL) this->m_Head = NULL;

   Saadin::Node<_T_>* Hold = this->m_Head;
   for (int i = 2; i < this->m_Size; ++i) {
      Hold = Hold->GetNext();
   }

   Saadin::Node<_T_>* Temp = Hold->GetNext();
   delete Temp;
   Hold->SetNext(NULL);

   --(this->m_Size);
}

template <class _T_>
void Saadin::Doubly<_T_>::DeleteFromIndex(const unsigned short& Position) {
   if (Position > (this->m_Size + 1) || this->m_Head == NULL) return;
   if (Position == 1) {
      this->DeleteFromStart(); return;
   }


   Saadin::Node<_T_>* Hold = this->m_Head;
   for (int i = 0; i < Position - 2; ++i) {
      if (Hold != NULL) Hold = Hold->GetNext();
   }

   if (Hold == NULL && Hold->GetNext() == NULL) return;
   Saadin::Node<_T_>* Temp = Hold->GetNext();
   Hold->SetNext(Hold->GetNext()->GetNext());
   if (Hold->GetNext()->GetNext() != NULL) Hold->GetNext()->GetNext()->SetPrevious(Hold->GetNext());
   delete Temp;

   --(this->m_Size);
}

template <class _T_>
_T_ Saadin::Doubly<_T_>::GetFromStart() const {
   if (this->m_Head == NULL) return 0;
   return this->m_Head->GetData();
}

template <class _T_>
_T_ Saadin::Doubly<_T_>::GetFromEnd() const {
   if (this->m_Head == NULL) return 0;

   Saadin::Node<_T_>* Hold = this->m_Head;
   while (Hold != NULL) Hold = Hold->GetNext();
   return Hold->GetData();
}

template <class _T_>
_T_ Saadin::Doubly<_T_>::GetFromIndex(const unsigned short& Position) const {
   if (Position > (this->m_Size + 1) || this->m_Head == NULL) return 0;
   if (Position == 1) return this->GetFromStart();

   Saadin::Node<_T_>* Hold = this->m_Head;
   for (int i = 0;i < Position - 1; ++i) {
      if (Hold != NULL) Hold = Hold->GetNext();
   }

   return Hold->GetData();
}

template <class _T_>
unsigned short Saadin::Doubly<_T_>::GetSize() {
   return this->m_Size;
}

template <class _T_>
bool Saadin::Doubly<_T_>::IsEmpty() {
   return this->m_Size == 0;
}

template <class _T_>
void Saadin::Doubly<_T_>::Display() {
   Saadin::Node<_T_>* Hold = this->m_Head;
   while (Hold != NULL) {
      std::cout << Hold->GetData() << std::endl;
      Hold = Hold->GetNext();
   }
}

#endif