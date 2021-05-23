#ifndef PREFIX_SAADIN
#define PREFIX_SAADIN

#include <string>
#include "Stack.cpp"

namespace Saadin {
   class Prefix {
      std::string m_Expression;
   public:
      Prefix(const std::string&);
      std::string ToInfix();
      std::string ToPostfix();
   };
}

Saadin::Prefix::Prefix(const std::string& Expression) {
   this->m_Expression = Expression;
}

std::string Saadin::Prefix::ToInfix() {
   Saadin::Stack<std::string> Stack;

   for (int i = this->m_Expression.length() - 1; i >= 0; --i) {
      char Character = this->m_Expression[i];
      if (Character == '+' || Character == '-' || Character == '*' || Character == '/') {
         std::string Left = Stack.Peek(); Stack.Pop();
         std::string Right = Stack.Peek(); Stack.Pop();
         Stack.Push("(" + Left + Character + Right + ")");
      }
      else Stack.Push(std::string(1, Character));
   }

   return Stack.Peek();
}

std::string Saadin::Prefix::ToPostfix() {
   Saadin::Stack<std::string> Stack;

   for (int i = this->m_Expression.length() - 1; i >= 0; --i) {
      char Character = this->m_Expression[i];
      if (Character == '+' || Character == '-' || Character == '*' || Character == '/') {
         std::string Left = Stack.Peek(); Stack.Pop();
         std::string Right = Stack.Peek(); Stack.Pop();
         Stack.Push(Left + Right + Character);
      }
      else Stack.Push(std::string(1, Character));
   }

   return Stack.Peek();
}

#endif