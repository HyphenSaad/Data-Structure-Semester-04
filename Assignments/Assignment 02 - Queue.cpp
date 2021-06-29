// DSA-ASSIGNMENT-02
// STUDNET NAME: Saad Mansoor
// SAP-ID:       70075954
// COURSE:       Data Structures & Algorithms
// DATED:        May 29, 2021 - Saturday
// BSCS-4/C1 - Department of Computer Science & Information Technology
// University of Lahore, Gujrat Campus

#include <iostream>

class CircularQueue {
private:
   char v[12]{ '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', 'N' };
   int F{ 11 }, R{ 11 };
   unsigned short m_Size{ 12 };
   bool is_full() const;
   void format_display(const int&) const;

public:
   void put_to_queue(const char&);
   void display_queue() const;
};


void CircularQueue::put_to_queue(const char& Data) {
   // here, i used a guard clause that will pop the function from call stack 
   // if, the queue is full
   if (this->is_full()) {
      std::cout << "Queue_Full" << std::endl;
      return;
   }

   this->R = (this->R + 1) % this->m_Size;
   this->v[this->R] = Data;
}

void CircularQueue::display_queue() const {
   std::cout << "FRONT:\t" << this->F << std::endl
      << "REAR:\t" << this->R << std::endl
      << "DATA:\t" << std::endl;

   int i{ this->F };
   while (i != this->R) {
      this->format_display(i);
      i = (i + 1) % this->m_Size;
   }
   this->format_display(i);
}

bool CircularQueue::is_full() const {
   return (this->F == (this->R + 1)) || (this->F == 0 && this->R == (this->m_Size - 1));
}

void CircularQueue::format_display(const int& index) const {
   std::cout << "  @Position[" << index << "]:" << (index < 10 ? "  " : " ") << this->v[index] << std::endl;
}

int main() {
   CircularQueue Queue;

   Queue.put_to_queue('A');
   Queue.put_to_queue('T');
   Queue.put_to_queue('I');
   Queue.put_to_queue('O');
   Queue.put_to_queue('N');

   Queue.display_queue();

   system("PAUSE");
   return 0;
}