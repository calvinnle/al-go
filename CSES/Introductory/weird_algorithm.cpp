#include <iostream>
/*#include <vector>*/

using namespace std;

int main() {
    int n;
    cin >> n;
    
    while (n != 1) {
        if (n % 2 == 0) {
            cout << n << " ";
            n = n / 2;
        } else if (n % 2 != 0) {
            cout << n << " ";
            n = n * 3 + 1;

        }

        if (n == 1) {
            cout << n << endl;
            break;
        }
        

    }
    
}
