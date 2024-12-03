#include <bits/stdc++.h>

using namespace std;

bool part1(const vector<int>& rep) {
    bool isInc = true;
    bool isDec = true;

    for (int i = 1; i < rep.size(); ++i) {
        int diff = rep[i] - rep[i - 1];
        
        if (abs(diff) < 1 || abs(diff) > 3) {
            return false;
        }

        if (diff <= 0) {
            isInc = false;
        }
        if (diff >= 0) {
            isDec = false;
        }
    }

    return isInc || isDec;
}

bool part2(vector<int> rep) {
    for (int i = 0; i < rep.size(); ++i) {
        vector<int> changed = rep;
        changed.erase(changed.begin() + i);

        if (part1(changed)) {
            return true;
        }
    }

    return false;
}

int main() {
    string line;
    int ans1 = 0;
    int ans2 = 0;

    while (getline(cin, line)) {
        vector<int> rep;
        stringstream ss(line);
        int level;

        while (ss >> level) {
            rep.push_back(level);
        }

        if (part1(rep)) {
            ans1++;
        }

        if (part2(rep)) {
            ans2++;
        }
    }

    cout << "Part 1: " << ans1 << endl;
    cout << "Part 2: " << ans2 << endl;

    return 0;
}
