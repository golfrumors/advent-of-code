#include <bits/stdc++.h>

using namespace std;

int main() {
    string line;
    int answer1 = 0;
    int answer2 = 0;

    ifstream file("input");

    while (getline(file, line)) {
        stringstream ss(line);
        int l, w, h;
        char x;

        ss >> l >> x >> w >> x >> h;

        int surface = 2 * l * w + 2 * w * h + 2 * h * l;

        int side1 = l * w;
        int side2 = w * h;
        int side3 = h * l;

        int extra = min(side1, min(side2, side3));
        answer1 += surface + extra;

        int perim1 = 2 * l + 2 * w;
        int perim2 = 2 * w + 2 * h;
        int perim3 = 2 * h + 2 * l;

        int minPerim = min(perim1, min(perim2, perim3));

        int vol = l * w * h;

        answer2 += minPerim + vol;
    }
    
    cout << "Part 1 : " << answer1 << endl;
    cout << "Part 2 : " << answer2 << endl;

    file.close();

    return 0;
}
