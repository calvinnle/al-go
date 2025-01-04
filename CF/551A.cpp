#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (auto &x : a) cin >> x;

    vector<int> clone_a(a);
    sort(clone_a.begin(), clone_a.end(), greater<int>());

    unordered_map<int, int> mp;

    for (int i = 0; i < n; i++) {
        if (mp.find(clone_a[i]) == mp.end()) mp[clone_a[i]] = i + 1;
    }

    for (auto &x : a) {
        cout << mp[x] << " ";
    }

    cout << endl;

    return 0;
}
