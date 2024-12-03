#include <bits/stdc++.h>

using namespace std;

int main() {
    string line;
    vector<string> input;

    while (getline(cin, line)) {
        input.push_back(line);
    }

    //this gave me chlamydia i think
    regex pattern("mul\\((\\d+),(\\d+)\\)|(do|don't)\\(\\)");

    bool enabled = true;
    int answer = 0, filtered = 0;

    for (const string& s : input) {
        auto begin = s.cbegin();
        auto end = s.cend();
        smatch match;

        while (regex_search(begin, end, match, pattern)) {
            if (match[0].str().substr(0, 3) == "mul") {

                int num1 = stoi(match[1].str());
                int num2 = stoi(match[2].str());
                answer += num1 * num2;
                if (enabled) {
                    filtered += num1 * num2;
                }
            } else {
                enabled = (match[3].str() == "do");
            }
            begin = match.suffix().first;
        }
    }

    cout << "Part 1: " << answer << endl;
    cout << "Part 2: " << filtered << endl;

    return 0;
}
