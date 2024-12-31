#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());

        if (s == t) {
            return true;
        } else {
            return false;
        }
    }
};

int main() {
    string s = "calvin";
    string t = "nvilac";


    Solution solution;
    bool res = solution.isAnagram(s, t);
    cout << res << endl;
}
