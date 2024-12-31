#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

class Node
{
public:
    int data;
    Node* left;
    Node* right;
};

Node* GetNewNode(int val)
{
    Node* newNode = new Node();
    newNode->data = val;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

Node* Insert(Node* root, int data)
{
    if (root == nullptr)
    {
        root = GetNewNode(data);
        return root;
    }

    else if (data <= root->data)
    {
        root->left = Insert(root->left, data);
    }
    
    else 
    {
        root->right = Insert(root->right, data);
    }

    return root;
}

bool Search(Node* root, int data)
{
    if (root == nullptr)
    {
        cout << "not found." << endl;
        return false;
    }
    else if (data == root->data) 
    {
        cout << "found." << endl;
        return true;
    }
    else if (data < root->data) return Search(root->left, data);
    else return Search(root->right, data);

}

int main()
{
    Node* root = nullptr;
    root = Insert(root, 15);
    root = Insert(root, 10);
    root = Insert(root, 12);
    root = Insert(root, 14);
    root = Insert(root, 16);
    root = Insert(root, 13);

    int number_of_element, value;
    cout << "How many elements do you want to insert in the tree: ";
    cin >> number_of_element;
    for (int i = 0; i< number_of_element; i++)
    {
        cout << "Enter the value: ";
        cin >> value;
        root = Insert(root, value);
    }

    char search;
    int to_find;
    cout << "Wanna search for the value(y/n): ";
    cin >> search;
    while (search != 'n')
    {
        cout << "what number do you want to find ? ";
        cin >> to_find;
        Search(root, to_find);
        cout << "continue ? (y/n): ";
        cin >> search;
    }
    cout << "program ending...." << endl;
    this_thread::sleep_for(chrono::seconds(3));
}