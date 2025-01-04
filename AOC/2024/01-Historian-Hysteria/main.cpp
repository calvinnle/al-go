#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cstdlib>  // For std::abs()

int main() {
    std::ifstream inputFile("input.txt");
    std::string line;
    std::vector<int> list1, list2;  // Two separate lists

    if (!inputFile) {
        std::cerr << "Error opening file!" << std::endl;
        return 1;
    }

    // Read the file and populate the two lists
    while (std::getline(inputFile, line)) {
        std::istringstream iss(line);
        int a, b;
        if (iss >> a >> b) {
            list1.push_back(a);
            list2.push_back(b);
        } else {
            std::cerr << "Error parsing line: " << line << std::endl;
        }
    }
    inputFile.close();

    // Sort both lists
    std::sort(list1.begin(), list1.end());
    std::sort(list2.begin(), list2.end());

    // Calculate the total distance
    int totalDistance = 0;
    for (size_t i = 0; i < list1.size(); ++i) {
        totalDistance += std::abs(list1[i] - list2[i]);  // Pairwise absolute difference
    }

    // Output the sorted lists and total distance
    std::cout << "Sorted List 1: ";
    for (size_t i = 0; i < list1.size(); ++i) {
        std::cout << list1[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Sorted List 2: ";
    for (size_t i = 0; i < list2.size(); ++i) {
        std::cout << list2[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Total Distance: " << totalDistance << std::endl;

    return 0;
}
