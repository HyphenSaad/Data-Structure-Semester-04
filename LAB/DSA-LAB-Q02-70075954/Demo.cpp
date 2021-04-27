////////////////////////////////////////////////////////////////////////////////////////////////
// DSA-LAB-QUIZ-02
// STUDNET NAME:   Saad Mansoor
// SAP-ID:         70075954
// COURSE:         Data Structures & Algorithms
// DATED:          April 07, 2021 - Wednesday
// BSCS-4/C1 - Department of Computer Science & Information Technology
// University of Lahore, Gujrat Campus
////////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include "Doubly.cpp"

int main() {
   Saadin::Doubly List;
   List.InsertAtStart({ "Saad Mansoor", 69 });
   List.InsertAtStart({ "Ali Ahsan", 33 });
   List.InsertAtLast({ "Umar Asghar", 77 });
   List.InsertAtLast({ "Alpha Bravo Charlie", 87 });
   List.Display();

   std::cout << "AFTER DELETING POSTION 2" << std::endl;
   List.DeleteFromPosition(2);
   List.Display();

   std::cout << "AFTER DELETING FROM LAST" << std::endl;
   List.DeleteFromLast();
   List.Display();

   std::cout << "LET'S SEARCH RECORD FOR ID 69" << std::endl;
   List.SearchByID(69);

   std::cout << "SIZE OF DOUBLY LIST:\t" << List.GetSize() << std::endl;

   system("PAUSE");
   return EXIT_SUCCESS;
}