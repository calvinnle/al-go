#include <iostream>
#include <vector>

using namespace std;


int solve(vector<vector<int> >& a) {
    int min_left = a[0][0];
    for (int i = 0; i < a.size(); i++) {
        if (a[i][0] < min_left) {
            min_left = a[i][0];
        }
    }

    int max_right = a[0][1];
    for (int i = 0; i < a.size(); i++) {
        if (a[i][1] > max_right) {
            max_right = a[i][1];
        }
    }

    vector<int> target;
    target.push_back(min_left);
    target.push_back(max_right);

    for (int i = 0; i < a.size(); i++) {
        if (a[i][0] == target[0] && a[i][1] == target[1]) {
            return i + 1;
        }
    }

    return -1;
}

int main() {
    int n;
    cin >> n;

    vector<vector<int> > all_arr;

    for (int i = 0; i < n; i++) {
        vector<int> arr;
        int l,r;
        cin >> l >> r;
        arr.push_back(l);
        arr.push_back(r);

        all_arr.push_back(arr);
    }

    int result = solve(all_arr);
    cout << result << endl;
}
