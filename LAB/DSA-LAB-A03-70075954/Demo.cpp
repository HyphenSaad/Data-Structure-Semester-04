// DSA-LAB-ASSIGNMENT-03
// STUDNET NAME: Saad Mansoor
// SAP-ID:       70075954
// COURSE:       Data Structures & Algorithms
// DATED:        May 23, 2021 - Sunday
// BSCS-4/C1 - Department of Computer Science & Information Technology
// University of Lahore, Gujrat Campus

#include <iostream>
#include "Stack.cpp"

int main() {
   Saadin::Stack<int> Numbers;
   Numbers.Push(10);
   Numbers.Push(20);
   std::cout << Numbers.Peek() << std::endl;
   Numbers.Pop();
   std::cout << Numbers.Peek() << std::endl;
   Numbers.Pop();

   std::cout << "Is Stack Empty?\t" << (Numbers.IsEmpty() ? "Yes" : "No") << std::endl;

   system("PAUSE");
   return 0;
}