#include <bits/stdc++.h>

using namespace std;

struct pair_hash {
    template <typename T1, typename T2>
    size_t operator() (const pair<T1, T2>& p) const {
        auto h1 = hash<T1>{}(p.first);
        auto h2 = hash<T2>{}(p.second);
        return h1 ^ (h2 << 1);
    }
};

int main() {
    string dirs;

    ifstream file("input");
    file >> dirs;

    pair<int, int> pos = {0,0};

    unordered_set<pair<int,int>, pair_hash> visited;
    visited.insert(pos);

    for (char c : dirs) {
        if(c == '^') pos.second += 1;
        else if (c == 'v') pos.second -= 1;
        else if (c == '>') pos.first += 1;
        else if (c == '<') pos.first -= 1;

        visited.insert(pos);
    } 

    cout << "Part 1 : " << visited.size() << endl;

    return 0;
}