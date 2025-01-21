#include <iostream>
#include <vector>

using namespace std;

vector<int> solve(vector<int> &a) {
    int seraja = 0;
    int dima = 0;
    int l = 0;
    int r = a.size() - 1;

    bool seraja_turn = true;

    while (l <= r) {
        if (a[l] >= a[r]) {
            if (seraja_turn) {
                seraja += a[l];
            } else {
                dima += a[l];
            }
            l++;
        } else {
            if (seraja_turn) {
                seraja += a[r];
            } else {
                dima += a[r];
            }
            r--;
        }

        seraja_turn = !seraja_turn;
    }

    return {seraja, dima};
}

int main() {
    int n;
    cin >> n;

    vector<int> a;

    for (int i = 0; i < n; i++) {
        int s;
        cin >> s;
        a.push_back(s);
    }

    vector<int> ans = solve(a);
    cout << ans[0] << " " << ans[1] << endl;
}
