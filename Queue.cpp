#include <iostream>

template<class Type>
class Queue {
private:
   Type* m_Queue;
   short m_Front, m_Rare;
   int m_Space;

public:
   Queue(const int&);
   void Enqueue(const Type&);
   Type Dequeue();
   bool IsFull();
   void Display();
};

template<class Type>
Queue<Type>::Queue(const int& Size) {
   this->m_Queue = new Type[Size];
   this->m_Front = -1;
   this->m_Rare = -1;
   this->m_Space = Size;
}

template<class Type>
void Queue<Type>::Enqueue(const Type& Data) {
   if (this->IsFull()) {
      std::cout << "QUEUE IS FULL!" << std::endl; return;
   }

   if (this->m_Front == -1) ++(this->m_Front);

   ++(this->m_Rare);
   this->m_Queue[this->m_Rare] = Data;
}

template<class Type>
Type Queue<Type>::Dequeue() {

}

template<class Type>
bool Queue<Type>::IsFull() {
   return this->m_Rare == (this->m_Space - 1);
}

template<class Type>
void Queue<Type>::Display() {
   for (int i = front;)
}

int main() {

   system("PAUSE");
   return 0;
}