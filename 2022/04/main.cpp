#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

int main()
{
    ifstream input("input.txt");
    string data((istreambuf_iterator<char>(input)), istreambuf_iterator<char>());

    vector<string> lines;
    istringstream iss(data);
    string line;
    
    while (getline(iss, line)) {
        lines.push_back(line);
    }

    int partOne = 0;
    int partTwo = 0;

    for (const auto& line : lines) {
        vector<string> parts;
        istringstream iss(line);
        string part;
        while (getline(iss, part, ',')) {
            parts.push_back(part);
        }

        if (parts.size() != 2) {
            continue;
        }

        int s1, e1, s2, e2;
        sscanf(parts[0].c_str(), "%d-%d", &s1, &e1);
        sscanf(parts[1].c_str(), "%d-%d", &s2, &e2);

        // (s2,e2) is fully contained in (s1,e1) if s1<=s2 and e2<=e1
        if (s1 <= s2 && e2 <= e1 || s2 <= s1 && e1 <= e2) {
            ++partOne;
        }

        // (s2,e2) overlaps (s1,e1) if it is not completely to the left or completely to the right
        //    s2 -- e2
        //    e1 -- s1
        if (!(e1 < s2 || s1 > e2)) {
            ++partTwo;
        }
    }

    cout << "Answer for part one: " << partOne << "\n";
    cout << "Answer for part two: " << partTwo << "\n";

    return 0;
}
