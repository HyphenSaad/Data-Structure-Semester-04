// DSA-LAB-QUIZ-03
// STUDNET NAME: Saad Mansoor
// SAP-ID:       70075954
// COURSE:       Data Structures & Algorithms
// DATED:        May 30, 2021 - Sunday
// BSCS-4/C1 - Department of Computer Science & Information Technology
// University of Lahore, Gujrat Campus

#include <iostream>
#include "Stack.cpp"

std::string DecimalToHexaDecimal(const unsigned int& Number) {
   int DecimalNumber = Number;

   Saadin::Stack<int> Stack;

   while (DecimalNumber != 0) {
      Stack.Push(DecimalNumber % 16);
      DecimalNumber /= 16;
   }

   std::string Hexadecimal{};

   while (!Stack.IsEmpty()) {
      int Hold = Stack.Peek();
      if (Hold < 10) Hexadecimal += std::to_string(Hold);
      else Hexadecimal += char(55 + Hold);
      Stack.Pop();
   }

   return Hexadecimal;
}

int main() {
   const unsigned int Number = 70075954;
   std::cout << "Decimal Number:\t\t" << Number << std::endl
      << "Hexadecimal Number:\t" << DecimalToHexaDecimal(Number) << std::endl;

   system("PAUSE");
   return 0;
}