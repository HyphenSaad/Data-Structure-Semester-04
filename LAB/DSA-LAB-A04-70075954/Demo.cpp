// DSA-LAB-ASSIGNMENT-04
// STUDNET NAME: Saad Mansoor
// SAP-ID:       70075954
// COURSE:       Data Structures & Algorithms
// DATED:        May 23, 2021 - Sunday
// BSCS-4/C1 - Department of Computer Science & Information Technology
// University of Lahore, Gujrat Campus

#include <iostream>
#include "Doubly.cpp"
#define SPACE std::cout << std::endl

int main() {
   Saadin::Doubly<int> List;

   List.InsertAtStart(5);
   List.InsertAtStart(4);
   List.InsertAtStart(3);
   List.InsertAtStart(2);
   List.InsertAtStart(1);
   List.InsertAtIndex(6, 6);
   List.InsertAtEnd(8);
   List.InsertAtIndex(7, 7);
   List.Display();

   SPACE;
   List.DeleteFromStart();
   List.DeleteFromEnd();
   List.DeleteFromIndex(5);
   List.Display();

   SPACE;
   std::cout << "Is List Empty?\t" << (List.IsEmpty() ? "Yes" : "No") << std::endl;

   SPACE;
   for (int i = 1; i <= List.GetSize(); ++i) {
      std::cout << "@Position[" << i << "]:\t" << List.GetFromIndex(i) << std::endl;
   }

   system("PAUSE");
   return 0;
}