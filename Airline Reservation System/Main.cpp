#include <iostream>
#include <string>
#include <ctime>
#include <conio.h>
#include <iomanip>
#include <algorithm>
#include <windows.h>
unsigned long TICKET_NUMBER = 12345678;
///////////////////////////////////////////////////////////////////////////////////////////////
template <typename Type>
class Node {
private:
   Type m_Data;
   Node<Type>* m_Next;
public:
   Node();
   Node(const Type&);
   Node(const Type&, Node<Type>*);
   void SetData(const Type&);
   void SetNext(Node<Type>*);
   Type GetData() const;
   Node<Type>* GetNext() const;
};

template <typename Type>
Node<Type>::Node() : m_Data(0), m_Next(NULL) {}

template <typename Type>
Node<Type>::Node(const Type& Data) : m_Data(Data), m_Next(NULL) {}

template <typename Type>
Node<Type>::Node(const Type& Data, Node<Type>* Next) : m_Data(Data), m_Next(Next) {}

template <typename Type>
void Node<Type>::SetData(const Type& Data) { this->m_Data = Data; }

template <typename Type>
void Node<Type>::SetNext(Node<Type>* Next) { this->m_Next = Next; }

template <typename Type>
Type Node<Type>::GetData() const { return this->m_Data; }

template <typename Type>
Node<Type>* Node<Type>::GetNext() const { return this->m_Next; }
///////////////////////////////////////////////////////////////////////////////////////////////
template <typename Type>
class Singly {
private:
   Node<Type>* m_Head;
   int m_Size;

public:
   Singly();
   ~Singly();

   void InsertAtStart(Type);
   void InsertAtLast(Type);
   void InsertAtPosition(Type, const int&);

   void DeleteFromStart();
   void DeleteFromPosition(const int&);
   void DeleteFromEnd();

   int GetSize() const;
   bool IsEmpty() const;
   Node<Type>* GetHead() const;
   void Clear();
};

template <typename Type>
Singly<Type>::Singly() : m_Size(0), m_Head(NULL) {}

template <typename Type>
Singly<Type>::~Singly() {
   this->Clear();
}

template <typename Type>
void Singly<Type>::Clear() {
   Node<Type>* Hold = this->m_Head;
   while (Hold != NULL) {
      Node<Type>* Temp = Hold;
      Hold = Hold->GetNext();
      delete Temp;
   }
}

template <typename Type>
void Singly<Type>::InsertAtStart(Type Data) {
   this->m_Head = new Node<Type>(Data, this->m_Head);
   ++(this->m_Size);
}

template <typename Type>
void Singly<Type>::InsertAtLast(Type Data) {
   if (this->m_Head == NULL) { this->InsertAtStart(Data); return; }

   Node<Type>* Hold = this->m_Head;
   while (Hold->GetNext() != NULL) Hold = Hold->GetNext();

   Node<Type>* Packet = new Node<Type>(Data);
   Hold->SetNext(Packet);
   ++(this->m_Size);
}

template <typename Type>
void Singly<Type>::InsertAtPosition(Type Data, const int& Position) {
   if (Position < 0 || Position > this->m_Size) return;
   if (this->IsEmpty() || Position == 0) { this->InsertAtStart(Data); return; }

   Node<Type>* Hold = this->m_Head;
   for (int i = 1; i < Position; i++) Hold = Hold->GetNext();

   Node<Type>* Packet = new Node<Type>(Data, Hold->GetNext());
   Hold->SetNext(Packet);
   ++(this->m_Size);
}

template <typename Type>
void Singly<Type>::DeleteFromStart() {
   Node<Type>* Hold = this->m_Head;
   this->m_Head = Hold->GetNext();
   delete Hold;
   --(this->m_Size);
}

template <typename Type>
void Singly<Type>::DeleteFromPosition(const int& Position) {
   if (Position < 0 || Position > this->m_Size) return;
   --(this->m_Size);

   if (Position == 0) {
      Node<Type>* Hold = this->m_Head;
      this->m_Head = Hold->GetNext();
      delete Hold;
      return;
   }

   Node<Type>* Hold = this->m_Head;
   for (int i = 0; i < Position - 1;++i) Hold = Hold->GetNext();

   Node<Type>* Keep = Hold->GetNext()->GetNext();
   delete Hold->GetNext();
   Hold->SetNext(Keep);
}

template <typename Type>
void Singly<Type>::DeleteFromEnd() {
   Node<Type>* Hold = this->m_Head;
   for (int i = 2; i < this->m_Size; ++i) Hold = Hold->GetNext();

   delete Hold->GetNext();
   Hold->SetNext(NULL);
   --(this->m_Size);
}

template <typename Type>
int Singly<Type>::GetSize() const { return this->m_Size; }

template <typename Type>
bool Singly<Type>::IsEmpty() const { return this->m_Head == NULL; }

template <typename Type>
Node<Type>* Singly<Type>::GetHead() const { return this->m_Head; }
///////////////////////////////////////////////////////////////////////////////////////////////
enum Role { PASSENGER, ADMIN };
enum Sex { MALE, FEMALE, OTHER };
enum Airline { PIA, AIR_BLUE, ARAB_EMIRATES, QATAR_AIRWAYS, };
enum FlightType { LOCAL, INTERNATIONAL, };
enum SeatType { BUSINESS, ECONOMY };

struct Time {
   unsigned int Hours, Minutes;
   Time() : Hours(0), Minutes(0) {}
   Time(const unsigned int& Hours, const unsigned int& Minutes)
      : Hours(Hours), Minutes(Minutes) {}
};

struct Date {
   unsigned int Day, Month, Year;
   Date() : Day(0), Month(0), Year(0) {}
   Date(const unsigned int& Day, const unsigned int& Month, const unsigned int& Year)
      : Day(Day), Month(Month), Year(Year) {}
};

struct AdditionalInfo {
   unsigned short SeatNumber;
   SeatType Type;
   std::string FlightNumber;
};

struct Booking {
   Time Time;
   Date Date;
   unsigned long TicketNumber;
   std::string FlightNumber;
   Airline Company;
   std::string Source, Destination;
   SeatType Type;
   unsigned int LuggageWeight;
   unsigned short SeatNumber;
};
///////////////////////////////////////////////////////////////////////////////////////////////
namespace Utilities {
   bool ValidateDay(const int& Day) { return (Day > 0 && Day < 32); }
   bool ValidateMonth(const int& Month) { return (Month > 0 && Month < 13); }
   bool ValidateYear(const int& Year) { return (Year > 2000 && Year < 2100); }
   bool ValidateHour(const int& Hour) { return (Hour > -1 && Hour < 24); }
   bool ValidateMinute(const int& Minute) { return (Minute > -1 && Minute < 60); }
   bool IsPrevious(const Date& Previous_D, const Time& Previous_T) {
      time_t now = time(0);
      tm* T = localtime(&now);
      if (Previous_D.Year != (1900 + T->tm_year))
         return (Previous_D.Year < (1900 + T->tm_year));
      if (Previous_D.Month != (1 + T->tm_mon))
         return (Previous_D.Month < (1 + T->tm_mon));
      if (Previous_D.Day != T->tm_mday)
         return (Previous_D.Day < T->tm_mday);
      if (Previous_T.Hours != T->tm_hour)
         return (Previous_T.Hours < T->tm_hour);
      return (Previous_T.Minutes < T->tm_min);
   }
}
///////////////////////////////////////////////////////////////////////////////////////////////
class User;
class Flight {
private:
   Singly<User> m_Passengers;
   Airline m_Company;
   FlightType m_FlightType;
   std::string m_FlightNumber, m_Source, m_Destination;
   Time m_Time;
   Date m_Date;

   unsigned short m_BusinessClassSeats, m_EconomyClassSeats;
   unsigned short m_BookedBusinessClassSeats, m_BookedEconomyClassSeats;
   unsigned short m_BusinessClassWeight, m_EconomyClassWeight;

public:
   Flight();
   Flight(
      const Airline&,
      const FlightType&,
      const std::string&,
      const std::string&,
      const std::string&,
      const Time&,
      const Date&,
      const unsigned short&,
      const unsigned short&,
      const unsigned short&,
      const unsigned short&);

   Airline GetCompany() const;
   FlightType GetFlightType() const;
   std::string GetFlightNumber() const;
   std::string GetSource() const;
   std::string GetDestination() const;
   Time GetTiming() const;
   Date GetDate() const;
   unsigned short GetBusinessClassSeats() const;
   unsigned short GetEconomyClassSeats() const;
   unsigned short GetBookedBusinessClassSeats() const;
   unsigned short GetBookedEconomyClassSeats() const;
   unsigned short GetBusinessClassLuggageWeight() const;
   unsigned short GetEconomyClassLuggageWeight() const;

   void SetCompany(const Airline&);
   void SetFlightType(const FlightType&);
   void SetFlightNumber(const std::string&);
   void SetSource(const std::string&);
   void SetDestination(const std::string&);
   void SetTiming(const Time&);
   void SetDate(const Date&);
   void SetBusinessClassSeats(const unsigned short&);
   void SetEconomyClassSeats(const unsigned short&);
   void SetBusinessClassLuggageWeight(const unsigned short&);
   void SetEconomyClassLuggageWeight(const unsigned short&);

   void RegisterSeat(User, const SeatType&);
};
///////////////////////////////////////////////////////////////////////////////////////////////
class User {
private:
   Role m_Role;
   Sex m_Sex;
   std::string m_FirstName, m_LastName, m_Username, m_Password;
   unsigned short m_Age;
   Singly<Booking>* m_CurrentBookings;
   Singly<Booking>* m_PreviousBookings;

public:
   ~User();
   User();
   User(
      const std::string&,
      const std::string&,
      const std::string&,
      const std::string&,
      const unsigned short&,
      const Role&,
      const Sex&);

   Role GetRole() const;
   Sex GetSex() const;
   std::string GetFirstName() const;
   std::string GetLastName() const;
   std::string GetUsername() const;
   std::string GetPassword() const;
   unsigned short GetAge() const;
   Singly<Booking>* GetCurrentBookings() const;
   void SetCurrentBookings(Singly<Booking>*);
   Singly<Booking>* GetPreviousBookings() const;

   void BookSeat(const Flight&, SeatType Type);
};
///////////////////////////////////////////////////////////////////////////////////////////////
User::~User() {
   delete m_CurrentBookings;
   delete m_PreviousBookings;
}

User::User()
   : m_CurrentBookings(new Singly<Booking>),
   m_PreviousBookings(new Singly<Booking>) {}

User::User(
   const std::string& FirstName,
   const std::string& LastName,
   const std::string& Username,
   const std::string& Password,
   const unsigned short& Age,
   const Role& Role,
   const Sex& Sex) :
   m_FirstName(FirstName),
   m_LastName(LastName),
   m_Username(Username),
   m_Password(Password),
   m_Age(Age),
   m_Role(Role),
   m_Sex(Sex),
   m_CurrentBookings(new Singly<Booking>),
   m_PreviousBookings(new Singly<Booking>) {}

Role User::GetRole() const {
   return this->m_Role;
}

Sex User::GetSex() const {
   return this->m_Sex;
}

std::string User::GetFirstName() const {
   return this->m_FirstName;
}

std::string User::GetLastName() const {
   return this->m_LastName;
}

std::string User::GetUsername() const {
   return this->m_Username;
}

std::string User::GetPassword() const {
   return this->m_Password;
}

unsigned short User::GetAge() const {
   return this->m_Age;
}

Singly<Booking>* User::GetCurrentBookings() const {
   return m_CurrentBookings;
}

void User::SetCurrentBookings(Singly<Booking>* Obj) {
   this->m_CurrentBookings = Obj;
}

Singly<Booking>* User::GetPreviousBookings() const {
   return m_PreviousBookings;
}

void User::BookSeat(const Flight& Obj, SeatType Type) {
   Booking Data;
   Data.Company = Obj.GetCompany();
   Data.Date = Obj.GetDate();
   Data.Destination = Obj.GetDestination();
   Data.FlightNumber = Obj.GetFlightNumber();
   Data.LuggageWeight = Type == ECONOMY ? Obj.GetEconomyClassLuggageWeight() : Obj.GetBusinessClassLuggageWeight();
   Data.SeatNumber = Type == ECONOMY ? Obj.GetBookedEconomyClassSeats() : Obj.GetBookedBusinessClassSeats();
   Data.Source = Obj.GetSource();
   Data.TicketNumber = ++TICKET_NUMBER;
   Data.Time = Obj.GetTiming();
   Data.Type = Type;
   this->m_CurrentBookings->InsertAtStart(Data);
}
///////////////////////////////////////////////////////////////////////////////////////////////
Flight::Flight() :
   m_BusinessClassWeight(0),
   m_EconomyClassWeight(0),
   m_BookedBusinessClassSeats(0),
   m_BookedEconomyClassSeats(0) {}

Flight::Flight(
   const Airline& Company,
   const FlightType& Type,
   const std::string& FlightNumber,
   const std::string& Source,
   const std::string& Destination,
   const Time& FlightTime,
   const Date& FlightDate,
   const unsigned short& BusinessClassSeats,
   const unsigned short& EconomyClassSeats,
   const unsigned short& BusinessClassWeight,
   const unsigned short& EconomyClassWeight) :
   m_Company(Company),
   m_FlightType(Type),
   m_FlightNumber(FlightNumber),
   m_Source(Source),
   m_Destination(Destination),
   m_Time(FlightTime),
   m_Date(FlightDate),
   m_BusinessClassSeats(BusinessClassSeats),
   m_EconomyClassSeats(EconomyClassSeats),
   m_BusinessClassWeight(BusinessClassWeight),
   m_EconomyClassWeight(EconomyClassWeight),
   m_BookedBusinessClassSeats(0),
   m_BookedEconomyClassSeats(0) {}

Airline Flight::GetCompany() const {
   return this->m_Company;
}

FlightType Flight::GetFlightType() const {
   return this->m_FlightType;
}

std::string Flight::GetFlightNumber() const {
   return this->m_FlightNumber;
}

std::string Flight::GetSource() const {
   return this->m_Source;
}

std::string Flight::GetDestination() const {
   return this->m_Destination;
}

Time Flight::GetTiming() const {
   return this->m_Time;
}

Date Flight::GetDate() const {
   return this->m_Date;
}

unsigned short Flight::GetBusinessClassSeats() const {
   return this->m_BusinessClassSeats;
}

unsigned short Flight::GetEconomyClassSeats() const {
   return this->m_EconomyClassSeats;
}

unsigned short Flight::GetBookedBusinessClassSeats() const {
   return this->m_BookedBusinessClassSeats;
}

unsigned short Flight::GetBookedEconomyClassSeats() const {
   return this->m_BookedEconomyClassSeats;
}

unsigned short Flight::GetBusinessClassLuggageWeight() const {
   return this->m_BusinessClassWeight;
}

unsigned short Flight::GetEconomyClassLuggageWeight() const {
   return this->m_EconomyClassWeight;
}

void Flight::SetCompany(const Airline& Company) {
   this->m_Company = Company;
}

void Flight::SetFlightType(const FlightType& Type) {
   this->m_FlightType = Type;
}

void Flight::SetFlightNumber(const std::string& FlightNumber) {
   this->m_FlightNumber = FlightNumber;
}

void Flight::SetSource(const std::string& Source) {
   this->m_Source = Source;
}

void Flight::SetDestination(const std::string& Destination) {
   this->m_Destination = Destination;
}

void Flight::SetTiming(const Time& FlightTime) {
   this->m_Time = FlightTime;
}

void Flight::SetDate(const Date& FlightDate) {
   this->m_Date = FlightDate;
}

void Flight::SetBusinessClassSeats(const unsigned short& BusinessClassSeats) {
   this->m_BusinessClassSeats = BusinessClassSeats;
}

void Flight::SetEconomyClassSeats(const unsigned short& EconomyClassSeats) {
   this->m_EconomyClassSeats = EconomyClassSeats;
}

void Flight::SetBusinessClassLuggageWeight(const unsigned short& BusinessClassWeight) {
   this->m_BusinessClassWeight = BusinessClassWeight;
}

void Flight::SetEconomyClassLuggageWeight(const unsigned short& EconomyClassWeight) {
   this->m_EconomyClassWeight = EconomyClassWeight;
}

void Flight::RegisterSeat(User Passeneger, const SeatType& Type) {
   Type == ECONOMY
      ? ++(this->m_BookedEconomyClassSeats)
      : ++(this->m_BookedBusinessClassSeats);
   this->m_Passengers.InsertAtStart(Passeneger);
}

///////////////////////////////////////////////////////////////////////////////////////////////
class Init {
private:
   Singly<User>* m_Users;
   Singly<Flight>* m_Flights;
   Singly<Flight>* m_PreviousFlights;
   Node<User>* m_CurrentUser;

private:
   bool Prompt_1();
   Airline InputAirline(bool);
   FlightType InputFlightType(bool);
   std::string InputFlightNumber(bool);
   std::string InputSource(bool);
   std::string InputDestination(bool);
   Time InputFlightTime(bool);
   Date InputFlightDate(bool);
   unsigned short InputBusinessClassSeats(bool);
   unsigned short InputEconomyClassSeats(bool);
   unsigned short InputBusinessClassWeight(bool);
   unsigned short InputEconomyClassWeight(bool);

   void Refresh(bool);
   void UserBooking(Singly<Booking>*);
   void PrintTicket(const unsigned short&);
   Singly<std::string>* GetAvailableSources();
   Singly<std::string>* GetAvailableDestinations();
   Singly<Flight>* GetFlightForRoute(
      const unsigned short&,
      const unsigned short&,
      const Singly<std::string>*,
      const Singly<std::string>*);

public:
   Init(Singly<User>*, Singly<Flight>*, Singly<Flight>*);
   int StartScreen();                                          // ADMIN & PASSENGER
   int LoginScreen();                                          // ADMIN & PASSENGER
   bool CreateUserScreen();                                    // PASSENGER
   void AboutScreen();                                         // ADMIN & PASSENGER

   int AdminScreen();                                          // ADMIN
   void CreateFlightScreen();                                  // ADMIN
   void DeleteFlightScreen();                                  // ADMIN
   void UpdateFlightScreen();                                  // ADMIN
   void DisplayFlightsScreen(bool, LPCSTR, bool);              // ADMIN
   void DisplayAvailableFlights(Singly<Flight>*);              // PASSENGER

   int PassengerScreen();                                      // PASSENGER
   void MakeReservation();                                     // PASSENGER
   void CurrentBookings();                                     // PASSENGER
   void PreviousBookings();                                    // PASSENGER
};

bool Init::Prompt_1() {
   char Choice = 0;
   do {
      std::cout << "Do you want to change it? (Y/N)";
      Choice = getche();
      std::cout << std::endl;

      if (Choice == 'Y' || Choice == 'y') return true;
      else if (Choice == 'N' || Choice == 'n') return false;
      else {
         std::cout << "\nINVALID SELECTION, PRESS ANY KEY TO TRY AGAIN!" << std::endl;
         getch();
      }
   } while (Choice != 'Y' || Choice != 'y' || Choice != 'N' || Choice != 'n');
}

Airline Init::InputAirline(bool Patch = false) {
   SetConsoleTitle((LPCSTR)"(01/11) Input Airline Company | Airline Reservation System!");
   Airline Company; unsigned int X = 0;

   do {
      if (Patch) system("CLS");
      std::cout << "Airline:" << std::endl
         << "1: PIA" << std::endl
         << "2: AIR BLUE" << std::endl
         << "3: ARAB EMIRATES" << std::endl
         << "4: QATAR AIRWAYS" << std::endl
         << ">: " << std::endl;
      std::cin >> X;

      if (X == 1) Company = PIA;
      else if (X == 2) Company = AIR_BLUE;
      else if (X == 3) Company = ARAB_EMIRATES;
      else if (X == 4) Company = QATAR_AIRWAYS;
      else {
         std::cout << "INVALID SELECTION, PRESS ANY KEY TO TRY AGAIN!" << std::endl;
         std::cin.ignore(); getch();
      }
   } while (X > 4 || X == 0);

   return Company;
}

FlightType Init::InputFlightType(bool Patch = false) {
   SetConsoleTitle((LPCSTR)"(02/11) Input Flight Type | Airline Reservation System!");
   FlightType Type; unsigned int X = 0;

   do {
      if (Patch) system("CLS");
      std::cout << "Airline:" << std::endl
         << "1: LOCAL" << std::endl
         << "2: INTERNATIONAL" << std::endl
         << ">: " << std::endl;
      std::cin >> X;

      if (X == 1) Type = LOCAL;
      else if (X == 2) Type = INTERNATIONAL;
      else {
         std::cout << "INVALID SELECTION, PRESS ANY KEY TO TRY AGAIN!" << std::endl;
         std::cin.ignore(); getch();
      }
   } while (X > 2 || X == 0);

   return Type;
}

std::string Init::InputFlightNumber(bool Patch = false) {
   SetConsoleTitle((LPCSTR)"(03/11) Input Flight Number | Airline Reservation System!");
   if (Patch) system("CLS");
   std::string FlightNumber;
   std::cin.ignore();
   std::cout << "Flight Number:\t";
   std::getline(std::cin, FlightNumber);
   return FlightNumber;
}

std::string Init::InputSource(bool Patch = false) {
   SetConsoleTitle((LPCSTR)"(04/11) Input Source | Airline Reservation System!");
   if (Patch) system("CLS");
   std::string Source;
   std::cout << "Source:\t";
   std::getline(std::cin, Source);
   return Source;
}

std::string Init::InputDestination(bool Patch = false) {
   SetConsoleTitle((LPCSTR)"(05/11) Input Destination | Airline Reservation System!");
   if (Patch) system("CLS");
   std::string Destination;
   std::cout << "Destination:\t";
   std::getline(std::cin, Destination);
   return Destination;
}

Time Init::InputFlightTime(bool Patch = false) {
   SetConsoleTitle((LPCSTR)"(06/11) Input Flight Time | Airline Reservation System!");
   Time FlightTime; unsigned int X = 0, Y = 0;

   do {
      if (Patch) system("CLS");
      std::cout << "Flight Time:" << std::endl << "   Hours:\t";
      std::cin >> X;

      if (!Utilities::ValidateHour(X)) {
         std::cout << "INVALID HOURS, PRESS ANY KEY TO TRY AGAIN!" << std::endl;
         std::cin.ignore(); getch();
      }
   } while (!Utilities::ValidateHour(X));

   do {
      if (Patch) system("CLS");
      std::cout << "Flight Time:" << std::endl
         << "   Hours:\t" << (X < 10 ? "0" : "") << X << std::endl
         << "   Minutes:\t";
      std::cin >> Y;

      if (!Utilities::ValidateMinute(Y)) {
         std::cout << "INVALID MINUTES, PRESS ANY KEY TO TRY AGAIN!" << std::endl;
         std::cin.ignore(); getch();
      }
   } while (!Utilities::ValidateMinute(Y));

   FlightTime = Time(X, Y);
   return FlightTime;
}

Date Init::InputFlightDate(bool Patch = false) {
   SetConsoleTitle((LPCSTR)"(07/11) Input Flight Date | Airline Reservation System!");
   Date FlightDate; unsigned int X = 0, Y = 0, Z = 0;

   do {
      if (Patch) system("CLS");
      std::cout << "Flight Date:" << std::endl << "   Day:\t";
      std::cin >> X;

      if (!Utilities::ValidateDay(X)) {
         std::cout << "INVALID DAY, PRESS ANY KEY TO TRY AGAIN!" << std::endl;
         std::cin.ignore(); getch();
      }
   } while (!Utilities::ValidateDay(X));

   do {
      if (Patch) system("CLS");
      std::cout << "Flight Date:" << std::endl
         << "   Day:\t" << (X < 10 ? "0" : "") << X << std::endl
         << "   Month:\t";
      std::cin >> Y;

      if (!Utilities::ValidateMonth(Y)) {
         std::cout << "INVALID MONTH, PRESS ANY KEY TO TRY AGAIN!" << std::endl;
         std::cin.ignore(); getch();
      }
   } while (!Utilities::ValidateMonth(Y));

   do {
      if (Patch) system("CLS");
      std::cout << "Flight Date:" << std::endl
         << "   Day:\t" << (X < 10 ? "0" : "") << X << std::endl
         << "   Month:\t" << (Y < 10 ? "0" : "") << Y << std::endl
         << "   Year:\t";
      std::cin >> Z;

      if (!Utilities::ValidateYear(Z)) {
         std::cout << "INVALID YEAR, PRESS ANY KEY TO TRY AGAIN!" << std::endl;
         std::cin.ignore(); getch();
      }
   } while (!Utilities::ValidateYear(Z));

   FlightDate = Date(X, Y, Z);
   return FlightDate;
}

unsigned short Init::InputBusinessClassSeats(bool Patch = false) {
   SetConsoleTitle((LPCSTR)"(08/11) Input Business Class Seats | Airline Reservation System!");
   if (Patch) system("CLS");
   unsigned short BusinessClassSeats;
   std::cout << "Business Class Seats:\t";
   std::cin >> BusinessClassSeats;
   return BusinessClassSeats;
}

unsigned short Init::InputEconomyClassSeats(bool Patch = false) {
   SetConsoleTitle((LPCSTR)"(09/11) Input Economy Class Seats | Airline Reservation System!");
   if (Patch) system("CLS");
   unsigned short EconomyClassSeats;
   std::cout << "Economy Class Seats:\t";
   std::cin >> EconomyClassSeats;
   return EconomyClassSeats;
}

unsigned short Init::InputBusinessClassWeight(bool Patch = false) {
   SetConsoleTitle((LPCSTR)"(10/11) Input Business Class Weight | Airline Reservation System!");
   if (Patch) system("CLS");
   unsigned short BusinessClassWeight;
   std::cout << "Business Class Luggage Weight:\t";
   std::cin >> BusinessClassWeight;
   return BusinessClassWeight;
}

unsigned short Init::InputEconomyClassWeight(bool Patch = false) {
   SetConsoleTitle((LPCSTR)"(11/11) Input Economy Class Weight | Airline Reservation System!");
   if (Patch) system("CLS");
   unsigned short EconomyClassWeight;
   std::cout << "Economy Class Luggage Weight:\t";
   std::cin >> EconomyClassWeight;
   return EconomyClassWeight;
}

Init::Init(Singly<User>* Users, Singly<Flight>* Flights, Singly<Flight>* PreviousFlights)
   :m_Users(Users), m_Flights(Flights), m_PreviousFlights(PreviousFlights) {}

int Init::StartScreen() {
   SetConsoleTitle((LPCSTR)"Welcome to Airline Reservation System!"); system("CLS");

   unsigned short Choice = 0;
   do {
      std::cout << "WELCOME TO AIRLINE RESERVATION SYSTEM!" << std::endl
         << "1: LOGIN" << std::endl
         << "2: CREATE ACCOUNT" << std::endl
         << "3: ABOUT" << std::endl
         << "4: EXIT" << std::endl
         << ">: ";
      std::cin >> Choice;

      if (Choice > 0 && Choice < 5) return Choice;
      else {
         std::cout << "INVALID SELECTION, PRESS ANY KEY TO TRY AGAIN!" << std::endl;
         std::cin.ignore(); getch();
      }
      system("CLS");
   } while (Choice > 4);

   return Choice;
}

int Init::LoginScreen() {
   SetConsoleTitle((LPCSTR)"Login | Airline Reservation System"); system("CLS");

   std::string Username, Password;
   bool IsUserFound = false;

   std::cout << "Username:\t";
   std::cin >> Username;
   std::cout << "Password:\t";
   std::cin >> Password;

   Node<User>* Hold = this->m_Users->GetHead();
   while (Hold != NULL) {
      if ((Hold->GetData().GetUsername() == Username) && (Hold->GetData().GetPassword() == Password)) {
         this->m_CurrentUser = Hold;
         IsUserFound = true; break;
      }
      else IsUserFound = false;
      Hold = Hold->GetNext();
   }

   if (!IsUserFound) {
      std::cout << "INVALID USERNAME/PASSWORD, PRESS ANY KEY TO GO BACK!" << std::endl;
      std::cin.ignore(); getch();
      return 0;
   }

   return (Hold->GetData().GetRole() == ADMIN) ? 1 : 2;
}

bool Init::CreateUserScreen() {
   SetConsoleTitle((LPCSTR)"Create Account | Airline Reservation System!"); system("CLS");

   std::string FirstName = 0, LastName = 0, Username = 0, Password = 0;
   unsigned short Age = 0;
   Sex UserSex = OTHER;
   bool IsUserAlreadyExists = false;

   std::cout << "First Name:\t";
   std::cin >> FirstName;
   std::cout << "Last Name:\t";
   std::cin >> LastName;

   do {
      std::cout << "Username:\t";
      std::cin >> Username;

      Node<User>* Hold = this->m_Users->GetHead();
      while (Hold != NULL) {
         if (Hold->GetData().GetUsername() == Username) { IsUserAlreadyExists = true; break; }
         else IsUserAlreadyExists = false;
         Hold = Hold->GetNext();
      }

      if (IsUserAlreadyExists) {
         std::cout << "USERNAME ALREADY EXISTS, PRESS ANY KEY TO TRY AGAIN!" << std::endl;
         std::cin.ignore(); getch();
      }
   } while (IsUserAlreadyExists);

   std::cout << "Password";
   std::cin >> Password;
   std::cout << "Age:\t\t";
   std::cin >> Age;

   unsigned short Temp = 0;
   do {
      std::cout << "Sex:" << std::endl
         << "1: Male" << std::endl
         << "2: Female" << std::endl
         << "3: Other" << std::endl
         << ">: Other" << std::endl;
      std::cin >> Temp;

      if (Temp == 1) UserSex = MALE;
      else if (Temp == 2) UserSex = FEMALE;
      else if (Temp == 3) UserSex = OTHER;
      else {
         std::cout << "INVALID SELECTION, PRESS ANY KEY TO TRY AGAIN!" << std::endl;
         std::cin.ignore(); getch();
      }
   } while (Temp > 3);

   this->m_Users->InsertAtStart(User(FirstName, LastName, Username, Password, Age, PASSENGER, UserSex));
}

void Init::CreateFlightScreen() {
   SetConsoleTitle((LPCSTR)"Create Flight | Airline Reservation System"); system("CLS");
   Airline A = this->InputAirline(true);
   FlightType B = this->InputFlightType(true);
   std::string C = this->InputFlightNumber(true);
   std::string D = this->InputSource(true);
   std::string E = this->InputDestination(true);
   Time F = this->InputFlightTime(true);
   Date G = this->InputFlightDate(true);
   unsigned short H = this->InputBusinessClassSeats(true);
   unsigned short I = this->InputEconomyClassSeats(true);
   unsigned short J = this->InputBusinessClassWeight(true);
   unsigned short K = this->InputEconomyClassWeight(true);

   this->m_Flights->InsertAtStart(Flight(A, B, C, D, E, F, G, H, I, J, K));
}

void Init::DisplayFlightsScreen(bool Toggle, LPCSTR Title, bool Patch = false) {
   this->Refresh(true);
   SetConsoleTitle((LPCSTR)Title); system("CLS");
   Node<Flight>* Hold = (Toggle ? this->m_Flights->GetHead() : this->m_PreviousFlights->GetHead());
   unsigned short INDEX = 0;

   std::cout << "+" << std::setw(5) << std::setfill('-') << "+" << std::setw(16)
      << std::setfill('-') << "+" << std::setw(11) << std::setfill('-') << "+"
      << std::setw(15) << std::setfill('-') << "+" << std::setw(16) << std::setfill('-')
      << "+" << std::setw(13) << std::setfill('-') << "+" << std::setw(8) << std::setfill('-')
      << "+" << std::setw(10) << std::setfill('-') << "+" << std::setw(10) << std::setfill('-')
      << "+" << std::setw(14) << std::setfill('-') << "+" << std::endl
      << std::setw(6) << "| ## |" << std::setw(16) << "    AIRLINE    |"
      << std::setw(11) << " FLIGHT # |" << std::setw(15) << "    SOURCE    |"
      << std::setw(16) << "  DESTINATION  |" << std::setw(13) << "    DATE    |"
      << std::setw(8) << "  TIME |" << std::setw(10) << " B-CLASS |"
      << std::setw(10) << " E-CLASS |" << std::setw(14) << "   LUGGAGE   |" << std::endl
      << "+" << std::setw(5) << std::setfill('-') << "+" << std::setw(16)
      << std::setfill('-') << "+" << std::setw(11) << std::setfill('-') << "+"
      << std::setw(15) << std::setfill('-') << "+" << std::setw(16) << std::setfill('-')
      << "+" << std::setw(13) << std::setfill('-') << "+" << std::setw(8) << std::setfill('-')
      << "+" << std::setw(10) << std::setfill('-') << "+" << std::setw(10) << std::setfill('-')
      << "+" << std::setw(14) << std::setfill('-') << "+" << std::endl << std::setfill(' ');

   while (Hold != NULL) {
      if (Hold->GetData().GetDate().Day != 0) {
         std::cout << "|" << std::setw(++INDEX < 10 ? 2 : 3) << std::right
            << (INDEX < 10 ? "0" : "") << INDEX << " |";

         switch (Hold->GetData().GetCompany()) {
         case PIA:           std::cout << " PIA           | "; break;
         case QATAR_AIRWAYS: std::cout << " QATAR AIRWAYS | "; break;
         case ARAB_EMIRATES: std::cout << " ARAB EMIRATES | "; break;
         case AIR_BLUE:      std::cout << " AIR BLUE      | "; break;
         }

         std::cout << std::setw(9) << std::left << Hold->GetData().GetFlightNumber() << "| "
            << std::setw(13) << Hold->GetData().GetSource() << "| "
            << std::setw(14) << Hold->GetData().GetDestination() << "| "
            << (Hold->GetData().GetDate().Day < 10 ? "0" : "") << Hold->GetData().GetDate().Day << "/"
            << (Hold->GetData().GetDate().Month < 10 ? "0" : "") << Hold->GetData().GetDate().Month << "/"
            << std::setw(2) << Hold->GetData().GetDate().Year << " | "
            << (Hold->GetData().GetTiming().Hours < 10 ? "0" : "")
            << std::setw(Hold->GetData().GetTiming().Hours < 10 ? 1 : 2)
            << Hold->GetData().GetTiming().Hours << ":"
            << (Hold->GetData().GetTiming().Minutes < 10 ? "0" : "")
            << std::setw(Hold->GetData().GetTiming().Minutes < 10 ? 1 : 2)
            << Hold->GetData().GetTiming().Minutes << " | "
            << std::setw(3) << std::right
            << Hold->GetData().GetBookedBusinessClassSeats() << "/"
            << std::setw(3) << std::left
            << Hold->GetData().GetBusinessClassSeats() << " | "
            << std::setw(3) << std::right
            << Hold->GetData().GetBookedEconomyClassSeats() << "/"
            << std::setw(3) << std::left
            << Hold->GetData().GetEconomyClassSeats() << " | "
            << std::setw(8) << std::right << std::setprecision(1)
            << ((Hold->GetData().GetEconomyClassLuggageWeight() * Hold->GetData().GetBookedEconomyClassSeats()) + (Hold->GetData().GetBusinessClassLuggageWeight() * Hold->GetData().GetBookedBusinessClassSeats())) << " KG |" << std::endl;
      }
      Hold = Hold->GetNext();
   }

   if ((Toggle ? this->m_Flights->GetSize() : this->m_PreviousFlights->GetSize()) > 0) {
      std::cout << "+" << std::setw(5) << std::setfill('-') << "+" << std::setw(16)
         << std::setfill('-') << "+" << std::setw(11) << std::setfill('-') << "+"
         << std::setw(15) << std::setfill('-') << "+" << std::setw(16) << std::setfill('-')
         << "+" << std::setw(13) << std::setfill('-') << "+" << std::setw(8) << std::setfill('-')
         << "+" << std::setw(10) << std::setfill('-') << "+" << std::setw(10) << std::setfill('-')
         << "+" << std::setw(14) << std::setfill('-') << "+" << std::endl;
   }
   else {
      std::cout << std::setw(68) << std::right << "NO DATA AVAILABLE" << std::endl << std::left;
   }

   if (!Patch) {
      std::cout << "PRESS ANY KEY TO GO BACK" << std::endl;
      std::cin.ignore(); getch();
   }
}

int Init::AdminScreen() {
   SetConsoleTitle((LPCSTR)"Admin | Airline Reservation System!"); system("CLS");

   unsigned short Choice = 0;
   do {
      std::cout << "WELCOME TO ADMIN PANEL!" << std::endl
         << "1: CREATE FLIGHT" << std::endl
         << "2: DELETE FLIGHT" << std::endl
         << "3: UPDATE FLIGHT" << std::endl
         << "4: AVALIABLE FLIGHT" << std::endl
         << "5: PREVIOUS FLIGHTS" << std::endl
         << "6: LOGOUT" << std::endl
         << ">: ";
      std::cin >> Choice;

      if (Choice > 0 && Choice < 7) return Choice;
      else {
         std::cout << "INVALID SELECTION, PRESS ANY KEY TO TRY AGAIN!" << std::endl;
         std::cin.ignore(); getch();
      }
      system("CLS");
   } while (Choice > 6 || Choice == 0);

   return 0;
}

void Init::DeleteFlightScreen() {
   this->DisplayFlightsScreen(this->m_Flights, "Delete Flight | Airline Reservation System!", true);

   if (this->m_Flights->GetSize() > 0) {
      unsigned short Choice = 0;
      do {
         std::cout << "ENTER 0 TO GO BACK!" << std::endl << "Select Flight To Delete:\t";
         std::cin >> Choice;

         if (Choice > this->m_Flights->GetSize()) {
            std::cout << "INVALID SELECTION, PRESS ANY KEY TO TRY AGAIN!" << std::endl;
            std::cin.ignore(); getch();
         }
      } while (Choice > this->m_Flights->GetSize());

      this->m_Flights->DeleteFromPosition(Choice - 1);
   }
   else {
      std::cout << "NO FLIGHT AVAILABLE TO DELETE, PRESS ANY KEY TO GO BACK!" << std::endl;
      std::cin.ignore(); getch();
   }
}

void Init::UpdateFlightScreen() {
   this->DisplayFlightsScreen(this->m_Flights, "Update Flight | Airline Reservation System!", true);

   if (this->m_Flights->GetSize() > 0) {
      unsigned short Choice = 0;
      do {
         std::cout << "ENTER 0 TO GO BACK!" << std::endl << "Select Flight To Update:\t";
         std::cin >> Choice;

         if (Choice > this->m_Flights->GetSize()) {
            std::cout << "INVALID SELECTION, PRESS ANY KEY TO TRY AGAIN!" << std::endl;
            std::cin.ignore(); getch();
         }

         if (Choice == 0) return;
      } while (Choice > this->m_Flights->GetSize());

      Node<Flight>* X = this->m_Flights->GetHead();
      for (int i = 1; i < Choice;++i) X = X->GetNext();

      Flight Hold;
      SetConsoleTitle((LPCSTR)"(01/11) Input Airline Company | Airline Reservation System!");
      system("CLS");
      std::cout << "Company:\t";
      switch (X->GetData().GetCompany()) {
      case PIA: std::cout << "PIA" << std::endl; break;
      case ARAB_EMIRATES: std::cout << "ARAB EMIRATES" << std::endl; break;
      case AIR_BLUE: std::cout << "AIR BLUE" << std::endl; break;
      case QATAR_AIRWAYS: std::cout << "QATAR AIRWAYS" << std::endl; break;
      }
      if (this->Prompt_1()) Hold.SetCompany(this->InputAirline(false));
      else {
         SetConsoleTitle((LPCSTR)"(02/11) Input Flight Type | Airline Reservation System!");
         Hold.SetCompany(X->GetData().GetCompany());
      }

      system("CLS");
      std::cout << "Flight Type:\t";
      switch (X->GetData().GetFlightType()) {
      case LOCAL: std::cout << "LOCAL" << std::endl; break;
      case INTERNATIONAL: std::cout << "INTERNATIONAL" << std::endl; break;
      }
      if (this->Prompt_1()) Hold.SetFlightType(this->InputFlightType(false));
      else {
         SetConsoleTitle((LPCSTR)"(03/11) Input Flight Number | Airline Reservation System!");
         Hold.SetFlightType(X->GetData().GetFlightType());
      }

      system("CLS");
      std::cout << "Flight Number:\t" << X->GetData().GetFlightNumber() << std::endl;
      if (this->Prompt_1()) Hold.SetFlightNumber(this->InputFlightNumber(false));
      else {
         SetConsoleTitle((LPCSTR)"(04/11) Input Source | Airline Reservation System!");
         Hold.SetFlightNumber(X->GetData().GetFlightNumber());
      }

      system("CLS");
      std::cout << "Source:\t" << X->GetData().GetSource() << std::endl;
      if (this->Prompt_1()) Hold.SetSource(this->InputSource(false));
      else {
         SetConsoleTitle((LPCSTR)"(05/11) Input Destination | Airline Reservation System!");
         Hold.SetSource(X->GetData().GetSource());
      }

      system("CLS");
      std::cout << "Destination:\t" << X->GetData().GetDestination() << std::endl;
      if (this->Prompt_1()) Hold.SetDestination(this->InputDestination(false));
      else {
         SetConsoleTitle((LPCSTR)"(06/11) Input Flight Time | Airline Reservation System!");
         Hold.SetDestination(X->GetData().GetDestination());
      }

      system("CLS");
      std::cout << "Timing:\t" << (X->GetData().GetTiming().Hours < 10 ? "0" : "")
         << X->GetData().GetTiming().Hours << ":"
         << (X->GetData().GetTiming().Minutes < 10 ? "0" : "")
         << X->GetData().GetTiming().Minutes << std::endl;
      if (this->Prompt_1()) Hold.SetTiming(this->InputFlightTime(false));
      else {
         SetConsoleTitle((LPCSTR)"(07/11) Input Flight Date | Airline Reservation System!");
         Hold.SetTiming(X->GetData().GetTiming());
      }

      system("CLS");
      std::cout << "Date:\t" << (X->GetData().GetDate().Day < 10 ? "0" : "")
         << X->GetData().GetDate().Day << "/"
         << (X->GetData().GetDate().Month < 10 ? "0" : "")
         << "/" << X->GetData().GetDate().Month << "/"
         << X->GetData().GetDate().Year << std::endl;
      if (this->Prompt_1()) Hold.SetDate(this->InputFlightDate(false));
      else {
         SetConsoleTitle((LPCSTR)"(08/11) Input Business Class Seats | Airline Reservation System!");
         Hold.SetDate(X->GetData().GetDate());
      }

      system("CLS");
      std::cout << "Business Class Seats:\t" << X->GetData().GetBusinessClassSeats() << std::endl;
      if (this->Prompt_1()) Hold.SetBusinessClassSeats(this->InputBusinessClassSeats(false));
      else {
         SetConsoleTitle((LPCSTR)"(09/11) Input Economy Class Seats | Airline Reservation System!");
         Hold.SetBusinessClassSeats(X->GetData().GetBusinessClassSeats());
      }

      system("CLS");
      std::cout << "Economy Class Seats:\t" << X->GetData().GetEconomyClassSeats() << std::endl;
      if (this->Prompt_1()) Hold.SetEconomyClassSeats(this->InputEconomyClassSeats(false));
      else {
         SetConsoleTitle((LPCSTR)"(10/11) Input Business Class Weight | Airline Reservation System!");
         Hold.SetEconomyClassSeats(X->GetData().GetEconomyClassSeats());
      }

      system("CLS"); std::cout << "Business Class Luggage Weight:\t" << X->GetData().GetBusinessClassLuggageWeight() << std::endl;
      if (this->Prompt_1()) Hold.SetBusinessClassLuggageWeight(this->InputBusinessClassWeight(false));
      else {
         SetConsoleTitle((LPCSTR)"(11/11) Input Economy Class Weight | Airline Reservation System!");
         Hold.SetBusinessClassLuggageWeight(X->GetData().GetBusinessClassLuggageWeight());
      }

      system("CLS"); std::cout << "Economy Class Luggage Weight:\t" << X->GetData().GetEconomyClassLuggageWeight() << std::endl;
      if (this->Prompt_1()) Hold.SetEconomyClassLuggageWeight(this->InputEconomyClassWeight(false));
      else {
         Hold.SetEconomyClassLuggageWeight(X->GetData().GetEconomyClassLuggageWeight());
      }

      X->SetData(Hold);
   }
   else {
      std::cout << "NO FLIGHT AVAILABLE TO UPDATE, PRESS ANY KEY TO GO BACK!" << std::endl;
      std::cin.ignore(); getch();
   }
}

int Init::PassengerScreen() {
   SetConsoleTitle((LPCSTR)"Passenger | Airline Reservation System!"); system("CLS");

   unsigned short Choice = 0;
   do {
      std::cout << "WELCOME TO PASSENGER PANEL!" << std::endl
         << "1: MAKE RESERVATION" << std::endl
         << "2: CURRENT BOOKINGS" << std::endl
         << "3: PREVIOUS BOOKINGS" << std::endl
         << "4: LOGOUT" << std::endl
         << ">: ";
      std::cin >> Choice;

      if (Choice > 0 && Choice < 5) return Choice;
      else {
         std::cout << "INVALID SELECTION, PRESS ANY KEY TO TRY AGAIN!" << std::endl;
         std::cin.ignore(); getch();
      }
      system("CLS");
   } while (Choice > 4 || Choice == 0);

   return 0;
}

Singly<std::string>* Init::GetAvailableSources() {
   Singly<std::string>* AvailableSources = new Singly<std::string>();

   Node<Flight>* Hold = this->m_Flights->GetHead();
   for (int i = 0; Hold != NULL;++i) {
      bool Unique = true;
      std::string X = Hold->GetData().GetSource();
      if (i == 0) AvailableSources->InsertAtStart(X);

      Node<std::string>* Temp = AvailableSources->GetHead();
      while (Temp != NULL) {
         if (X == Temp->GetData()) {
            Unique = false;
            break;
         }
         Temp = Temp->GetNext();
      }

      if (Unique) AvailableSources->InsertAtStart(X);
      Hold = Hold->GetNext();
   }

   return AvailableSources;
}

Singly<std::string>* Init::GetAvailableDestinations() {
   Singly<std::string>* AvailableDestinations = new Singly<std::string>();

   Node<Flight>* Hold = this->m_Flights->GetHead();
   for (int i = 0; Hold != NULL;++i) {
      bool Unique = true;
      std::string X = Hold->GetData().GetDestination();
      if (i == 0) AvailableDestinations->InsertAtStart(X);

      Node<std::string>* Temp = AvailableDestinations->GetHead();
      while (Temp != NULL) {
         if (X == Temp->GetData()) {
            Unique = false;
            break;
         }
         Temp = Temp->GetNext();
      }

      if (Unique) AvailableDestinations->InsertAtStart(X);
      Hold = Hold->GetNext();
   }

   return AvailableDestinations;
}

Singly<Flight>* Init::GetFlightForRoute(const unsigned short& x, const unsigned short& y, const Singly<std::string>* AvailableSources, const Singly<std::string>* AvailableDestinations) {
   std::string Source, Destination;

   Node<std::string>* X = AvailableSources->GetHead();
   for (int i = 1; X != NULL; i++) {
      if (i == x) { Source = X->GetData(); break; }
      X = X->GetNext();
   }

   Node<std::string>* Y = AvailableDestinations->GetHead();
   for (int i = 1; Y != NULL; i++) {
      if (i == y) { Destination = Y->GetData(); break; }
      Y = Y->GetNext();
   }

   Singly<Flight>* _Data;
   Node<Flight>* Hold = this->m_Flights->GetHead();
   while (Hold != NULL) {
      if (Hold->GetData().GetSource() == Source && Hold->GetData().GetDestination() == Destination) _Data->InsertAtStart(Hold->GetData());
      Hold = Hold->GetNext();
   }

   return _Data;
}

void Init::DisplayAvailableFlights(Singly<Flight>* Flights) {
   this->Refresh(true);
   system("CLS");
   Node<Flight>* Hold = Flights->GetHead();

   std::cout << "+" << std::setw(5) << std::setfill('-') << "+" << std::setw(16)
      << std::setfill('-') << "+" << std::setw(11) << std::setfill('-') << "+"
      << std::setw(15) << std::setfill('-') << "+" << std::setw(16) << std::setfill('-')
      << "+" << std::setw(13) << std::setfill('-') << "+" << std::setw(8) << std::setfill('-')
      << "+" << std::setw(12) << std::setfill('-') << "+" << std::setw(12) << std::setfill('-') << "+" << std::endl
      << std::setw(6) << "| ## |" << std::setw(16) << "    AIRLINE    |"
      << std::setw(11) << " FLIGHT # |" << std::setw(15) << "    SOURCE    |"
      << std::setw(16) << "  DESTINATION  |" << std::setw(13) << "    DATE    |"
      << std::setw(8) << "  TIME |" << std::setw(12) << "  B-SEATS  |"
      << std::setw(12) << "  E-SEATS  |" << std::endl
      << "+" << std::setw(5) << std::setfill('-') << "+" << std::setw(16)
      << std::setfill('-') << "+" << std::setw(11) << std::setfill('-') << "+"
      << std::setw(15) << std::setfill('-') << "+" << std::setw(16) << std::setfill('-')
      << "+" << std::setw(13) << std::setfill('-') << "+" << std::setw(8) << std::setfill('-')
      << "+" << std::setw(12) << std::setfill('-') << "+" << std::setw(12)
      << std::setfill('-') << "+" << std::endl << std::setfill(' ');

   for (unsigned short INDEX = 0; INDEX < Flights->GetSize(); ) {
      if (Hold->GetData().GetDate().Day != 0) {
         std::cout << "|" << std::setw(++INDEX < 10 ? 2 : 3) << std::right
            << (INDEX < 10 ? "0" : "") << INDEX << " |";

         switch (Hold->GetData().GetCompany()) {
         case PIA:           std::cout << " PIA           | "; break;
         case QATAR_AIRWAYS: std::cout << " QATAR AIRWAYS | "; break;
         case ARAB_EMIRATES: std::cout << " ARAB EMIRATES | "; break;
         case AIR_BLUE:      std::cout << " AIR BLUE      | "; break;
         }

         std::cout << std::setw(9) << std::left << Hold->GetData().GetFlightNumber() << "| "
            << std::setw(13) << Hold->GetData().GetSource() << "| "
            << std::setw(14) << Hold->GetData().GetDestination() << "| "
            << (Hold->GetData().GetDate().Day < 10 ? "0" : "") << Hold->GetData().GetDate().Day << "/"
            << (Hold->GetData().GetDate().Month < 10 ? "0" : "") << Hold->GetData().GetDate().Month << "/"
            << std::setw(2) << Hold->GetData().GetDate().Year << " | "
            << (Hold->GetData().GetTiming().Hours < 10 ? "0" : "")
            << std::setw(Hold->GetData().GetTiming().Hours < 10 ? 1 : 2)
            << Hold->GetData().GetTiming().Hours << ":"
            << (Hold->GetData().GetTiming().Minutes < 10 ? "0" : "")
            << std::setw(Hold->GetData().GetTiming().Minutes < 10 ? 1 : 2)
            << Hold->GetData().GetTiming().Minutes << " | "
            << std::setw(2) << std::right
            << Hold->GetData().GetBusinessClassSeats() - Hold->GetData().GetBookedBusinessClassSeats() << ", "
            << std::setw(2) << std::right
            << Hold->GetData().GetBusinessClassLuggageWeight() << " KG | "
            << std::setw(2) << std::right
            << Hold->GetData().GetEconomyClassSeats() - Hold->GetData().GetBookedEconomyClassSeats() << ", "
            << std::setw(2) << std::right
            << Hold->GetData().GetEconomyClassLuggageWeight() << " KG | "
            << std::endl;
      }
      Hold = Hold->GetNext();
   }

   if (Flights->GetSize() > 0) {
      std::cout << "+" << std::setw(5) << std::setfill('-') << "+" << std::setw(16)
         << std::setfill('-') << "+" << std::setw(11) << std::setfill('-') << "+"
         << std::setw(15) << std::setfill('-') << "+" << std::setw(16) << std::setfill('-')
         << "+" << std::setw(13) << std::setfill('-') << "+" << std::setw(8) << std::setfill('-')
         << "+" << std::setw(12) << std::setfill('-') << "+" << std::setw(12) << std::setfill('-')
         << "+" << std::endl;
   }
   else {
      std::cout << std::setw(63) << std::right << "NO DATA AVAILABLE" << std::endl << std::left;
      std::cout << "PRESS ANY KEY TO GO BACK" << std::endl;
      std::cin.ignore(); getch();
   }
}

void Init::MakeReservation() {
   this->Refresh(false);

   SetConsoleTitle((LPCSTR)"Make Reservation | Airline Reservation System!");
   Singly<std::string>* A = this->GetAvailableSources();
   Singly<std::string>* B = this->GetAvailableDestinations();
   unsigned short x = 0, y = 0, z = 0;

   do {
      system("CLS");
      if (A->GetSize() == 0) {
         std::cout << "SORRY, NO DATA AVAILABLE!" << std::endl
            << "PRESS ANY KEY TO GO BACK!" << std::endl;
         std::cin.ignore(); getch(); return;
      }

      Node<std::string>* X = A->GetHead();
      std::cout << "SELECT SOURCE:" << std::endl;
      for (int i = 1; X != NULL;++i) {
         std::cout << (i < 10 ? "0" : "") << i << ": " << X->GetData() << std::endl;
         X = X->GetNext();
      }
      std::cout << ">: "; std::cin >> x;

      if (x > A->GetSize() || x == 0) {
         std::cout << "INVALID SELECTION, PRESS ANY KEY TO TRY AGAIN!" << std::endl;
         std::cin.ignore(); getch();
      }
   } while (x > A->GetSize() || x == 0);

   do {
      system("CLS");
      if (A->GetSize() == 0) {
         std::cout << "SORRY, NO DATA AVAILABLE!" << std::endl
            << "PRESS ANY KEY TO GO BACK!" << std::endl;
         std::cin.ignore(); getch(); return;
      }

      Node<std::string>* Y = B->GetHead();
      std::cout << "SELECT DESTINATION:" << std::endl;
      for (int i = 1; Y != NULL;++i) {
         std::cout << (i < 10 ? "0" : "") << i << ": " << Y->GetData() << std::endl;
         Y = Y->GetNext();
      }
      std::cout << ">: "; std::cin >> y;

      if (y > B->GetSize() || y == 0) {
         std::cout << "INVALID SELECTION, PRESS ANY KEY TO TRY AGAIN!" << std::endl;
         std::cin.ignore(); getch();
      }
   } while (y > B->GetSize() || y == 0);

   Singly<Flight>* Data = GetFlightForRoute(x, y, A, B);
   delete A; delete B;
   do {
      this->DisplayAvailableFlights(Data);
      if (Data->GetSize() != 0) {
         std::cout << ">: "; std::cin >> z;
      }
      else {
         break;
      }

      if (z > Data->GetSize() || z == 0) {
         std::cout << "INVALID SELECTION, PRESS ANY KEY TO TRY AGAIN!" << std::endl;
         std::cin.ignore(); getch();
      }
   } while (z > Data->GetSize() || z == 0);

   if (Data->GetSize() == 0) return;

   Node<Flight>* Hold = Data->GetHead();
   Flight _Flight;
   for (int i = 1; i <= z; ++i) {
      if (i == z) _Flight = Hold->GetData();
      Hold = Hold->GetNext();
   }

   do {
      std::cout << "01: ECONOMY" << std::endl << "02: BUSINESS" << std::endl;
      std::cin >> z;

      if (z > 2 || z == 0) {
         std::cout << "INVALID SELECTION, PRESS ANY KEY TO TRY AGAIN!" << std::endl;
         std::cin.ignore(); getch();
      }
   } while (z > 2 || z == 0);

   _Flight.RegisterSeat(this->m_CurrentUser->GetData(), z == 1 ? ECONOMY : BUSINESS);
   this->m_CurrentUser->GetData().BookSeat(_Flight, z == 1 ? ECONOMY : BUSINESS);
}

void Init::UserBooking(Singly<Booking>* Obj) {
   system("CLS");
   Node<Booking>* Hold = Obj->GetHead();

   std::cout << std::left << "+" << std::setw(5) << std::setfill('-') << "+" << std::setw(16)
      << std::setfill('-') << "+" << std::setw(11) << std::setfill('-') << "+"
      << std::setw(15) << std::setfill('-') << "+" << std::setw(16) << std::setfill('-')
      << "+" << std::setw(13) << std::setfill('-') << "+" << std::setw(8) << std::setfill('-')
      << "+" << std::setw(12) << std::setfill('-') << "+" << std::setw(6) << std::setfill('-') << "+" << std::setw(12) << std::setfill('-') << "+" << std::endl << std::setfill(' ')
      << std::setw(6) << "| ## |" << std::setw(16) << "    AIRLINE    |"
      << std::setw(11) << " FLIGHT # |" << std::setw(15) << "    SOURCE    |"
      << std::setw(16) << "  DESTINATION  |" << std::setw(13) << "    DATE    |"
      << std::setw(8) << "  TIME |" << std::setw(12) << " SEAT TYPE |"
      << std::setw(6) << " S## |" << std::setw(12) << " TICKET # |" << std::endl
      << "+" << std::setw(5) << std::setfill('-') << "+" << std::setw(16)
      << std::setfill('-') << "+" << std::setw(11) << std::setfill('-') << "+"
      << std::setw(15) << std::setfill('-') << "+" << std::setw(16) << std::setfill('-')
      << "+" << std::setw(13) << std::setfill('-') << "+" << std::setw(8) << std::setfill('-')
      << "+" << std::setw(12) << std::setfill('-') << "+" << std::setw(6)
      << std::setfill('-') << "+" << std::setw(12) << std::setfill('-') << "+"
      << std::endl << std::setfill(' ');

   for (unsigned short INDEX = 0; INDEX < Obj->GetSize() && Hold != NULL; ) {
      if (Hold->GetData().Date.Day != 0) {
         std::cout << "|" << std::setw(++INDEX < 10 ? 2 : 1) << std::right
            << (INDEX < 10 ? "0" : "") << INDEX << " |";

         switch (Hold->GetData().Company) {
         case PIA:           std::cout << " PIA           | "; break;
         case QATAR_AIRWAYS: std::cout << " QATAR AIRWAYS | "; break;
         case ARAB_EMIRATES: std::cout << " ARAB EMIRATES | "; break;
         case AIR_BLUE:      std::cout << " AIR BLUE      | "; break;
         }

         std::cout << std::setw(9) << std::left << Hold->GetData().FlightNumber << "| "
            << std::setw(13) << Hold->GetData().Source << "| "
            << std::setw(14) << Hold->GetData().Destination << "| "
            << (Hold->GetData().Date.Day < 10 ? "0" : "") << Hold->GetData().Date.Day << "/"
            << (Hold->GetData().Date.Month < 10 ? "0" : "") << Hold->GetData().Date.Month << "/"
            << std::setw(2) << Hold->GetData().Date.Year << " | "
            << (Hold->GetData().Time.Hours < 10 ? "0" : "")
            << std::setw(Hold->GetData().Time.Hours < 10 ? 1 : 2)
            << Hold->GetData().Time.Hours << ":"
            << (Hold->GetData().Time.Minutes < 10 ? "0" : "")
            << std::setw(Hold->GetData().Time.Minutes < 10 ? 1 : 2)
            << Hold->GetData().Time.Minutes << " | ";

         switch (Hold->GetData().Type) {
         case BUSINESS: std::cout << " BUSINESS | "; break;
         case ECONOMY:  std::cout << " ECONOMY  | "; break;
         }

         std::cout << std::setw(3) << std::right << Hold->GetData().SeatNumber << " |"
            << std::setw(10) << Hold->GetData().TicketNumber << " |"
            << std::endl;
      }
      Hold = Hold->GetNext();
   }

   if (Obj->GetHead() != NULL) {
      std::cout << "+" << std::setw(5) << std::setfill('-') << "+" << std::setw(16)
         << std::setfill('-') << "+" << std::setw(11) << std::setfill('-') << "+"
         << std::setw(15) << std::setfill('-') << "+" << std::setw(16) << std::setfill('-')
         << "+" << std::setw(13) << std::setfill('-') << "+" << std::setw(8) << std::setfill('-')
         << "+" << std::setw(12) << std::setfill('-') << "+" << std::setw(6) << std::setfill('-')
         << "+" << std::setw(12) << std::setfill('-') << "+" << std::endl;
   }
   else {
      std::cout << std::setw(63) << std::right << "NO DATA AVAILABLE" << std::endl << std::left;
   }
}

void Init::PrintTicket(const unsigned short& Key) {
   SetConsoleTitle((LPCSTR)"Current Bookings | Airline Reservation System!"); system("CLS");
   Node<Booking>* Hold = this->m_CurrentUser->GetData().GetCurrentBookings()->GetHead();
   Booking Details; std::string K;
   for (int i = 1; i <= Key; ++i) {
      if (i == Key) Details = Hold->GetData();
      Hold = Hold->GetNext();
   }

   K = this->m_CurrentUser->GetData().GetFirstName() + " " + this->m_CurrentUser->GetData().GetLastName();
   std::cout << std::setfill(char(219)) << std::setw(104) << "\n" << char(219) << char(219)
      << std::setfill(' ') << std::setw(100) << char(219) << char(219) << "\n" << char(219)
      << char(219) << "    PASSENGER:  " << std::setw(26) << std::left << K;

   K = (this->m_CurrentUser->GetData().GetSex() == MALE ? "MALE" : "FEMALE");
   K = "SEX:  " + K; std::cout << std::setw(17) << K;

   K = "AGE:  " + (this->m_CurrentUser->GetData().GetAge() < 10 ? ("0" + std::to_string(this->m_CurrentUser->GetData().GetAge())) : std::to_string(this->m_CurrentUser->GetData().GetAge())) + " YEARS";
   std::cout << std::setw(20) << K;

   K = (Details.Type == ECONOMY ? "ECONOMY" : "BUSINESS"); K = "CLASS:  " + K;
   std::cout << std::setw(20) << K << char(219) << char(219) << std::endl << char(219) << char(219) << "      AIRLINE:  ";

   switch (Details.Company) {
   case PIA:           K = "PIA"; break;
   case QATAR_AIRWAYS: K = "QATAR AIRWAYS"; break;
   case ARAB_EMIRATES: K = "ARAB EMIRATES"; break;
   case AIR_BLUE:      K = "AIR BLUE"; break;
   }
   std::cout << std::setw(26) << K;

   K = "-" + std::to_string(Details.Date.Year);
   switch (Details.Date.Month) {
   case 1: K = "JAN" + K; break;
   case 2: K = "FEB" + K; break;
   case 3: K = "MAR" + K; break;
   case 4: K = "APR" + K; break;
   case 5: K = "MAY" + K; break;
   case 6: K = "JUN" + K; break;
   case 7: K = "JUL" + K; break;
   case 8: K = "AUG" + K; break;
   case 9: K = "SEP" + K; break;
   case 10: K = "OCT" + K; break;
   case 11: K = "NOV" + K; break;
   case 12: K = "DEC" + K; break;
   }
   K = (Details.Date.Day < 10 ? ("0" + std::to_string(Details.Date.Day)) : std::to_string(Details.Date.Day)) + +"-" + K;
   std::cout << "DATE:  " << std::setw(30) << K;

   K = ":" + (Details.Time.Minutes < 10 ? ("0" + std::to_string(Details.Time.Minutes)) : std::to_string(Details.Time.Minutes)) + "    ";
   K = (Details.Time.Hours < 10 ? ("0" + std::to_string(Details.Time.Hours)) : std::to_string(Details.Time.Hours)) + K;
   std::cout << "TIME:  " << std::setw(13) << K << char(219) << char(219) << std::endl << char(219) << char(219) << "       SOURCE:  " << std::setw(26) << Details.Source << "FLIGHT # " << std::setw(28) << Details.FlightNumber << "SEAT # ";

   K = (Details.SeatNumber < 10 ? ("00" + std::to_string(Details.SeatNumber)) : (Details.SeatNumber < 100 ? ("0" + std::to_string(Details.SeatNumber)) : std::to_string(Details.SeatNumber)));
   std::cout << std::setw(13) << K << char(219) << char(219) << std::endl << char(219) << char(219) << "  DESTINATION:  " << std::setw(26) << Details.Destination << "TICKET # " << std::setw(48) << std::to_string(Details.TicketNumber) << char(219) << char(219) << std::endl << std::right;

   std::cout << char(219) << char(219) << std::setfill(char(205)) << std::setw(100) << char(219) << char(219) << "\n";
   std::cout << char(219) << char(219) << "                               BE HAPPY & ENJOY THE JOURNEY WITH US!                               " << char(219) << char(219) << "\n";
   std::cout << char(219) << char(219) << std::setfill(' ') << std::setw(100) << char(219) << char(219) << "\n";
   std::cout << std::setfill(char(219)) << std::setw(104) << "\n";

   int Choice = 0;
   do {
      std::cout << "01: TO CANCEL" << std::endl << "02: TO GO BACK" << std::endl << ">: ";
      std::cin >> Choice;

      if (Choice > 3 || Choice == 0) {
         std::cout << "INVALID SELECTION, PRESS ANY KEY TO TRY AGAIN!" << std::endl;
         std::cin.ignore(); getch();
      }
      else if (Choice == 1) {
         this->m_CurrentUser->GetData().GetCurrentBookings()->DeleteFromPosition(Key - 1);
         std::cout << "CANCELED THE TICKET, PRESS ANY KEY TO GO BACK!" << std::endl;
         std::cin.ignore(); getch();
      }
   } while (Choice > 3 || Choice == 0);
}

void Init::CurrentBookings() {
   this->Refresh(false);
   SetConsoleTitle((LPCSTR)"Current Bookings | Airline Reservation System!");
   unsigned short x = 0;

   do {
      system("CLS");
      this->UserBooking(this->m_CurrentUser->GetData().GetCurrentBookings());

      if (this->m_CurrentUser->GetData().GetCurrentBookings()->GetHead() == NULL) {
         std::cout << "PRESS ANY KEY TO GO BACK!" << std::endl;
         std::cin.ignore(); getch(); return;
      }

      std::cout << ">: "; std::cin >> x;

      if (x > this->m_CurrentUser->GetData().GetCurrentBookings()->GetSize() || x == 0) {
         std::cout << "INVALID SELECTION, PRESS ANY KEY TO TRY AGAIN!" << std::endl;
         std::cin.ignore(); getch();
      }
   } while (x > this->m_CurrentUser->GetData().GetCurrentBookings()->GetSize() || x == 0);

   this->PrintTicket(x);
}

void Init::PreviousBookings() {
   this->Refresh(false);
   this->UserBooking(this->m_CurrentUser->GetData().GetPreviousBookings());
   std::cout << "PRESS ANY KEY TO GO BACK" << std::endl;
   std::cin.ignore(); getch();
}

void Init::Refresh(bool Toggle) {
   if (Toggle) {
      Node<Flight>* Hold = this->m_Flights->GetHead();
      Singly<Flight>* CurrentFlights = new Singly<Flight>();
      while (Hold != NULL) {
         if (Utilities::IsPrevious(Hold->GetData().GetDate(), Hold->GetData().GetTiming()))
            this->m_PreviousFlights->InsertAtStart(Hold->GetData());
         else CurrentFlights->InsertAtStart(Hold->GetData());
         Hold = Hold->GetNext();
      }

      this->m_Flights->Clear();
      this->m_Flights = CurrentFlights;
   }
   else {
      Node<Booking>* Hold = this->m_CurrentUser->GetData().GetCurrentBookings()->GetHead();
      Singly<Booking>* CurrentBookings = new Singly<Booking>();
      while (Hold != NULL) {
         if (Utilities::IsPrevious(Hold->GetData().Date, Hold->GetData().Time))
            this->m_CurrentUser->GetData().GetPreviousBookings()->InsertAtStart(Hold->GetData());
         else CurrentBookings->InsertAtStart(Hold->GetData());
         Hold = Hold->GetNext();
      }

      this->m_CurrentUser->GetData().GetCurrentBookings()->Clear();
      this->m_CurrentUser->GetData().SetCurrentBookings(CurrentBookings);
   }
}

int main() {
   Singly<User> Users;
   Users.InsertAtStart(User("Ali", "Raza", "AliRaza", "ali123", 22, PASSENGER, MALE));
   Users.InsertAtStart(User("Hyphen", "Saad", "HyphenSaad", "hyphen", 25, PASSENGER, FEMALE));
   Users.InsertAtStart(User("JK", "Rowling", "Admin", "jk", 23, ADMIN, FEMALE));

   Singly<Flight> AvailableFlights;
   AvailableFlights.InsertAtLast(Flight(ARAB_EMIRATES, INTERNATIONAL, "AE-7307", "DUBAI", "NEW YORK", Time(17, 15), Date(5, 11, 2020), 30, 70, 100, 150));
   AvailableFlights.InsertAtLast(Flight(PIA, LOCAL, "PK-404", "SIALKOT", "KARACHI", Time(11, 30), Date(15, 11, 2020), 20, 60, 35.0, 45.0));
   AvailableFlights.InsertAtLast(Flight(AIR_BLUE, INTERNATIONAL, "AB-5782", "LONDON", "CANDA", Time(1, 0), Date(15, 11, 2020), 10, 40, 35.0, 40.0));
   AvailableFlights.InsertAtLast(Flight(ARAB_EMIRATES, INTERNATIONAL, "AE-7307", "DUBAI", "NEW YORK", Time(17, 15), Date(15, 11, 2020), 30, 70, 30.0, 35.0));
   AvailableFlights.InsertAtLast(Flight(PIA, LOCAL, "PK-7307", "X", "Y", Time(17, 15), Date(10, 8, 2021), 30, 70, 30.0, 35.0));

   Singly<Flight> PreviousFlights;
   PreviousFlights.InsertAtLast(Flight(PIA, LOCAL, "PK-404", "LAHORE", "KARACHI", Time(15, 30), Date(5, 11, 2020), 20, 60, 35.0, 45.0));
   PreviousFlights.InsertAtLast(Flight(QATAR_AIRWAYS, INTERNATIONAL, "QA-5389", "SHARJA", "MUMBAI", Time(12, 45), Date(5, 11, 2020), 20, 60, 30.0, 40.0));

   Role CurrentUserRole;
   Init Application(&Users, &AvailableFlights, &PreviousFlights);
   int Response = 0;
   while (true) {
      if (Response == 0) Response = Application.StartScreen();

      if (Response == 1) {
         Response = Application.LoginScreen();
         if (Response == 0) { Response = 0; continue; }
         else if (Response == 1) (CurrentUserRole = ADMIN, Response = 99);
         else if (Response == 2) (CurrentUserRole = PASSENGER, Response = 98);
      }

      if (CurrentUserRole == ADMIN && Response == 99) {
         Response = Application.AdminScreen();
         if (Response == 1) Application.CreateFlightScreen();
         else if (Response == 2) Application.DeleteFlightScreen();
         else if (Response == 3) Application.UpdateFlightScreen();
         else if (Response == 4) Application.DisplayFlightsScreen(true, "Available Flights | Airline Reservation System");
         else if (Response == 5) Application.DisplayFlightsScreen(false, "Previous Flights | Airline Reservation System");
         else if (Response == 6) { Response = 0; continue; }
         Response = 99;
      }
      else if (CurrentUserRole == PASSENGER && Response == 98) {
         Response = Application.PassengerScreen();
         if (Response == 1) Application.MakeReservation();
         else if (Response == 2) Application.CurrentBookings();
         else if (Response == 3) Application.PreviousBookings();
         else if (Response == 4) { Response = 0; continue; }
         Response = 98;
      }
   }
   return 0;
}