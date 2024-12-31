#include <iostream>

using namespace std;

class Stack
{
private:
    int arr[101]; //array to store the stack
    int top; //variable to mark the top index of stack
public:
    Stack()
    {
        top = -1; //empty stack
    }

    //Push operation to insert an element on top of stack
    void Push(int x)
    {
        if (top == 101 - 1)
        {
            cout << "stack overflow." << endl;
            return;        
        }
        top++;
        arr[top] = x;
    }

    void Pop()
    {
        if (top == -1)
        {
            cout << "stack is empty 😭" << endl;
            return;
        }

        top--;
    }

    int getTop()
    {
        return arr[top];
    }

    bool IsEmpty()
    {
        if (top == -1)
        {
            return true;
        }
        return false;
    }

    void Print()
    {
        cout << "Stack: ";
        for (int i = 0; i <= top; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};
int main()
{
    Stack stack;
    cout << stack.IsEmpty() << endl;
    //1
    stack.Push(8);
    stack.Push(5);
    stack.Push(2);
    stack.Push(3);
    stack.Push(10);

    cout << stack.IsEmpty() << endl; //0
    int a = stack.getTop();
    cout << a << endl; //10
    stack.Print(); //8 5 2 3 10
    stack.Pop();
    stack.Print(); //8 5 2 3


    
}