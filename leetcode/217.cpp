#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// brute force approach
/*bool containsDuplicate(vector<int>& nums) {*/
/*	for (int i = 0; i < nums.size(); i++) {*/
/*		for (int j = i + 1; j < nums.size(); j++) {*/
/*			if (nums[i] == nums[j]) {*/
/*				return true;*/
/*			}*/
/*		}*/
/*	}*/
/**/
/*	return false;*/
/*}*/

bool containsDuplicate(vector<int>& nums) {
    unordered_map<int, int> visited;
    
    for (int i = 0; i < nums.size(); i++) {
        if (visited.count(nums[i]) >  0) {
            return true; 
        }
        visited[nums[i]] = i;
    }

    return false;
}

int main() {
	vector<int> a;
	a.push_back(1);
	a.push_back(2);
	a.push_back(4);
	a.push_back(5);
	a.push_back(4);
	a.push_back(2);
	a.push_back(8);


	bool res = containsDuplicate(a);
	cout << res << endl;

}
