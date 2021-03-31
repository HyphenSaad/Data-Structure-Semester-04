// DSA-LAB-ASSIGNMENT-01
// STUDNET - NAME: Saad Mansoor
// SAP-ID:       70075954
// COURSE:       Data Structures & Algorithms
// DATED:        March 24, 2021 - Wednesday
// BSCS-4/C1 - Department of Computer Science & Information Technology
// University of Lahore, Gujrat Campus

#include <iostream>
#include <algorithm>

namespace Saadin {
   class Array {
   private:
      int* m_Data;  // TO POINT TO THE DYNAMICALLY CREATED ARRAY ON HEAP
      int m_Length; // TO KEEP TRACK OF USED MEMORY BLOCKS
      int m_Size;   // TO STORE THE SIZE OF WHOLE ARRAY

   public:
      Array(const int&);

      void InsertInSequence();
      void InsertAtStart(const int&);
      void InsertAtLast(const int&);
      void InsertAtPosition(const int&, const int&);

      void DeleteFromStart();
      void DeleteFromEnd();
      void DeleteFromPosition(const int&);

      bool Search(const int&);
      void Sort(bool);
      void Display();
      int GetSize() const;
      int GetLength() const;
   };
}

int main() {
   Saadin::Array XYZ(5);
   XYZ.InsertAtPosition(10, 0);
   XYZ.InsertAtPosition(20, 1);
   XYZ.InsertAtPosition(30, 2);
   XYZ.InsertAtPosition(50, 4);
   XYZ.InsertAtStart(60);
   XYZ.InsertAtLast(100);
   XYZ.Display();
   XYZ.Sort(0);
   XYZ.Display();

   system("PAUSE");
   return EXIT_SUCCESS;
}

// CONSTRUCTOR:
// - ARGUMENTS: {Size (type: integer)(required: true)}
// - Using List Initializer, I initialized;
//   [m_Length] -> [0] which we will increment are decrement in future,
//              just to keep track of used memory blocks
//   [m_Size] -> [Size] which will help us to dynamically allocate memory 
//   [m_Data] -> [new int[Size]]
//               - Create a dynamic array of intergers of [Size]
//               - Stored address
// - TRAVERSAL: In order to avoid garbagge values and unknown behaviours,
//              I just initialized each block of dynamic array with [0]
Saadin::Array::Array(const int& Size) : m_Length(0), m_Size(Size), m_Data(new int[Size]) {
   for (int i = 0;i < this->m_Size;++i)
      this->m_Data[i] = 0;
}

// FUNCTION: InsertInSequence
// - ARGUMENTS: None
// - RETURN: void
// - TRAVERSAL: Prompted user to enter value for each index of dynamic array
void Saadin::Array::InsertInSequence() {
   for (int i = 0; i < this->m_Size; ++i) {
      std::cout << "value @index[" << i << "]:\t";
      std::cin >> this->m_Data[i];
   }
}

// FUNCTION: InsertAtStart
// - ARGUMENTS: {Value (type: integer)(required: true)}
// - RETURN: void
// - GUARD-CLAUSE: Just to prevent insertion in fulled array.
//                 It's bypass-able using InsertAtPosition() method.
// - CHUNK-01:
//   - Allocated dynamic memory just to dump the actual dynamic array's values
//   - Traversed over each index and copied all the values to the [Bin] array
//   - Here, I did a little performance tweak that will help us to reduce complexity
//   - So, if on any index we found zero we will append [0] in [Bin] and break the loop
//   - Reason why i looped till [this->m_Size - 1] because there has to be one memory
//     block availiable for insertion through this method
// - CHUNK-02:
//   - As we have already dumped our main array, we can overwrite its content
//   - Just inserted the value to FIRST_INDEX
//   - Traversed through the main array, till we not found any [0] in the [Bin]
//   - Once [0] is found loop will be terminated, again a performance tweak here
//   - Reason, i started loop from [1] instead of [0], because we already achieved
//     we want to do with INDEX[0]
// - CHUNK-03:
//   - Deleted the dynamically allocated [Array]
//   - Incremented the [m_Length] by 1
void Saadin::Array::InsertAtStart(const int& Value) {
   if (this->m_Length == this->m_Size) {
      std::cout << "No Availiable Space in Array!" << std::endl;
      return;
   }

   int* Bin = new int[this->m_Size - 1];
   for (int i = 0; i < this->m_Size - 1;++i)
      Bin[i] = (this->m_Data[i] != 0) ? this->m_Data[i] : 0;

   this->m_Data[0] = Value;
   for (int i = 1, j = 0; i < this->m_Size;++i)
      if (Bin[j] != 0) this->m_Data[i] = Bin[j++];
      else break;

   delete[] Bin;
   ++(this->m_Length);
}

// FUNCTION: InsertAtLast
// - ARGUMENTS: {Value (type: integer)(required: true)}
// - RETURN: void
// - GUARD-CLAUSE: Just to prevent insertion in fulled array.
//                 It's bypass-able using InsertAtPosition() method.
// - CHUNK-01 & CHUNK-02: Same as of InsertAtStart(), but in reverse order.
// - CHUNK-03: Same as of InsertAtStart()
void Saadin::Array::InsertAtLast(const int& Value) {
   if (this->m_Length == this->m_Size) {
      std::cout << "No Availiable Space in Array!" << std::endl;
      return;
   }

   int* Bin = new int[this->m_Size - 1];
   for (int i = this->m_Size - 1; i > 1;--i)
      Bin[i] = (this->m_Data[i] != 0) ? this->m_Data[i] : 0;

   this->m_Data[this->m_Size - 1] = Value;
   for (int i = 1, j = this->m_Size - 1; i < this->m_Size;++i)
      if (Bin[j] != 0) this->m_Data[i] = Bin[j--];
      else break;

   delete[] Bin;
   ++(this->m_Length);
}

// FUNCTION: InsertAtPosition
// - ARGUMENTS: {Value (type: integer)(required: true)},
//              {Position (type: integer)(required: true)}
// - RETURN: void
// - GUARD-CLAUSE: Just to handle invalid positions
// - CHUNK-01:
//   - If, position is valid then value will be added to that position
//   - After that [m_Length] will be incremented by 1.
void Saadin::Array::InsertAtPosition(const int& Value, const int& Position) {
   if (Position < 0 || Position > this->m_Size) {
      std::cout << "Invalid Position!" << std::endl;
      return;
   }

   this->m_Data[Position] = Value;
   ++(this->m_Length);
}

// FUNCTION: DeleteFromStart
// - ARGUMENTS: None
// - RETURN: void
// - Updated FIRST_INDEX with [0] and decremented [m_Length] by 1
void Saadin::Array::DeleteFromStart() {
   this->m_Data[0] = 0;
   --(this->m_Length);
}

// FUNCTION: DeleteFromEnd
// - ARGUMENTS: None
// - RETURN: void
// - Updated LAST_INDEX (which we can obtain by substracing 1 from [m_Size]) with [0]
//   and decremented [m_Length] by 1
void Saadin::Array::DeleteFromEnd() {
   this->m_Data[this->m_Size - 1] = 0;
   --(this->m_Length);
}

// FUNCTION: DeleteFromEnd
// - ARGUMENTS: None
// - RETURN: void
// - GUARD-CLAUSE: Just to handle invalid positions
// - If, position is valid we will move to that INDEX and set it to [0]
//   and decrement the [m_Length] by 1
void Saadin::Array::DeleteFromPosition(const int& Position) {
   if (Position < 0 || Position > this->m_Size) {
      std::cout << "Invalid Position!" << std::endl;
      return;
   }

   this->m_Data[Position] = 0;
   --(this->m_Length);
}

// FUNCTION: Search
// - ARGUMENTS: {Value (type: integer)(required: true)}
// - RETURN: boolean
// - TRAVERSAL:
//   - Will loop over whole array
//   - as we will found the value, we will return the TRUE from function
//   - which wll ultimately terminate the further loop execution in that scope
// - Retured FALSE as a fallback, in case [Value] did'nt match with existing values
bool Saadin::Array::Search(const int& Value) {
   for (int i = 0; i < this->m_Size; ++i)
      if (this->m_Data[i] == Value) return true;
   return false;
}

// FUNCTION: Sort
// - ARGUMENTS: {Ascending (type: boolean)(required: true)}
// - RETURN: void
// - [Ascending] == TRUE : will sort the array in Ascending-Order
// - [Ascending] == FALSE : will sort the array in Descending-Order
// - Used C++ STL to Sort the array [it's handy and very-well optimized]
void Saadin::Array::Sort(bool Ascending) {
   Ascending
      ? std::sort(this->m_Data, this->m_Data + this->m_Size)
      : std::sort(this->m_Data, this->m_Data + this->m_Size, std::greater<int>());
}

// FUNCTION: Display
// - ARGUMENTS: NONE
// - RETURN: void
// - TRAVERSAL: Just to loop-through each index and display its value on console
void Saadin::Array::Display() {
   for (int i = 0;i < this->m_Size;++i)
      std::cout << "@index[" << i << "]\t" << this->m_Data[i] << std::endl;
}

// FUNCTION: GetSize
// - ARGUMENTS: NONE
// - RETURN: integer
int Saadin::Array::GetSize() const {
   return this->m_Size;
}

// FUNCTION: GetLength
// - ARGUMENTS: NONE
// - RETURN: integer
int Saadin::Array::GetLength() const {
   return this->m_Length;
}