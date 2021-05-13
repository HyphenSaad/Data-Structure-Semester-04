#include <iostream>
////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
class Node {
private:
   T m_Data;
   Node<T>* m_Next;
public:
   Node(const T&);
   Node(const T&, Node<T>*);
   void SetData(const T&);
   void SetNext(Node<T>*);
   T GetData() const;
   Node<T>* GetNext() const;
};
template <class T> Node<T>::Node(const T& Data) :m_Data(Data), m_Next(NULL) {}
template <class T> Node<T>::Node(const T& Data, Node<T>* Next) : m_Data(Data), m_Next(Next) {}
template <class T> void Node<T>::SetData(const T& Data) { this->m_Data = Data; }
template <class T> void Node<T>::SetNext(Node<T>* Next) { this->m_Next = Next; }
template <class T> T Node<T>::GetData() const { return this->m_Data; }
template <class T> Node<T>* Node<T>::GetNext() const { return this->m_Next; }
////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
class Stack {
private:
   Node<T>* m_Head;
   unsigned short m_Height;
public:
   Stack();
   void Push(const T&);
   T Pop();
   T Peek() const;
   bool IsEmpty() const;
   void Display();
};

template <class T> Stack<T>::Stack() : m_Head(NULL), m_Height(0) {}

template <class T> void Stack<T>::Push(const T& Data) {
   this->m_Head = new Node<T>(Data, this->m_Head);
   ++(this->m_Height);
}

template <class T> T Stack<T>::Pop() {
   if (this->m_Height == 0) return -1;
   Node<T>* Hold = this->m_Head->GetNext();
   T Data = this->m_Head->GetData();
   delete this->m_Head;
   this->m_Head = Hold;
   --(this->m_Height);
   return Data;
}

template <class T> T Stack<T>::Peek() const { return this->m_Head->GetData(); }
template <class T> bool Stack<T>::IsEmpty() const { return this->m_Height == 0; }

template<> void Stack<int>::Display() {
   std::cout << std::endl;
   const int X = 20;                                                   // STACK-DISPLAY-WIDTH
   if (this->m_Height == 0) {                                          // IF STACK IS EMPTY
      std::cout << "  " << char(179);                                  // LEFT-LINE
      int w = (X - 7);                                                 // SPACE WIDTH
      for (int j = 0; j < w / 2; ++j) std::cout << " ";                // SPACE ON LEFT-SIDE
      std::cout << "EMPTY";                                            // MESSAGE
      for (int j = 0; j < w / 2; ++j) std::cout << " ";                // SPACE ON RIGHT-SIDE
      if (w % 2 != 0) std::cout << " ";                                // SPACE ADJUSTMENT
      std::cout << char(179) << std::endl;                             // RIGHT-LINE
   }

   Node<int>* Hold = this->m_Head;                                     // BACKUP xD
   for (int i = 0, w = 0; i < this->m_Height;++i, w -= w) {            // TO PRINT STACK
      int Data = Hold->GetData(); while (Data != 0) (Data /= 10, ++w); // DIGIT COUNT
      w = (X - w - 2);                                                 // SPACE WIDTH
      std::cout << "  " << char(179);                                  // LEFT-LINE
      for (int j = 0; j < w / 2; ++j) std::cout << " ";                // SPACE ON LEFT-SIDE
      std::cout << Hold->GetData();                                    // ACTUAL DATA
      for (int j = 0; j < w / 2; ++j) std::cout << " ";                // SPACE ON RIGHT-SIDE
      if (w % 2 != 0) std::cout << " ";                                // SPACE ADJUSTMENT
      std::cout << char(179) << std::endl;                             // RIGHT-LINE
      if (i != this->m_Height - 1) {                                   // IF NOT LAST ELEMENT
         std::cout << "  " << char(195);                               // SPLIT-LEFT-SYMBOL
         for (int j = 2; j < X; ++j) std::cout << char(196);           // SPLIT-LINE
         std::cout << char(180) << std::endl;                          // SPLIT-RIGHT-SYMBOL
      }
      Hold = Hold->GetNext();                                          // FETCH NEXT NODE
   }

   std::cout << "  " << char(192);                                     // BOTTOM-LEFT-SYMBOL
   for (int j = 2; j < X; ++j) std::cout << char(196);                 // BOTTOM-LINE
   std::cout << char(217) << std::endl;                                // BOTTOM-RIGHT-SYMBOL
   std::cout << "  STACK REPRESENTATION" << std::endl;                 // FOOTER
   std::cout << std::endl;
}
////////////////////////////////////////////////////////////////////////////////////////////////
int main() {
   Stack<int> Data;
   Data.Push(10);
   Data.Push(20);
   Data.Push(50);
   Data.Push(30);
   Data.Push(40);
   std::cout << "PUSHED 10, 20, 50, 30, 40" << std::endl;
   Data.Display();

   Data.Pop();
   Data.Pop();
   Data.Pop();
   std::cout << "CALLED POP() THREE TIMES" << std::endl;
   Data.Display();

   system("PAUSE");
   return 0;
}