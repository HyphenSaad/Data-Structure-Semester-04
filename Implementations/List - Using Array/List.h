#ifndef HYPHEN_LIST
#define HYPHEN_LIST

namespace Hyphen {
   class List {
   private:
      int* m_List = nullptr;
      int m_Length = 0;

   public:
      void CreateList();
      bool Copy(const List*);
      void Clear();
      void Insert(const int&, const int&);
      void Remove(const int&);
      int Get(const int&) const;
      void Update(const int&, const int&);
      bool Find(const int&) const;
      int Length() const;

      void Start();
      void Tail();
      void Next();
      void Back();

   private:
      bool m_ShowLogs;
   public:
      void ShowLogs(bool);
      void Display() const;
   };
}

#endif