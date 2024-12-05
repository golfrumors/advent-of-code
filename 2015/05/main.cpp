#include <bits/stdc++.h>

using namespace std;

int main() {
    ifstream inputFile("input");
    vector<string> strings;
    string line;
    
    while (getline(inputFile, line)) {
        strings.push_back(line);
    }

    regex vowReg("([aeiou].*){3,}");
    regex doubleReg("(.)\\1");
    regex forbSub("ab|cd|pq|xy");

    int ansPart1 = 0;
    for (const auto& s : strings) {
        if (regex_search(s, vowReg) && 
            regex_search(s, doubleReg) &&
            !regex_search(s, forbSub)) {
            ansPart1++;
        }
    }

    cout << "Part 1 : " << ansPart1 << endl;

    regex pairReg("(..).*\\1");
    regex repeatOneBetReg("(.).\\1");

    int ansPart2 = 0;
    for (const auto& s : strings) {
        if (regex_search(s, pairReg) && regex_search(s, repeatOneBetReg)) {
            ansPart2++;
        }
    }

    cout << "Part 2 : " << ansPart2 << endl;

    return 0;
}
