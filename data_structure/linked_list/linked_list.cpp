#include <iostream>
#include <string>

using namespace std;

class Node
{
    string data;
    Node* next;
};

void Reverse(Node** head)
{   
    cout << "Reversing the linked list: ";
    Node* prev, *current, *next;
    current = *head;
    prev = nullptr;
    while (current != nullptr)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
}

int main()
{
    // Create the head pointer 
    Node* head = nullptr;

    // Create the first node
    Node* temp = new Node;
    temp->data = "CCCC";
    temp->next = nullptr;

    // Assign the head to first node
    head = temp;

    // Create the second node
    temp->next = new Node;
    temp = temp->next;
    temp->data = "BBBB";
    temp->next = nullptr;

    // Create the third node
    temp->next = new Node;
    temp = temp->next;
    temp->data = "AAAA";
    temp->next = nullptr;

    //Reverse(&head);

    // Print the values in the linked list
    cout << "Values in the linked list:" << endl;
    temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << endl;
        temp = temp->next;
    }

    // Don't forget to free the memory allocated for the nodes
    temp = head;
    while (temp != nullptr)
    {
        Node* toDelete = temp;
        temp = temp->next;
        delete toDelete;
    }

    return 0;
}
