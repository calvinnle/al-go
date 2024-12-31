#include <iostream>

using namespace std;


class Node
{
public:
    int value;
    Node* next;
};

Node* Insert(Node* head, int value)
{
    Node* temp = new Node();
    temp->value = value;
    temp->next = head;
    head = temp;
    return head;
}

void Print(Node* head)
{
    while (head != nullptr)
    {
        cout << head->value << " ";
        head = head->next;
    }
}
int main()
{

    Node* head = nullptr;

    int num_of_element, value;
    cout << "How many elements do you want in a linked list ?";
    cout << endl;
    cin >> num_of_element;
    for (int i = 0;i < num_of_element; i++)
    {
        cout << "Enter the value of the element ?";
        cin >> value;
        cout << endl;
        head = Insert(head, value);
        Print(head);
    }

}