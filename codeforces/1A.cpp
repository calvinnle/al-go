#include <bits

using namespace std;

using ll = long long;

int main() {
    long double n,m,a;
    cin >> n >> m >> a;

    long double shape = n * m;

    if (shape <= (a *a)) {
            cout << "1" << endl;
            return 0;
    }

    ll res =ceil(shape / (a*a));
    
    if (res % 2 == 0)  {
        cout << res << endl;
    } else {
        cout << res + 1 << endl;
    }
} 
