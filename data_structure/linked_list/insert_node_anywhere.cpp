#include <iostream>

using namespace std;

class Node
{
    public:
        int data;
        Node* next;
};

Node* head;

void Insert(int value, int n)
{
    Node* temp1 = new Node();
    temp1->data = value;
    temp1->next = nullptr;

    if (n == 1 )
    {
        temp1->next = head;
        head = temp1;
        return;
    }

    Node* temp2 = head;
    for (int i = 0; i < n - 2; i++)
    {
        temp2 = temp2->next;
    }

    temp1->next = temp2->next;
    temp2->next = temp1;
}


void Print()
{
    Node* temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    Insert(2,1); //2
    Print();
    Insert(3,2); //2 3
    Print();
    Insert(8,3);
    Print();

}