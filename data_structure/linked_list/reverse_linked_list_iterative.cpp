#include <iostream>

using namespace std;

class Node
{
    public:
    int data;
    Node* next;

    ~Node()
    {
        cout << "Releasing the memory for node." << endl;
    }
};

Node* head = nullptr;

void Insert(Node** head, int value, int index)
{   
    Node* temp1 = new Node();
    temp1->data = value;
    temp1->next = nullptr;
    if (index == 1)
    {
        temp1->next = (*head);
        (*head) = temp1;
    } 
    
    else 
    {
        Node* temp2 = (*head);
        for (int i = 0; i < index - 2; i++)
        {
            temp2 = temp2->next;
        }

        temp1->next = temp2->next;
        temp2->next = temp1;
    }
}
void Display(Node** head)
{
    Node* temp = *head;
    cout << "List is: " << " ";
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

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
    int num_of_element, value, index;
    cout << "How many elements do u want?";
    cin >> num_of_element;
    for (int i = 0; i < num_of_element; i++)
    {
        cout << "Enter value: ";
        cout << "Enter index: ";
        cin >> value;
        cin >> index;
        Insert(&head, value, index);
    }
    Display(&head);
    Reverse(&head);
    Display(&head);
}