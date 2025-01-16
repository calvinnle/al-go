#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
    ll k,n,w;
    cin >> k >> n >> w;

    int total = 0;
    for (int i = 0; i < w; i++) {
        total += k * (i+1);       
    }
    
    (total - n <= 0) ? (cout << 0 << endl) : (cout << total - n << endl);

}

