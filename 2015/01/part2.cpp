#include <bits/stdc++.h>

using namespace std;

int main() {
    string in;
    int ans = 0, i = 0;
    
    ifstream file("input");
    file >> in;
    
    for(char c : in) {
        if (c == '(') ans++;
        else ans--;
        if (ans == -1) { cout << "Part 2 : " << i+1 << endl; break; }
        i++;
    }

    file.close();

    return 0;
}
