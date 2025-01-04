#include <vector>
#include <iostream>

using namespace std;

vector<int> solve(vector<int>& a, int k) {
    vector<int> visited(1e5 + 1, 0);
    int unique = 0;
    int r = -1;
    int l = 0;

    for (int i = 0; i < a.size(); i++) {
        if (visited[a[i]] == 0) {
            unique++;
        }

        visited[a[i]]++;

        if (unique == k) {
            r = i;
            break;
        }
    }

    if (r == -1) {
        return {-1,-1};
    }

    while (l <= r) {
        if (visited[a[l]] > 1) {
            visited[a[l]]--;
            l++;
        } else {
            break;
        }
    }

    return {l+1,r +1};
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> a;

    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        a.push_back(tmp);
    }

    vector<int> ans = solve(a, k);
    cout << ans[0] << " " << ans[1] << endl;
}
