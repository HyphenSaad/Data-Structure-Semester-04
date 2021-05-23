// DSA-LAB-ASSIGNMENT-05
// STUDNET NAME: Saad Mansoor
// SAP-ID:       70075954
// COURSE:       Data Structures & Algorithms
// DATED:        May 23, 2021 - Sunday
// BSCS-4/C1 - Department of Computer Science & Information Technology
// University of Lahore, Gujrat Campus

#include <iostream>
#include "Infix.cpp"
#include "Prefix.cpp"
#include "Postfix.cpp"
#define SPACE std::cout << std::endl

int main() {
   std::string _Infix = "A+B*C/(E-F)";
   Saadin::Infix InfixExpression(_Infix);
   std::cout << "INFIX EXPRESSION:\t" << _Infix << std::endl
      << " > Postfix:\t" << InfixExpression.ToPostfix() << std::endl
      << " > Prefix:\t" << InfixExpression.ToPrefix() << std::endl;

   SPACE;
   std::string _Prefix = "*-A/BC-/AKL";
   Saadin::Prefix PrefixExpression(_Prefix);
   std::cout << "PREFIX EXPRESSION:\t" << _Prefix << std::endl
      << " > Infix:\t" << PrefixExpression.ToInfix() << std::endl
      << " > Postfix:\t" << PrefixExpression.ToPostfix() << std::endl;

   SPACE;
   std::string _Postfix = "ABC/-AK/L-*";
   Saadin::Postfix PostfixExpression(_Postfix);
   std::cout << "POSTFIX EXPRESSION:\t" << _Postfix << std::endl
      << " > Infix:\t" << PostfixExpression.ToInfix() << std::endl
      << " > Prefix:\t" << PostfixExpression.ToPrefix() << std::endl;

   system("PAUSE");
   return 0;
}