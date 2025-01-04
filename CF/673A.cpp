#include <iostream>
#include <vector>

using namespace std;


int solve(vector<int> t) {
    int boring_time = 0;
    int time_watched = 0;

    for (int i = 0; i < 90; i++) {

        for (int j = 0; j < t.size(); j++) {
            if (i == t[j]) {
                boring_time = 0;
            }
        }
        if (boring_time == 15) {
            return time_watched;
        }
        boring_time++; 
        time_watched++;
    }
    return time_watched;
}


int main() {
    int n;
	cin >> n;
    vector<int> t;

	for (int i = 0; i < n; i++) {
		int t_min;
        cin >> t_min;
        t.push_back(t_min);
    }

    int res = solve(t);
    cout << res << endl;
}
