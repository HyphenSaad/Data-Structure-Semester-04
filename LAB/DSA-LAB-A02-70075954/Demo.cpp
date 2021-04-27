// DSA-LAB-ASSIGNMENT-02
// STUDNET NAME: Saad Mansoor
// SAP-ID:       70075954
// COURSE:       Data Structures & Algorithms
// DATED:        April 01, 2021 - Thursday
// BSCS-4/C1 - Department of Computer Science & Information Technology
// University of Lahore, Gujrat Campus

#include <iostream>
#include <conio.h>
#include "Singly.cpp"
#include "Menu.cpp"

#define SAADIN_ARROW ' ' << char(175) << ' '

int main() {
   int Option = 0, Input = 0, Position = 0;
   Saadin::Singly List;

   while (true) {
      system("CLS");
      Saadin::Menu();
      std::cout << SAADIN_ARROW << "Selection:\t";
      std::cin >> Option;

      if (Option < -1 || Option > 11) {
         std::cout << SAADIN_ARROW << "Invalid Selection! Press Any Key To Continue!";
         getch();
         continue;
      }

      switch (Option) {
      case 1:
         std::cout << SAADIN_ARROW << "Enter Data To Insert At Start Of List:\t";
         std::cin >> Input;
         List.InsertAtStart(Input);
         std::cout << SAADIN_ARROW << "Successfully, Inserted Data At Start!" << std::endl;
         std::cout << SAADIN_ARROW << "Press Any Key To Go Back To Main Menu!" << std::endl;
         getch();
         break;

      case 2:
         std::cout << SAADIN_ARROW << "Enter Data To Insert At Last Of List:\t";
         std::cin >> Input;
         List.InsertAtLast(Input);
         std::cout << SAADIN_ARROW << "Successfully, Inserted Data At Last!" << std::endl;
         std::cout << SAADIN_ARROW << "Press Any Key To Go Back To Main Menu!" << std::endl;
         getch();
         break;

      case 3:
         std::cout << SAADIN_ARROW << "Enter Postion Between [0-" << List.GetSize() << "]:\t";
         std::cin >> Position;

         if (Position < 0 || Position > List.GetSize() + 1) {
            std::cout << SAADIN_ARROW << "Invalid Position! Press Any Key To Continue!" << std::endl;
            getch();
            break;
         }

         std::cout << SAADIN_ARROW << "Enter Data To Insert At Postion " << Position << " in List:\t";
         std::cin >> Input;
         List.InsertAtPosition(Input, Position);
         std::cout << SAADIN_ARROW << "Successfully, Inserted Data At Position " << Position << "!" << std::endl;
         std::cout << SAADIN_ARROW << "Press Any Key To Go Back To Main Menu!" << std::endl;
         getch();
         break;

      case 4:
         List.DeleteFromStart();
         std::cout << SAADIN_ARROW << "Successfully, Deleted Data From Start!" << std::endl;
         std::cout << SAADIN_ARROW << "Press Any Key To Go Back To Main Menu!" << std::endl;
         getch();
         break;

      case 5:
         List.DeleteFromEnd();
         std::cout << SAADIN_ARROW << "Successfully, Deleted Data From Last!" << std::endl;
         std::cout << SAADIN_ARROW << "Press Any Key To Go Back To Main Menu!" << std::endl;
         getch();
         break;

      case 6:
         std::cout << SAADIN_ARROW << "Enter Postion Between [0-" << List.GetSize() - 1 << "]:\t";
         std::cin >> Position;

         if (Position < 0 || Position > List.GetSize() - 1) {
            std::cout << SAADIN_ARROW << "Invalid Position! Press Any Key To Continue!" << std::endl;
            getch();
            break;
         }

         List.DeleteFromPosition(Position);
         std::cout << SAADIN_ARROW << "Successfully, Deleted Data From Position " << Position << "!" << std::endl;
         std::cout << SAADIN_ARROW << "Press Any Key To Go Back To Main Menu!" << std::endl;
         getch();
         break;

      case 7:
         std::cout << SAADIN_ARROW << "Enter Data To Search From List:\t";
         std::cin >> Input;

         std::cout << SAADIN_ARROW << (List.Search(Input) ? "Successfully, Found Data!" : "Unfortunately, Data Not Found!") << std::endl;
         std::cout << SAADIN_ARROW << "Press Any Key To Go Back To Main Menu!" << std::endl;
         getch();
         break;

      case 8:
         std::cout << SAADIN_ARROW << "1: Asscending" << std::endl;
         std::cout << SAADIN_ARROW << "2: Descending" << std::endl;
         std::cout << SAADIN_ARROW << "Selection:\t";
         std::cin >> Input;

         if (Input == 1) {
            List.Sort(true);
         }
         else if (Input == 2) {
            List.Sort(false);
         }
         else {
            std::cout << SAADIN_ARROW << "Invalid Selection! Press Any Key To Continue!" << std::endl;
            getch();
            break;
         }

         std::cout << SAADIN_ARROW << "Successfully, Sorted Data In " << (Input == 1 ? "Asscending" : "Descending") << " Order!" << std::endl;
         std::cout << SAADIN_ARROW << "Press Any Key To Go Back To Main Menu!" << std::endl;
         getch();
         break;

      case 9:
         std::cout << SAADIN_ARROW << "Size:\t" << List.GetSize() << std::endl;
         std::cout << SAADIN_ARROW << "Press Any Key To Go Back To Main Menu!" << std::endl;
         getch();
         break;

      case 10:
         std::cout << SAADIN_ARROW << "Empty:\t" << (List.IsEmpty() ? "True" : "False") << std::endl;
         std::cout << SAADIN_ARROW << "Press Any Key To Go Back To Main Menu!" << std::endl;
         getch();
         break;

      case 11:
         List.Display();
         std::cout << SAADIN_ARROW << "Press Any Key To Go Back To Main Menu!" << std::endl;
         getch();
         break;

      case 0:
         exit(0);
         break;

      default:
         std::cout << "Unknown Operation!" << std::endl;
      }
   }

   system("PAUSE");
   return EXIT_SUCCESS;
}