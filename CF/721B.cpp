#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> preSort(vector<string> attempts) {
    int n = attempts.size();
    bool swapped;
  
    for (int i = 0; i < n - 1; i++) {
        swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (attempts[j].length() > attempts[j + 1].length()) {
                swap(attempts[j], attempts[j + 1]);
                swapped = true;
            }
        }
      
        // If no two elements were swapped, then break
        if (!swapped)
            break;
    }
    return attempts;
}

vector<int> solve(vector<string>& sortedAttempts, string password, int k) {
    int best = 0;
    int worst = 0;
    int length = password.length();

    //finding best case
    for (auto &s : sortedAttempts) {
        best++;
        if (s.length() == length) {
            break;
        }
    }

    //finding worst case
    for (auto &s : sortedAttempts) {
        worst++;
        if (s.length() > length) {
            worst--;
            break;
        }
    }

    int num_worst_wrong = worst ;
    int count_worst = 0;
    for (int i = 0; i < num_worst_wrong; i++) {
        if (count_worst == k) {
            worst += 5;
            count_worst = 0;
        }
        count_worst++;
    }

    int num_best_wrong = best ;
    int count = 0;
    for (int i = 0; i < num_best_wrong; i++) {
        if (count == k) {
            best += 5;
            count = 0;
        }
        count++;
    }

    vector<int> best_and_worst;
    best_and_worst.push_back(best);
    best_and_worst.push_back(worst);
    
    return best_and_worst;
}

int main() {
    int n, k;
    cin >> n >> k;
    
    vector<string> attempts;

    cin.ignore();

    for (int i = 0; i < n; i++) {
        string s;
        getline(cin ,s);
    
        attempts.push_back(s);
    }


    string password;
    getline(cin,password);
    
    vector<string> sortedAttempts = preSort(attempts);
    vector<int> ans = solve(sortedAttempts, password, k);
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }

    cout << endl;
}
