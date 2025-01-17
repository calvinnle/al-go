#include <bits/stdc++.h>

using namespace std;

pair<int,int> maxInQueue(queue<pair<int, int>> q) {
    pair<int,int> maxx = q.front();
    q.pop();
    
    while (!q.empty()) {
        pair<int, int> temp = q.front();
        
        q.pop();

        if (temp.first > maxx.first) {
            maxx = temp;
        }
    }

    return maxx;
}

int main() {
    int k;
    cin >> k;
        vector<int> ans;

    for (int i = 0; i < k; i++) {
        int n,m;
        cin >> n >> m;

        queue<pair<int, int>> q;

        for (int j = 0; j < n; j++) {
            pair<int, int> tmp;
            int first;
            cin >> first;
            tmp.first = first;

            if (j == m) {
                tmp.second = 1;
            } else tmp.second = 0;

            q.push(tmp);
        }

        int time = 0;

        while (!q.empty()) {
            pair<int,int> maxx = maxInQueue(q);

            pair<int,int> f= q.front();

            q.pop();

            if (f.first < maxx.first) q.push(f);
            else if (f.first == maxx.first) {
                if (f.second == 1) {
                    ans.push_back(time+1); 
                    break;
                }
                time += 1;
            }
        }
    }

    for (auto &x : ans) cout << x << endl;
}
