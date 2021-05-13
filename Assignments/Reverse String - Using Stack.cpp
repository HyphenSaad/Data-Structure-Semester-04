#include <iostream>
#include <string>
////////////////////////////////////////////////////////////////////////////////////////////////
template <typename T>
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
template <typename T> Node<T>::Node(const T& Data) :m_Data(Data), m_Next(NULL) {}
template <typename T> Node<T>::Node(const T& Data, Node<T>* Next) : m_Data(Data), m_Next(Next) {}
template <typename T> void Node<T>::SetData(const T& Data) { this->m_Data = Data; }
template <typename T> void Node<T>::SetNext(Node<T>* Next) { this->m_Next = Next; }
template <typename T> T Node<T>::GetData() const { return this->m_Data; }
template <typename T> Node<T>* Node<T>::GetNext() const { return this->m_Next; }
////////////////////////////////////////////////////////////////////////////////////////////////
template <typename T>
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
};

template <typename T> Stack<T>::Stack() : m_Head(NULL), m_Height(0) {}

template <typename T> void Stack<T>::Push(const T& Data) {
   this->m_Head = new Node<T>(Data, this->m_Head);
   ++(this->m_Height);
}

template <typename T> T Stack<T>::Pop() {
   if (this->m_Height == 0) return -1;
   T Data = this->m_Head->GetData();
   Node<T>* Hold = this->m_Head->GetNext();
   delete this->m_Head;
   this->m_Head = Hold;
   --(this->m_Height);
   return Data;
}

template <typename T> T Stack<T>::Peek() const { return this->m_Head->GetData(); }
template <typename T> bool Stack<T>::IsEmpty() const { return this->m_Height == 0; }
////////////////////////////////////////////////////////////////////////////////////////////////
int main() {
   std::string data = "PROGRAM";
   int index = 0;
   Stack<char> s;
   while (data[index] != '\0') {
      s.Push(data[index]);
      index = index + 1;
   }
   index = 0;
   while (data[index] != '\0') {
      data[index] = s.Pop();
      index = index + 1;
   }
   std::cout << data << std::endl;
   system("PAUSE");
   return 0;
}