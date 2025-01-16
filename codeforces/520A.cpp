#include <bits/stdc++.h>
#include <cctype>

using namespace std;

int main() {
    int n;
    cin >> n;

    set<char> word;

    for (int i = 0; i < n; i++) {
        char tmp;
        cin >> tmp;
        word.insert(tolower(tmp));
    }

    if (word.size() == 26) {
        cout << "YES";
    } else cout << "NO";

    cout << "\n";
}
