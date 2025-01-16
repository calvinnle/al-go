#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>

using namespace std;

int clockwise(int start, int target) {
    int step;
    if (start < target) {
        step = target - start;
    } else {
        step = abs(target - start + 26);
    }
    return step;
}

int counterClockwise(int start, int target) {
    int step;
    if (target > start) {
        step = start - target + 26;
    } else {
        step = start - target;
    }
    return step;
}

int solve(string &s) {
    int start = 'a' + 0;
    int step = 0;

    for (int i = 0; i < s.length(); i++) {
        int target = s.at(i);

        int clockwiseStep = clockwise(start, target);
        int counterClockwiseStep = counterClockwise(start, target);

        if (clockwiseStep < counterClockwiseStep) {
            step += clockwiseStep;
        } else {
            step += counterClockwiseStep;
        }

        start = s.at(i);
    }

    return step;
}

int main() {
    string s;
    getline(cin, s);

    int result = solve(s);

    cout << result << endl;
}
