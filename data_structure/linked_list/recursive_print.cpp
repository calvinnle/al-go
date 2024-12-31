#include <iostream>

using namespace std;

class Node
{
    public:
    int data;
    Node* next;
};

void Print(Node* ptr)
{
    if (ptr == NULL) return;
    Print(ptr->next);
    cout << ptr->data << " ";
}

Node* Insert(Node* head, int value)
{
    Node* temp1 = new Node();
    temp1->data = value;
    temp1->next = nullptr;
    if (head == nullptr)
    {
        head = temp1;
    }
    else {
        Node* temp2 = head;
        while (temp2->next != nullptr)
        {
            temp2 = temp2->next;
        }
        temp2->next = temp1;
    }
    return head;

}

int main()
{
    Node* head = nullptr;

    head = Insert(head,1);
    head = Insert(head,2);
    head = Insert(head,3);
    head = Insert(head,4);
    head = Insert(head,5);

    Print(head);

}