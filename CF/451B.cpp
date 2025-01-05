#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    if (n == 1) {
        cout << "yes" << endl;
        cout << 1 << " " << 1 << endl;
        return 0;
    }

    vector<int> a(n);
    vector<int> sorted_a(n);

    for (auto &x : a) cin >> x;
    
    copy(a.begin(), a.end(), sorted_a.begin());
    sort(sorted_a.begin(), sorted_a.end());

    int start;
    int end;
    
    for (int i = 0; i < n; i++) {
        if (a[i] < a[i + 1]) {
            continue;
        } else {
            start = i;
            break;
        }
    }

    for (int j = start; j < n; j++) {
        if (j == n - 1) {
            end = j;
        }
        else if (a[j] < a[j+1]) {
            end = j;
            break;
        } else continue;
    }

    if (start == end) {
        cout << "yes" << endl;

        cout << start << " " << end << endl;
        return 0;
    }

    sort(a.begin() + start, a.begin() + end+ 1);
    
    for (int i = 0; i < n; i++) {
        if (a[i] != sorted_a[i]) {
            cout << "no" << endl;
            return 0;
        }
    }

    cout << "yes" << endl;
    cout << start + 1 << " " << end + 1 << endl;
}

