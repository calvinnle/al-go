#include <iostream>
#include <stack>

using namespace std;

class Node
{
public:
    int data;
    Node* next;

    Node(int d, Node* n = nullptr) : data(d), next(n) {}
};

Node* head = nullptr;

void Reverse(Node** head)
{
    stack<Node*> s;
    Node* temp = *head;
    if (temp == nullptr) return;
    while (temp != nullptr)
    {
        s.push(temp);
        temp = temp->next;
    }

    *head = s.top();
    temp = *head;
    s.pop();
    while (!s.empty())
    {
        temp->next = s.top();
        s.pop();
        temp = temp->next;
    }
    temp->next = nullptr;
}

void Print(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    Node* node4 = new Node(31);
    node4->next = new Node(23);

    head = node4;

    Print(head);
    Reverse(&head);
    Print(head);


}