#include <iostream>

void reverseString(char* str) {
    // Find the length of the string
    int length = 0;
    while (str[length] != '\0') {
        ++length;
    }

    // Initialize pointers to the first and last elements
    int i = 0;
    int j = length - 1;

    // Swap elements until the two pointers meet
    while (i < j) {
        // Swap str[i] and str[j]
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;

        // Move the pointers towards each other
        ++i;
        --j;
    }
}

int main() {
    // Example usage
    char myString[] = "Hello, World!";
    
    std::cout << "Original String: " << myString << std::endl;

    // Reverse the string in-place
    reverseString(myString);

    std::cout << "Reversed String: " << myString << std::endl;

    return 0;
}
