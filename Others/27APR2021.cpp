#include <iostream>
#include <conio.h>

class Array {
private:
   int* m_Array;
   unsigned int m_Size;
   unsigned int m_Used;
   bool INVALID;

public:
   Array(const unsigned int&);
   ~Array();

   void InsertInSequence();
   void InsertAtHead(const int&);
   void InsertAtIndex(const int&, const unsigned int&);

   void DeleteFromStart();
   void DeleteFromLast();
   void DeleteFromIndex(const unsigned int&);

   void ResetArray();
   bool Search(const int&);
   void Display();
   int NumberOfIndexesUsed();
   int ShowFreeIndexes();
};

int main() {
   unsigned int Size = 0;
   std::cout << " > Enter Array Size:\t";
   std::cin >> Size;
   Array* Data = new Array(Size);

   while (true) {
      unsigned int Option = 0;
      int Value = 0, Index = 0;
      std::cout
         << " > 01: Insert In Sequence" << std::endl
         << " > 02: Insert At Head" << std::endl
         << " > 03: Insert At Index" << std::endl
         << " > 04: Delete From Start" << std::endl
         << " > 05: Delete From Last" << std::endl
         << " > 06: Delete From Index" << std::endl
         << " > 07: Reset Array" << std::endl
         << " > 08: Search From Array" << std::endl
         << " > 09: Display Array" << std::endl
         << " > 10: Show Number Of Used Indexes" << std::endl
         << " > 11: Show Number Of Free Indexes" << std::endl
         << " > 00: Exit" << std::endl
         << " > SELECTION:\t";
      std::cin >> Option;

      switch (Option) {
      case 1:
         Data->InsertInSequence();
         break;
      case 2:
         std::cout << " > Enter Value:\t";
         std::cin >> Value;
         Data->InsertAtHead(Value);
         break;
      case 3:
         std::cout << " > Enter Value:\t";
         std::cin >> Value;
         std::cout << " > Enter Index:\t";
         std::cin >> Index;
         Data->InsertAtIndex(Value, Index);
         break;
      case 4:
         Data->DeleteFromStart();
         std::cout << " > Press Any Key To Continue! ";
         getch();
         break;
      case 5:
         Data->DeleteFromLast();
         std::cout << " > Press Any Key To Continue! ";
         getch();
         break;
      case 6:
         std::cout << " > Enter Index:\t";
         std::cin >> Index;
         Data->DeleteFromIndex(Index);
         std::cout << " > Press Any Key To Continue! ";
         getch();
         break;
      case 7:
         Data->ResetArray();
         std::cout << " > Press Any Key To Continue! ";
         getch();
         break;
      case 8:
         std::cout << " > Enter Value:\t";
         std::cin >> Value;
         std::cout << " > Value Found:\t" << (Data->Search(Value) ? "True" : "False") << std::endl;
         std::cout << " > Press Any Key To Continue! ";
         getch();
         break;
      case 9:
         Data->Display();
         std::cout << " > Press Any Key To Continue! ";
         getch();
         break;
      case 10:
         std::cout << " > Used Indexes:\t" << Data->NumberOfIndexesUsed() << std::endl;
         std::cout << " > Press Any Key To Continue! ";
         getch();
         break;
      case 11:
         std::cout << " > Free Indexes:\t" << Data->ShowFreeIndexes() << std::endl;
         std::cout << " > Press Any Key To Continue! ";
         getch();
         break;
      case 0:
         delete Data;
         break;
      default:
         std::cout << " > Invalid Selection, Try Again!" << std::endl;
         std::cout << " > Press Any Key To Continue! ";
         getch();
      }
      system("CLS");
   }
   return 0;
}

Array::Array(const unsigned int& Size) {
   this->INVALID = Size == 0;
   this->m_Size = Size;
   this->m_Used = 0;
   this->m_Array = new int[this->m_Size];
   for (int i = 0; i < this->m_Size; ++i) this->m_Array[i] = 0;
}

Array::~Array() {
   delete[]m_Array;
}

void Array::InsertInSequence() {
   if (INVALID) return;
   for (int i = 0; i < this->m_Size; ++i) {
      std::cout << " > Enter Value For Index " << i << ":\t";
      std::cin >> this->m_Array[i];
      ++(this->m_Used);
   }
}

void Array::InsertAtHead(const int& Data) {
   if (INVALID) return;
   this->m_Array[0] = Data;
   ++(this->m_Used);
}

void Array::InsertAtIndex(const int& Data, const unsigned int& Index) {
   if (INVALID || Index >= this->m_Size) return;
   this->m_Array[Index] = Data;
   ++(this->m_Used);
}

void Array::DeleteFromStart() {
   if (INVALID || this->m_Used == 0) return;
   this->m_Array[0] = 0;
   --(this->m_Used);
}

void Array::DeleteFromLast() {
   if (INVALID || this->m_Used == 0) return;
   this->m_Array[this->m_Size - 1] = 0;
   --(this->m_Used);
}

void Array::DeleteFromIndex(const unsigned int& Index) {
   if (INVALID || this->m_Used == 0 || Index >= this->m_Size) return;
   this->m_Array[Index] = 0;
   --(this->m_Used);
}

void Array::ResetArray() {
   if (INVALID) return;
   for (int i = 0; i < this->m_Size; ++i) this->m_Array[i] = 0;
}

bool Array::Search(const int& Data) {
   if (INVALID) return false;
   for (int i = 0; i < this->m_Size; ++i) if (this->m_Array[i] == Data) return true;
   return false;
}

void Array::Display() {
   if (INVALID) return;
   for (int i = 0; i < this->m_Size; ++i)
      std::cout << " > @index[" << i << "]:\t" << this->m_Array[i] << std::endl;
}

int Array::NumberOfIndexesUsed() {
   return this->m_Used;
}

int Array::ShowFreeIndexes() {
   return this->m_Size - this->m_Used;
}