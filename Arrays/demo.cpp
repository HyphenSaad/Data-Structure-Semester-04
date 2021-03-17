#include <iostream>
#define ADD_SPACE std::cout << std::endl << std::endl
///////////////////////////////////////////////////////////////////////////////////////////
class Array {
private:
   int* m_Data;
   int m_Size;
public:
   // Constructors / CREATION
   Array(const int&);
   Array(const int&, const int&);

   // INSERTION / SETTERS
   void Insert(const int&, const int&);
   void InsertFirst(const int&);
   void InsertLast(const int&);

   // DELETION
   void Delete(const int&);

   // GETTERS
   int Get(const int&) const;
   int GetFirst() const;
   int GetLast() const;
   int GetSize() const;

   // UTILITIES
   void Extend(const int&);
   void Concat(const Array*);
   void Concat(const int*, const int& Size);
   bool Search(const int&);
   void Display() const;
   int GreatestValue() const;
   int SmallestValue() const;
   bool SelectionSort() const;
private:
   void Prepare(const int&, const int&);
};
///////////////////////////////////////////////////////////////////////////////////////////
void Array::Prepare(const int& Size, const int& Value) {
   // WROTE THAT FUNCTION TO AVOID CODE REPEATION IN CONSTRUCTORS
   this->m_Size = Size;
   // TO GET THE MEMORY DYNAMICALLY ON THE HEAP
   this->m_Data = new int[this->m_Size];
   // TO JUST INITIALZE THE OBTAINED MEMORY WITH SOME VALUE TO AVOID THE [GARBAGGE VALUE]
   // LOOP WILL TRAVERSE ON OBTAINED CHUNK OF MEMORY, [BLOCK-BY-BLOCK]
   for (int i = 0; i < this->m_Size;++i) {
      this->m_Data[i] = Value; // YOU CAN SET VALUE AS YOU LIKE
   }
}
///////////////////////////////////////////////////////////////////////////////////////////
Array::Array(const int& Size) {
   this->Prepare(Size, 0);
}

Array::Array(const int& Size, const int& Initialize) {
   this->Prepare(Size, Initialize);
}
///////////////////////////////////////////////////////////////////////////////////////////
void Array::Insert(const int& Data, const int& Position) {
   // JUST A [GUARD-CLAUSE] TO HANDLE INVALID POSITIONS/INDEXES
   // POSITION/INDES SHOULD BE [POSITIVE] AND [LESS THAN ARRAY SIZE]
   // BECAUSE ARRAY INDEX IS ALWAYS [ARRAY_SIZE - 1]
   if (Position < 0 || Position > this->m_Size) {
      std::cout << "Invalid Position!" << std::endl;
      return; // MAY REQUIRE C++11
   }

   this->m_Data[Position] = Data;
}

void Array::InsertFirst(const int& Data) {
   this->m_Data[0] = Data;
}

void Array::InsertLast(const int& Data) {
   this->m_Data[this->m_Size - 1] = Data;
}
///////////////////////////////////////////////////////////////////////////////////////////
void Array::Delete(const int& Position) {
   // JUST A [GUARD-CLAUSE] TO HANDLE INVALID POSITIONS/INDEXES
   // POSITION/INDES SHOULD BE [POSITIVE] AND [LESS THAN ARRAY SIZE]
   // BECAUSE ARRAY INDEX IS ALWAYS [ARRAY_SIZE - 1]
   if (Position < 0 || Position > this->m_Size) {
      std::cout << "Invalid Position!" << std::endl;
      return;
   }

   // AS WE HAVE DYNAMICALLY ALLCOCATED THE MEMORY FOR OUT ARRAY
   // WE CAN SHRINK IT, BUT IT MAY BREAK THE CODE [BECAUSE OF CHANGE IN SIZE]
   // THAT'S WHY I JUST UPDATED IT WITH 0
   this->m_Data[Position] = 0;
}
///////////////////////////////////////////////////////////////////////////////////////////
int Array::Get(const int& Position) const {
   // JUST A [GUARD-CLAUSE] TO HANDLE INVALID POSITIONS/INDEXES
   // POSITION/INDES SHOULD BE [POSITIVE] AND [LESS THAN ARRAY SIZE]
   // BECAUSE ARRAY INDEX IS ALWAYS [ARRAY_SIZE - 1]
   if (Position < 0 || Position > this->m_Size) {
      std::cout << "Invalid Position!" << std::endl;
      return 0;
   }

   return this->m_Data[Position];
}

int Array::GetFirst() const {
   return this->m_Data[0];
}

int Array::GetLast() const {
   return this->m_Data[this->m_Size - 1];
}

int Array::GetSize() const {
   return this->m_Size;
}
///////////////////////////////////////////////////////////////////////////////////////////
void Array::Extend(const int& Size) {
   // TO HOLD THE CURRENT SIZE [JUST IN THAT SCOPE]
   int OldSize = this->m_Size;
   // TO UPDATE & VALIDATE THE EXTEND_SIZE
   this->m_Size = Size > 0 ? (this->m_Size + Size) : this->m_Size;
   // if (Size > 0) {
   //    this->m_Size = this->m_Size + Size;
   // }
   // else {
   //    this->m_Size = this->m_Size;
   // }

   // OBTAINED NEW DYNAMIC MEMORY, BUT THIS TIME ALLOCATION IS AS PER EXTEND_SIZE
   int* NewArray = new int[this->m_Size];

   for (int i = 0; i < this->m_Size;++i) {
      NewArray[i] = i < OldSize ? this->m_Data[i] : 0;
      // if (i < OldSize) {
      //    NewArray[i] = this->m_Data[i];
      // }
      // else {
      //    NewArray[i] = 0;
      // }
   }
   // TO FREE THE OLD MEMORY OBTAINED ON HEAP
   delete[] m_Data;
   // TO SAVE THE POINTER TO NEWLY/EXTENDED MEMORY ON THE HEAP
   this->m_Data = NewArray;
}

void Array::Display() const {
   for (int i = 0; i < this->m_Size;++i) {
      std::cout << "@index[" << i << "]\t" << this->m_Data[i] << std::endl;
   }
}

void Array::Concat(const Array* Obj) {
   this->Extend(Obj->m_Size);
   // TO COPY GIVEN ARRAY
   for (int i = Obj->m_Size + 1, j = 0; i < this->m_Size; i++, j++) {
      this->m_Data[i] = Obj->m_Data[j];
   }
}

void Array::Concat(const int* Array, const int& Size) {
   this->Extend(Size);
   // TO COPY GIVEN ARRAY
   // i = to control the index main array
   // j = to control the index of given array
   for (int i = Size, j = 0; i < this->m_Size; i++, j++) {
      this->m_Data[i] = Array[j];
   }
}

bool Array::Search(const int& Value) {
   // LINEAR SEARCH
   for (int i = 0; i < this->m_Size;++i) {
      if (this->m_Data[i] == Value) {
         return true;
      }
   }
   return false;
}
///////////////////////////////////////////////////////////////////////////////////////////
int Array::GreatestValue() const {
   int Hold = this->m_Data[0]; // SUPPOSED
   for (int i = 1; i < this->m_Size; ++i) {
      if (Hold > this->m_Data[i]) {
         Hold = this->m_Data[i];
      }
   }
   return Hold;
}

int Array::SmallestValue() const {
   int Hold = this->m_Data[0]; // SUPPOSED
   for (int i = 1; i < this->m_Size; ++i) {
      if (Hold < this->m_Data[i]) {
         Hold = this->m_Data[i];
      }
   }
   return Hold;
}
bool Array::SelectionSort() const {
   // LATER xD
}
///////////////////////////////////////////////////////////////////////////////////////////
int main() {
   Array Data(5, 11);
   // Array Test(4, 45);
   int Num[5] = { 1,2,3,4,5 };
   Data.Concat(Num, 5);
   // Data.Concat(&Test);
   Data.Display();
   // Data.Insert(152, 0);
   // Data.Insert(652, 2);
   // ADD_SPACE;
   // Data.Display();
   // ADD_SPACE;
   // Data.Extend(5);
   // Data.Display();

   system("PAUSE");
   return EXIT_SUCCESS;
}