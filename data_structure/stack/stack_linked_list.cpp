#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node* next;
};


class Stack
{
    private:
    Node* top;;

    public:
    Stack()
    {
        top = nullptr;
    }

    void push(int val)
    {
        Node* temp = new Node();
        temp->data = val;
        temp->next = top;
        top = temp;
    }

    void pop()
    {
        Node* temp = top;
        if (IsEmpty()) return;
        top = temp->next;
        temp->next = nullptr;
        free(temp);
    }

    void print()
    {
        Node* temp = top;
        cout << "stack: ";
        while (temp != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    bool IsEmpty()
    {
        if (top == nullptr) 
        {   
            cout << "stack is empty" << endl;
            return 1;
        }
        cout << "stack isn't empty sir" << endl;
        return 0;
    }
};

int main()
{
    Stack a;
    Stack b;
    a.push(5);
    a.print();
    a.IsEmpty();
    b.IsEmpty();
}