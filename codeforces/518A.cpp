#include <bits/stdc++.h>

using namespace std;


string solve(string s, string t) {
    for (int i = s.length() - 1; i >= 0; i--) {
        if (s[i] != 'z') {
            s[i]++;
            break;
        } else {
           s[i] = 'a';
        }
    }

    if (s == t) {
        return "No such string";
    }

    return s;
}


int main() {
    string s;
    string t;
    getline(cin, s);
    getline(cin, t);

    string result = solve(s, t);
    cout << result << endl;
}
