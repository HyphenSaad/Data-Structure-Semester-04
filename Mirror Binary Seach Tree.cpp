#include <iostream>

class Node
{
public:
   int m_Data;
   Node* m_Left, * m_Right;

   Node(const int&);

   Node* GetRight() const;
   Node* GetLeft() const;
   int GetData() const;

   void SetRight(Node*);
   void SetLeft(Node*);
};

Node::Node(const int& Data) {
   this->m_Data = Data;
   this->m_Left = NULL;
   this->m_Right = NULL;
}

Node* Node::GetRight() const { return this->m_Right; }
Node* Node::GetLeft() const { return this->m_Left; }
int Node::GetData() const { return this->m_Data; }
void Node::SetRight(Node* R) { this->m_Right = R; }
void Node::SetLeft(Node* L) { this->m_Left = L; }

void MirrorTree(Node* Root) {
   if (Root == NULL) return;

   Node* Left = Root->GetLeft();
   Node* Right = Root->GetRight();

   Root->SetLeft(Right);
   Root->SetRight(Left);

   MirrorTree(Right);
   MirrorTree(Left);
}

#define x(x) new Node(x)

void printPreorder(Node* node)
{
   if (node == NULL)
      return;

   /* first print data of node */
   std::cout << node->GetData() << " ";

   /* then recur on left sutree */
   printPreorder(node->GetLeft());

   /* now recur on right subtree */
   printPreorder(node->GetRight());
}

int main() {
   Node* Tree = x(6);
   Tree->SetLeft(x(3));
   Tree->SetRight(x(8));
   Tree->GetLeft()->SetRight(x(2));
   Tree->GetRight()->SetLeft(x(7));
   Tree->GetRight()->SetRight(x(9));

   printPreorder(Tree);
   std::cout << std::endl;
   MirrorTree(Tree);
   printPreorder(Tree);

   system("PAUSE");
   return 0;
}