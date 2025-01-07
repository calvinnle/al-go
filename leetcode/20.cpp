#include <bits/stdc++.h>

using namespace std;

bool solve(string s) {
    stack<char> stack;

    for (auto &x : s) {
        if ((x == '{') || (x == '[') || (x == '(')) {
            stack.push(x);
        } else if (x =='}') {
            if (stack.top() == '{') {
                stack.pop();
            } 
        } else if (x == ']') {
            if (stack.top() == '[') {
                stack.pop();
            }
        } else if (x == ')') {
            if (stack.top() == '(') {
                stack.pop();
            }
        } else {
            return false;
        }
    }

    if (!stack.empty()) {
        return false;
    }

    return true;
}

int main() {
    string s;
    cin >> s;

    bool ans = solve(s);
    cout << ans << endl;
    
}
