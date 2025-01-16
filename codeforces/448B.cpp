#include <iostream>
#include <string>
#include <algorithm>


using namespace std;

bool arr(string s, string t) {
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());
    
    return s == t;
}

bool automaton(string a, string b) {
    int n = 0;
    for (int i = 0; i < a.length() and n < b.length(); i++) n += a[i] == b[n];
    return n == b.length();
}

bool both(string a, string b) {
    for (int i = 0; i < b.length(); i++) {
        int p = a.find(b[i]);
        if (p == -1) return false;
        a[p] = '0';
    }
    return true;
}

int main() {
    string s,t;
    cin >> s >> t;
    if (arr(s,t)) cout << "array" << endl;
    else if (automaton(s,t)) cout << "automaton" << endl;
    else if (both(s,t)) cout << "both" << endl;
    else cout << "need tree" << endl;
}
