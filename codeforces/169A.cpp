#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int n,a,b;
    scanf("%d %d %d", &n, &a, &b);

    vector<ll> h;

    for (int i = 0; i < n; i++) {
        ll tmp;
        cin >> tmp;
        h.push_back(tmp);
    }

    sort(h.begin(), h.end());
    
    int count = 0;
    for (int i = 0; i < n; i++) {
        count++;
        if (count == b) {
            cout << h[i+1] - h[i] << endl;  
        }
    }
}

/*#include <bits/stdc++.h>*/
/*using namespace std;*/
/*using ll = long long;*/
/**/
/*int main() {*/
/*    int n, a, b;*/
/*    cin >> n >> a >> b;*/
/**/
/*    vector<ll> h(n);*/
/*    for (ll &x : h) cin >> x;*/
/**/
/*    sort(h.begin(), h.end());*/
/*    cout << h[b] - h[b - 1] << endl;*/
/**/
/*    return 0;*/
/*}*/
