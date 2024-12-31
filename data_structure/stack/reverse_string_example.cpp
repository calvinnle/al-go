#include <iostream>
#include <string>
#include <stack>

using namespace std;

string reverseString(const string& input) {
    stack<char> charStack;

    // Push each character onto the stack
    for (size_t i = 0; i < input.length(); ++i) {
        charStack.push(input[i]);
    }

    // Pop characters from the stack to build the reversed string
    string reversedString;
    while (!charStack.empty()) {
        reversedString += charStack.top();
        charStack.pop();
    }

    return reversedString;
}

int main() {
    string originalString = "Hello, World!";
    string reversedString = reverseString(originalString);

    cout << "Original String: " << originalString << endl;
    cout << "Reversed String: " << reversedString << endl;

    return 0;
}
