#include <iostream>
#include <vector>

using namespace std;

vector<int> arr;

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

void Inorder(Node* root)
{
    if (root == nullptr) return;
    Inorder(root->left);
    arr.push_back(root->data);
    Inorder(root->right);
}

bool check_sorted(const vector<int>& a)
{
    for (int i = 1; i < a.size(); i++)
    {
        for (int j = i - 1; j < i; j++)
        {
            if (a[j] > a[i])
            {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    Node* root = nullptr;
    Insert(&root, 1);
    Insert(&root, 4);
    Insert(&root, 6);
    Insert(&root, 7);
    Insert(&root, 102);
    

    Inorder(root);
    int a = check_sorted(arr);
    cout << a << endl;

}