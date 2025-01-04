#include <iostream>
#include <vector>
#include <stdlib.h>     /* abs */

using namespace std;

int safe = 0;

void isSafe(vector<int> arr) {
	for (int i = 0; i < arr.size(); i++) {
		for (int j = i + 1; i < arr.size(); i++) {
			int diff = abs(arr[i] - arr[j]);
			if (diff > 3) {
				safe++;
				break;
			} continue;
		}
	}
}	

int main() {
	vector<int> a;
	a.push_back(7);
	a.push_back(6);
	a.push_back(4);
	a.push_back(2);
	a.push_back(1);

	vector<int> line1;
	line1.push_back(1);
	line1.push_back(2);
	line1.push_back(7);
	line1.push_back(8);
	line1.push_back(9);

	// Line 2
	std::vector<int> line2;
	line2.push_back(9);
	line2.push_back(7);
	line2.push_back(6);
	line2.push_back(2);
	line2.push_back(1);

	// Line 3
	std::vector<int> line3;
	line3.push_back(1);
	line3.push_back(3);
	line3.push_back(2);
	line3.push_back(4);
	line3.push_back(5);

	// Line 4
	std::vector<int> line4;
	line4.push_back(8);
	line4.push_back(6);
	line4.push_back(4);
	line4.push_back(4);
	line4.push_back(1);

	// Line 5
	std::vector<int> line5;
	line5.push_back(1);
	line5.push_back(3);
	line5.push_back(6);
	line5.push_back(7);
	line5.push_back(9);

	isSafe(a);
	isSafe(line1);
	isSafe(line2);
	isSafe(line3);
	isSafe(line4);
	isSafe(line5);

	cout << safe << endl;
}
