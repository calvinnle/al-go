#include <iostream>
#include <vector>

using namespace std;


int main() {
    int n;
    cin >> n;

    vector<int> a;
    for (int i = 0; i <  n - 1; i++) {
        int s;
        cin >> s;
        a.push_back(s);
    }

    int expected_sum = 0;
    int current_sum = 0;

    for (int i = 1; i <= n; i++) {
        expected_sum+= i;
    }

    for (int i = 0; i < a.size();i++) {
        current_sum += a[i];
    }

    cout << expected_sum - current_sum << endl;


}
