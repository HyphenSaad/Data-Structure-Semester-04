#ifndef POSTFIX_SAADIN
#define POSTFIX_SAADIN

#include <string>
#include "Stack.cpp"

namespace Saadin {
   class Postfix {
      std::string m_Expression;
   public:
      Postfix(const std::string&);
      std::string ToInfix();
      std::string ToPrefix();
   };
}

Saadin::Postfix::Postfix(const std::string& Expression) {
   this->m_Expression = Expression;
}

std::string Saadin::Postfix::ToInfix() {
   Saadin::Stack<std::string> Stack;

   for (int i = 0; this->m_Expression[i] != '\0';++i) {
      char Character = this->m_Expression[i];
      if ((Character > 96 && Character < 123) || (Character > 64 && Character < 91)) {
         Stack.Push(std::string(1, Character));
      }
      else {
         std::string Left = Stack.Peek(); Stack.Pop();
         std::string Right = Stack.Peek(); Stack.Pop();
         Stack.Push("(" + Right + Character + Left + ")");
      }
   }

   return Stack.Peek();
}

std::string Saadin::Postfix::ToPrefix() {
   Saadin::Stack<std::string> Stack;

   for (int i = 0; i < this->m_Expression.length(); ++i) {
      char Character = this->m_Expression[i];
      if (Character == '+' || Character == '-' || Character == '*' || Character == '/') {
         std::string Left = Stack.Peek(); Stack.Pop();
         std::string Right = Stack.Peek(); Stack.Pop();
         Stack.Push(Character + Right + Left);
      }
      else Stack.Push(std::string(1, Character));
   }

   std::string Output;
   while (!Stack.IsEmpty()) {
      Output += Stack.Peek(); Stack.Pop();
   }
   return Output;
}

#endif