#include <iostream>
#include <queue>

using namespace std;

class Node
{
    public:
    int data;
    Node* left;
    Node* right;
};

Node* GetNode(int data)
{
    Node* newNode = new Node();
    newNode->data = data;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

void Insert(Node** root, int data)
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

Node* FindMin(Node* root)
{
	while(root->left != NULL) root = root->left;
	return root;
}

Node* Delete(Node* root, int data)
{
    if (root == nullptr) return root;
    else if (root->data < data) return Delete(root->left, data);
    else if (root->data > data) return Delete(root->right, data);
    else //(root == value)
    {
        //case 1: node has no child
        if ((root->left == nullptr) && (root->right == nullptr))
        {
            delete root;
            root = nullptr;
            return root;
        }

        //case 2.1: node has 1 left child
        else if (root->right == nullptr)
        {
            Node* temp = root;
            root = root->left;
            delete temp;
            return root;
        }

        //case 2.2: node has 1 right child
        else if (root->left == nullptr)
        {
            Node* temp = root;
            root = root->right;
            delete temp;
            return root;
        }   

        else 
        {
            Node* temp = FindMin(root->right);
            root->data = temp->data;
            root->right = Delete(root->right, temp->data);
            return root;
        }
    }
}

void Search(Node* root, int data)
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

int main()
{
    Node* root = nullptr;
    Insert(&root, 1);
    Insert(&root, 4);
    Insert(&root, 6);
    Insert(&root, 7);
    Insert(&root, 102);
    Insert(&root, 52);
    Insert(&root, 23);
    Insert(&root, 531);
    Insert(&root, 63);
    Insert(&root, 85);

    Search(root, 102);
    root = Delete(root, 102);
    Search(root, 102);

}