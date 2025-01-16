#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> A(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }

    vector<int> freq(100001, 0); 
    int count = 0;              
    int best = 0;               
    int l = 1;                  

    for (int r = 1; r <= n; r++) {
        if (freq[A[r]] == 0) {
            count++;
        }
        freq[A[r]]++;

        while (count > 2) {
            freq[A[l]]--;
            if (freq[A[l]] == 0) {
                count--;
            }
            l++;
        }

        best = max(best, r - l + 1);
    }

    cout << best << endl;

    return 0;
}
