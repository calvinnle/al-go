#include <iostream>
#include <queue>

using namespace std;

class Node
{
public:
    char data;
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

void Search(Node* root, char data)
{
    if (root == nullptr)
    {
        cout << "it's not here guys." << endl;
    }

    else if (root->data == data)
    {
        cout << "it's here." << endl;
    }

    else if (root->data > data)
    {
        Search(root->left, data);
    }
    else Search(root->right, data);
}

void BFS(Node* root)
{
    if (root == nullptr) return;
    queue<Node*> q;
    q.push(root);
    //While there is at least 1 discovered node
    while (!q.empty())
    {
        Node* current = q.front();
        cout << current->data << " ";
        if (current->left != nullptr) q.push(current->left);
        if (current->right != nullptr) q.push(current->right);
        q.pop();
    }
}

void Preorder(Node* root)
{   
    if (root == nullptr) return;
    cout << root->data << " ";
    Preorder(root->left);
    Preorder(root->right);
}

void Inorder(Node* root)
{
    if (root == nullptr) return;
    Inorder(root->left);
    cout << root->data << " ";
    Inorder(root->right);
}

void Postorder(Node* root)
{   
    if (root == nullptr) return;
    Postorder(root->left);
    Postorder(root->right);
    cout << root->data << " ";
}

//Time complexity: O(n)
//Space complexity: 0(h) where h is the height of the tree.
                    //Worst case: O(n-1) edges
                    //Best case: O(logn)

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

    BFS(root); cout << endl;         //F D J B E G K A C I
    Preorder(root); cout << endl;    //F D B A C E J G I K
    Inorder(root); cout << endl;     //A B C D E F G I J K
    Postorder(root); cout << endl;   //A C B E D I G K J F
}