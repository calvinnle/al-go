#include <iostream>
#include <chrono>
#include <thread>

using namespace std;

class Node
{
public:
    int data;
    Node* left;
    Node* right;
};

Node* GetNewNode(int data)
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
        *root = GetNewNode(data);
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


void SearchFor(Node* root, int data)
{
    if (root == nullptr)
    {
        cout << "not found" << endl;
    }

    else if (data == root->data)
    {
        cout << "exists." << endl;
    }

    else if (data <= root->data) 
    {
        SearchFor(root->left, data);
    }

    else SearchFor(root->right, data);
}

void FindMax(Node* root)
{
    if (root == nullptr)
    {
        cout << "tree is empty" << endl;
    }

    if (root->right == nullptr)
    {
        cout << "The max value of the tree is: " << root->data << endl;
    }

    else 
    {
        FindMax(root->right);
    }
}

void FindMin(Node* root)
{
    if (root == nullptr)
    {
        cout << "tree is empty" << endl;
    }

    if (root->left == nullptr)
    {
        cout << "The min value of the tree is: " << root->data << endl;
    }

    else 
    {
        FindMin(root->left);
    }
}

int main()
{
    Node* root = nullptr;
    int number_of_element, value;
    cout << "How many elements do you want to insert in the tree: ";
    cin >> number_of_element;
    for (int i = 0; i< number_of_element; i++)
    {
        cout << "Enter the value: ";
        cin >> value;
        Insert(&root, value);
    }

    char search;
    int to_find;
    cout << "Wanna search for the value(y/n): ";
    cin >> search;
    while (search != 'n')
    {
        cout << "what number do you want to find ? ";
        cin >> to_find;
        SearchFor(root, to_find);
        cout << "continue ? (y/n): ";
        cin >> search;
    }

    FindMax(root);
    FindMin(root);
    cout << "program ending...." << endl;
    this_thread::sleep_for(chrono::seconds(3));
}