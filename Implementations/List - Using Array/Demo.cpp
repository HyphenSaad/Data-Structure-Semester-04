#include <iostream>
#include "List.cpp"

int main() {
   Hyphen::List A;
   A.CreateList();
   A.ShowLogs(true);
   A.Insert(12, 0);
   A.Insert(34, 0);
   A.Insert(56, 0);
   A.Insert(78, 0);
   A.Display();

   Hyphen::List B;
   B.CreateList();
   B.ShowLogs(true);
   B.Copy(&A);
   B.Display();

   std::cout << "25 is " << (B.Find(25) ? " present!" : " absent!") << std::endl;

   for (int i = 0; i < B.Length(); ++i) {
      B.Update((i + i) + 5, i);
   }

   for (int i = 0; i < B.Length(); ++i) {
      std::cout << B.Get(i) << "\t";
   }
   std::cout << std::endl;

   system("PAUSE");
   return EXIT_SUCCESS;
}