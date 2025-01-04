#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

string solve(vector<int>& s, vector<int>& t, int k, int m) {
    vector<int> chosen_from_s;
    vector<int> chosen_from_t;
    
    //sort 2 arrays ascending
    sort(s.begin(), s.end());
    sort(t.begin(), t.end(), greater<int>());


    //choose k from s and m from t.
    for (int i = 0; i < k; i++) {
        chosen_from_s.push_back(s[i]);
    }

    for (int i = 0; i < m; i++) {
        chosen_from_t.push_back(t[i]);
    }

    //find max in s
    int max_s = chosen_from_s[0];
    for (int i = 0; i < chosen_from_s.size(); i++) {
        if (chosen_from_s[i] > max_s) {
            max_s = chosen_from_s[i];
        }
    }
    
    //find min in t
    int min_t = chosen_from_t[0];
    for (int i = 0; i < chosen_from_t.size(); i++) {
        if (chosen_from_t[i] < min_t) {
            min_t = chosen_from_t[i];
        }
    }
    
    //compare
    if (max_s < min_t) {
        return "YES";
    }

    return "NO";
}

int main() {
    int n1, n2;
    cin >> n1 >> n2;

    int k,m;
    cin >> k >> m;

    vector<int> s;
    vector<int> t;

    for (int i = 0; i < n1; i++) {
        int a;
        cin >> a;
        s.push_back(a);
    }


    for (int i = 0; i < n2; i++) {
        int a;
        cin >> a;
        t.push_back(a);
    }


    string result = solve(s, t, k, m);
    cout << result << endl;
}
