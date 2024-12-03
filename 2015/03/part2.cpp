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

    pair<int, int> posSanta = {0,0};
    pair<int, int> posRobo = {0,0};

    unordered_set<pair<int,int>, pair_hash> visited;
    visited.insert(posSanta);
    visited.insert(posRobo);

    for(int i = 0; i < dirs.size(); i++) {
        if(dirs[i] == '^') { if(i % 2 == 0) posSanta.second += 1; else posRobo.second += 1;}
        else if (dirs[i] == 'v') { if(i % 2 == 0) posSanta.second -= 1; else posRobo.second -= 1; }
        else if (dirs[i] == '>') { if(i % 2 == 0) posSanta.first += 1; else posRobo.first += 1; }
        else if (dirs[i] == '<') { if(i % 2 == 0) posSanta.first -= 1; else posRobo.first -= 1; };

        if(i % 2 == 0) visited.insert(posSanta);
        else visited.insert(posRobo);
    } 

    cout << "Part 2 : " << visited.size() << endl;

    return 0;
}