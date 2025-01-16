#include <iostream>
#include <vector>
#include <string>


using namespace std;


string solve(vector<int> buttons) {
    if (buttons.size() == 1) {
        if (buttons[0] == 0) {
            return "NO";
        } else {
            return "YES";
        }
    }
    
    int count_zero = 0;
    for (int i = 0; i < buttons.size(); i++) {
        if (buttons[i] == 0) {
            count_zero++;
        }
    }

    if (count_zero > 1 || count_zero == 0) {
        return "NO";
    }

    return "YES";

}

int main() {
    int n; cin >> n;

    vector<int> buttons;
    for (int i = 0; i < n; i++) {
        int button;
        cin >> button;
        buttons.push_back(button);
    }

    string res = solve(buttons);
    cout << res << endl;
}
