#include <iostream>
#include <vector>

using namespace std;

vector<int> solve(vector<int>& a) {
    int alice = 0;
    int bob = 0;

    int alice_time = 0;
    int bob_time = 0;
    int l = 0;
    int r = a.size() - 1;

    while (l <= r) {
        if (alice_time <= bob_time) {
            alice++;
            alice_time += a[l];
            l++;
        } else {
            bob++;
            bob_time += a[r];
            r--;
        }
    }

    return {alice, bob};
}

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> ans = solve(a);
    cout << ans[0] << " " << ans[1] << endl;

    return 0;
}


