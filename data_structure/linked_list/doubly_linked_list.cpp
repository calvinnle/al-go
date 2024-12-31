#include <iostream>

using namespace std;

class Node
{
    public:
    int data;
    Node* prev;
    Node* next;
};

Node* head =nullptr;

Node* GetNewNode(int x)
{
    Node* newNode = new Node();
    newNode->data = x;
    newNode->next = nullptr;
    newNode->prev = nullptr;
    return newNode;
}

Node* InsertAtHead(Node* head, int x)
{
    Node* newNode = GetNewNode(x);
    if (head == nullptr)
    {
        head = newNode;
        return head;
    }

    head->prev = newNode;
    newNode->next = head;
    head = newNode;
    return head;
}

Node* InsertAtTail(Node* head, int val)
{
    Node* newNode = GetNewNode(val);
    if (head == nullptr)
    {
        head = newNode;
        return head;
    }

    Node* temp = head;
    while (temp->next != nullptr)
    {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;
    return head;
}

void Display(Node** head)
{
    Node* temp  = *head;
    cout << "List is: " ;
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void ReverseDisplay(Node** head)
{
    Node* temp = *head;
    while (temp->next != nullptr)
    {
        temp = temp->next;
    }

    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->prev;
    }
    cout << endl;
}

int main()
{
    head = InsertAtHead(head, 31);
    head = InsertAtHead(head, 43);
    head = InsertAtHead(head, 455);
    head = InsertAtHead(head, 34);
    //34 455 43 31
    head = InsertAtTail(head, 88);
    head = InsertAtTail(head, 2010);
    //34 455 43 31 88 2010    

    Display(&head);
    //34 455 43 31 88 2010

    ReverseDisplay(&head);
    //2010 88 31 43 455 34

}
