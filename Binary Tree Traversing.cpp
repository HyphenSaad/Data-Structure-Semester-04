#include <iostream>
#include <queue>
using namespace std;

struct Node
{
   int data;
   struct Node* l, * r;
   Node(int data)
   {
      this->data = data;
      l = r = NULL;
   }
};


void printPostorder(struct Node* node)
{
   if (node == NULL)
      return;

   // first recur on left subtree
   printPostorder(node->l);

   // then recur on right subtree
   printPostorder(node->r);

   // now deal with the node
   cout << node->data << " ";
}

void printInorder(struct Node* node)
{
   if (node == NULL)
      return;

   /* first recur on left child */
   printInorder(node->l);

   /* then print the data of node */
   cout << node->data << " ";

   /* now recur on right child */
   printInorder(node->r);
}

void printPreorder(struct Node* node)
{
   if (node == NULL)
      return;

   /* first print data of node */
   cout << node->data << " ";

   /* then recur on left sutree */
   printPreorder(node->l);

   /* now recur on right subtree */
   printPreorder(node->r);
}

void printLevelOrder(struct Node* node)
{
   // Base Case
   if (node == NULL)  return;

   // Create an empty queue for level order traversal
   queue<Node*> q;

   // Enqueue Root and initialize height
   q.push(node);

   while (q.empty() == false)
   {
      // Print front of queue and remove it from queue
      Node* n = q.front();
      cout << n->data << " ";
      q.pop();

      /* Enqueue left child */
      if (n->l != NULL)
         q.push(n->l);

      /*Enqueue right child */
      if (n->r != NULL)
         q.push(node->r);
   }
}

#define x(x) new Node(x)

int main()
{
   // LEVEL - 1
   struct Node* root = x(4);
   // LEVEL - 2
   root->l = x(2);
   root->r = x(6);
   // LEVEL - 3
   root->l->l = x(1);
   root->l->r = x(3);
   root->r->l = x(5);
   root->r->r = x(7);

   cout << "Pre-Order:\t";
   printPreorder(root);
   cout << "\n\nIn-Order:\t";
   printInorder(root);
   cout << "\n\nPost-Order:\t";
   printPostorder(root);
   // cout << "\n\nLevel-Order:\t";
   // printLevelOrder(root);
   cout << "\n\n";
   system("PAUSE");
   return 0;
}
