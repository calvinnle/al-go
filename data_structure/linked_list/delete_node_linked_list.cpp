#include <iostream>
#include <string>

using namespace std;

class Node
{
public:
    int value;
    Node *next;
};

Node *head = nullptr;

void Insert(Node **head, int value, int index)
{
    Node *temp1 = new Node();
    temp1->value = value;
    temp1->next = nullptr;
    if (index == 1)
    {
        temp1->next = (*head);
        (*head) = temp1;
    }

    else
    {
        Node *temp2 = (*head);
        for (int i = 0; i < index - 2; i++)
        {
            temp2 = temp2->next;
        }

        temp1->next = temp2->next;
        temp2->next = temp1;
    }
}

int GetIndex(Node **head, int value)
{
    Node *temp = (*head);
    int i = 1;
    while (temp != nullptr)
    {
        if (temp->value == value)
        {
            return i;
        }
        i++;
        temp = temp->next;
    }
    return 0;
}

void Delete_node_at_position(Node **head, int index)
{
    cout << "Deleting node at postion " << index << "th." << endl;
    Node *temp1 = *head;
    if (index == 1)
    {
        *head = temp1->next;
        delete temp1;
    }
    else
    {
        for (int i = 0; i < index - 2; i++)
        {
            temp1 = temp1->next;
            // temp1 points to (index-1)th
        }
        Node *temp2 = temp1->next; // index-th postion
        temp1->next = temp2->next;
        delete temp2;
    }
}

void Delete_node_which_value_is(Node **head, int value)
{
    Node *temp = (*head);
    int i = 1;
    while (temp != nullptr)
    {
        if (temp->value == value)
        {
            break;
        }
        i++;
        temp = temp->next;
    }
    Delete_node_at_position(&(*head), i);
}

void Display(Node **head)
{
    Node *temp = *head;
    cout << "List is: " << " ";
    while (temp != nullptr)
    {
        cout << temp->value << " ";
        temp = temp->next;
    }
    cout << endl;
}

string response;

int main()
{
    cout << "wanna start the program of linked list (y/n): ";
    cin >> response;
    while (response != "n")
    {
        int option;
        cin >> option;
        switch (option)
        {
        case 1:
            int num_of_element, value, position;
            cout << "Enter the number of elements in the list: ";
            cin >> num_of_element;

            for (int i = 0; i < num_of_element; i++)
            {
                cout << "Enter the value for the element: ";
                cin >> value;
                cout << "Enter the position you want to add: ";
                cin >> position;
                Insert(&head, value, position);
            }
            Display(&head);
            break;

        case 2:
            int pos;
            cout << "Wanna delete a node ? Enter the position: ";
            cin >> pos;
            Delete_node_at_position(&head, pos);
            break;
        case 3:
            cout << "Wanna display the linked list? Alright" << endl;
            Display(&head);
            break;
        case 4:
            int val;
            cout << "wanna delete a note by value huh? alright" << endl;
            Delete_node_which_value_is(&head, value);
        case (5):
            response = "n";
            break;
        }
    }
}
