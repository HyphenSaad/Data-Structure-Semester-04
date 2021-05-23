#ifndef INFIX_SAADIN
#define INFIX_SAADIN

#include <string>
#include <algorithm>
#include "Stack.cpp"

using namespace std;
namespace Saadin {
   class Infix {
   private:
      std::string m_Expression;
      int OperatorPrecedence(const char&);
      std::string _ToPostfix(const std::string&);

   public:
      Infix(const std::string&);
      std::string ToPostfix();
      std::string ToPrefix();
   };
}

int Saadin::Infix::OperatorPrecedence(const char& Operator) {
   if (Operator == '^') return 3;
   else if (Operator == '*' || Operator == '/') return 2;
   else if (Operator == '+' || Operator == '-') return 1;
   else return -1;
}

Saadin::Infix::Infix(const std::string& Expression) {
   this->m_Expression = Expression;
}

std::string Saadin::Infix::_ToPostfix(const std::string& Expression) {
   Saadin::Stack<char> Stack;
   std::string Output;

   for (int i = 0; i < Expression.length(); ++i) {
      char Character = Expression[i];

      if ((Character > 96 && Character < 123) || (Character > 64 && Character < 91) || (Character > 47 && Character < 58)) Output += Character;
      else if (Character == 40) Stack.Push(Character);
      else if (Character == 41) {
         while (!Stack.IsEmpty() && Stack.Peek() != 40) {
            Output += Stack.Peek(); Stack.Pop();
         }
         Stack.Pop();
      }
      else {
         while (!Stack.IsEmpty() && (this->OperatorPrecedence(Character) <= this->OperatorPrecedence(Stack.Peek()))) {
            Output += Stack.Peek(); Stack.Pop();
         }
         Stack.Push(Character);
      }
   }

   while (!Stack.IsEmpty()) {
      Output += Stack.Peek(); Stack.Pop();
   }

   return Output;
}

std::string Saadin::Infix::ToPostfix() {
   return this->_ToPostfix(this->m_Expression);
}

std::string Saadin::Infix::ToPrefix() {
   std::string _EXP = this->m_Expression;
   std::reverse(_EXP.begin(), _EXP.end());

   for (int i = 0; i < _EXP.length(); ++i) {
      if (_EXP[i] == '(') {
         _EXP[i] = ')'; ++i;
      }
      else if (_EXP[i] == ')') {
         _EXP[i] = '('; ++i;
      }
   }

   std::string Prefix = this->_ToPostfix(_EXP);
   std::reverse(Prefix.begin(), Prefix.end());
   return Prefix;
}

#endif