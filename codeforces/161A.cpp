#include <bits/stdc++.h>

using namespace std;

int main() {
    int n,m,x,y;
    cin >> n >> m >> x >> y;

    vector<int> a(n);
    vector<int> b(m);

    for (auto &x : a) cin >> x;
    for (auto &x : b) cin >> x;

    int la = 0;
    int lb = 0;

    int count = 0;

    vector<pair<int, int>> mp;
    while ((la < n) && (lb < m)) {
        if (b[lb] > a[la] + y) {
            la++;
        } else if (b[lb] < a[la] - x ){
            lb++;
        } else {
            count++;
            mp.push_back({la + 1, lb + 1}); 
            la++;
            lb++;
        }
    }

    cout << count << endl;

    for (auto x : mp) {
        cout << x.first << " " << x.second << endl;
    }
}
