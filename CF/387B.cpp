#include <bits/stdc++.h>

using namespace std;

int solve(vector<int>& a, vector<int>& b) {
    int ans = a.size();

    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < b.size(); j++) {
            if (b[j] >= a[i]) {
                ans--;
                a.erase(a.begin() + i);
                b.erase(b.begin() + j);
                i--;
                j--;
                break;
            }

            if (ans == 0) {
                return ans;
            }
        }
    }

    return ans;
}

int main() {
    int n,m;
    cin >> n >> m;

    vector<int> a(n);
    vector<int> b(m);

    for (int &x : a) cin >> x;
    for (int &x : b) cin >> x;

    int ans = solve(a, b);
    cout << ans << endl;
}
