#ifndef AIRLINE_NODE
#define AIRLINE_NODE

#include "includes.cpp"

struct Data {
   std::string FirstName = 0, LastName = 0, Address = 0, From = 0,
      To = 0, ReservationNumber = 0;
   unsigned short BusinessSeat_LC = 0, EconomySeat_LC = 0;
   unsigned short BusinessSeat_IC = 0, EconomySeat_IC = 0;
};

struct Node {
public:
   Node* Next = NULL;
   Node* Previous = NULL;
   Data* Information;
};

#endif