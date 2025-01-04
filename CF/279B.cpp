#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solve(vector<int>& a, int t) {
    int max_book = 0;
    int l = 0;
    int current_time = 0;

    for (int r = 0; r < a.size(); r++) {
        current_time += a[r];

        while (current_time > t) {
            current_time -= a[l];
            l++;
        }

        max_book = max(max_book, r - l + 1);
    }

    return max_book;
}

int main() {
    int n, t;
    cin >> n >> t;

    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int ans = solve(a, t);
    cout << ans << endl;

    return 0;
}
