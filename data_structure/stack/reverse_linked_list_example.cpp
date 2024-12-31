#include <iostream>
#include <stack>

using namespace std;

// Definition for singly-linked list
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Function to reverse a linked list using a stack
ListNode* reverseLinkedList(ListNode* head) {
    // Step 1: Push nodes onto a stack
    stack<ListNode*> nodeStack;
    ListNode* current = head;
    while (current != nullptr) {
        nodeStack.push(current);
        current = current->next;
    }

    // Step 2: Pop nodes from the stack and adjust next pointers
    ListNode* newHead = nullptr;
    ListNode* prev = nullptr;
    while (!nodeStack.empty()) {
        ListNode* node = nodeStack.top();
        nodeStack.pop();

        if (prev == nullptr) {
            newHead = node;
        } else {
            prev->next = node;
        }

        prev = node;
    }

    if (prev != nullptr) {
        prev->next = nullptr; // Set the next of the last node to null
    }

    return newHead;
}

// Function to print a linked list
void printList(ListNode* head) {
    ListNode* current = head;
    while (current != nullptr) {
        cout << current->val << " ";
        current = current->next;
    }
    cout << endl;
}

int main() {
    // Example usage
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);

    cout << "Original Linked List: ";
    printList(head);

    // Reverse the linked list using a stack
    head = reverseLinkedList(head);

    cout << "Reversed Linked List: ";
    printList(head);

    // Clean up memory (deallocation)
    while (head != nullptr) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
