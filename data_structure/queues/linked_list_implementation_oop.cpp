#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

class Queue {
private:
    Node* front;
    Node* rear;

public:
    Queue() : front(nullptr), rear(nullptr) {}

    void Enqueue(int x) {
        Node* temp = new Node(x);
        if (front == nullptr && rear == nullptr) {
            front = rear = temp;
        } else {
            rear->next = temp;
            rear = temp;
        }
    }

    void Dequeue() {
        if (front == nullptr) {
            cout << "Queue is Empty" << endl;
            return;
        }
        Node* temp = front;
        if (front == rear) {
            front = rear = nullptr;
        } else {
            front = front->next;
        }
        delete temp;
    }

    int Front() {
        if (front == nullptr) {
            cout << "Queue is empty" << endl;
            return -1; // Assuming -1 as an invalid value for an integer queue
        }
        return front->data;
    }

    void Print() {
        Node* temp = front;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    // Drive code to test the implementation.
    // Printing elements in Queue after each Enqueue or Dequeue 
    Queue myQueue;
    myQueue.Enqueue(2);
    myQueue.Print();
    myQueue.Enqueue(4);
    myQueue.Print();
    myQueue.Enqueue(6);
    myQueue.Print();
    myQueue.Dequeue();
    myQueue.Print();
    myQueue.Enqueue(8);
    myQueue.Print();

    return 0;
}
