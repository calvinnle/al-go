#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    long long n, x;
    cin >> n >> x;

    vector<int> c;

    for (long long i = 0; i < n; i++) {
        long long s;
        cin >> s;
        c.push_back(s);
    }

    sort(c.begin(), c.end());

    long long time = 0;

    for (long long i = 0; i < n; i++) {
        time += x * c[i]; 
        if (x == 1) {
            continue;
        }
        x--;
    }
    
    cout << time << endl;

}
