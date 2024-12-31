#include <iostream>

using namespace std;

class Node
{
    public:
    int data;
    Node* left;
    Node* right;
};

Node* GetNode(char data)
{
    Node* newNode = new Node();
    newNode->data = data;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

void Insert(Node** root, char data)
{
    if (*root == nullptr)
    {
        *root = GetNode(data);
        return;
    }

    else if (data <= (*root)->data)
    {
        Insert(&((*root)->left), data);
    }
    else
    {
        Insert(&((*root)->right), data);
    }
}

bool IsSubtreeLesser(Node* root, int value)
{
    if (root == nullptr) return true;
    if (root->data <= value
    &&  IsSubtreeLesser(root->left, value)
    &&  IsSubtreeLesser(root->right, value))
    {
        return true;
    }
    else return false;
}

bool IsSubtreeGreater(Node* root, int value)
{
    if (root == nullptr) return true;
    if (root->data > value
    &&  IsSubtreeGreater(root->left, value)
    &&  IsSubtreeGreater(root->right, value))
    {
        return true;
    }
    else return false;
}


bool IsBST(Node* root)
{
    if (root == nullptr) return true;
    if (IsSubtreeLesser(root->left, root->data)
    &&  IsSubtreeGreater(root->right, root->data)
    &&  IsBST(root->left)
    &&  IsBST(root->right))
    {
        return true;
    }
    else 
    {
        return false;
    }
}


int main()
{
    Node* root = nullptr;
    Insert(&root, 'F');
    Insert(&root, 'D');
    Insert(&root, 'J');
    Insert(&root, 'B');
    Insert(&root, 'E');
    Insert(&root, 'G');
    Insert(&root, 'K');
    Insert(&root, 'A');
    Insert(&root, 'C');
    Insert(&root, 'I');

    int a = IsBST(root);
    cout << a << endl;
}