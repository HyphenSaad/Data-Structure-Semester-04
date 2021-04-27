#include <iostream>
#include <iomanip>

namespace Saadin {
   void Head();
   void Body();
   void Menu();
   std::string Repeat(const char&, const int&);
}

void Saadin::Menu() {
   Saadin::Head();
   Saadin::Body();
}

std::string Saadin::Repeat(const char& Character, const int& Times) {
   std::string Data;
   Data = Character;
   for (int Saadin_i = 1; Saadin_i < Times; ++Saadin_i) Data += Character;
   return Data;
}

void Saadin::Head() {
   using namespace Saadin;
   std::cout
      << Repeat(char(219), 2) << Repeat(char(205), 43) << Repeat(char(219), 2) << std::endl
      << ' ' << char(222) << Repeat(' ', 5) << "SINGLY LINKED LIST IMPLEMENTATION" << Repeat(' ', 5) << char(221) << std::endl
      << ' ' << char(222) << Repeat(' ', 8) << "PROGRAMMED BY: SAAD MANSOOR" << Repeat(' ', 8) << char(221) << std::endl
      << ' ' << char(222) << Repeat(' ', 14) << "SAADIN-70075954" << Repeat(' ', 14) << char(221) << std::endl
      << ' ' << char(222) << Repeat(char(196), 43) << char(221) << std::endl;
}

void Saadin::Body() {
   using namespace Saadin;
   std::cout
      << ' ' << char(222) << ' ' << char(175) << " 01: Insert At Start" << Repeat(' ', 21) << char(221) << std::endl
      << ' ' << char(222) << ' ' << char(175) << " 02: Insert At Last" << Repeat(' ', 22) << char(221) << std::endl
      << ' ' << char(222) << ' ' << char(175) << " 03: Insert At Position" << Repeat(' ', 18) << char(221) << std::endl
      << ' ' << char(222) << ' ' << char(175) << " 04: Delete From Start" << Repeat(' ', 19) << char(221) << std::endl
      << ' ' << char(222) << ' ' << char(175) << " 05: Delete From Last" << Repeat(' ', 20) << char(221) << std::endl
      << ' ' << char(222) << ' ' << char(175) << " 06: Delete From Position" << Repeat(' ', 16) << char(221) << std::endl
      << ' ' << char(222) << ' ' << char(175) << " 07: Search Data" << Repeat(' ', 25) << char(221) << std::endl
      << ' ' << char(222) << ' ' << char(175) << " 08: Sort Data" << Repeat(' ', 27) << char(221) << std::endl
      << ' ' << char(222) << ' ' << char(175) << " 09: Check Size" << Repeat(' ', 26) << char(221) << std::endl
      << ' ' << char(222) << ' ' << char(175) << " 10: Is Empty?" << Repeat(' ', 27) << char(221) << std::endl
      << ' ' << char(222) << ' ' << char(175) << " 11: Display Data" << Repeat(' ', 24) << char(221) << std::endl
      << ' ' << char(222) << ' ' << char(175) << " 00: Close Program" << Repeat(' ', 23) << char(221) << std::endl
      << Repeat(char(219), 2) << Repeat(char(205), 43) << Repeat(char(219), 2) << std::endl;
}