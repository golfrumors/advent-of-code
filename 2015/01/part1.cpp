#include <bits/stdc++.h>

using namespace std;

int main() {
    string in;
    int ans = 0;
    
    ifstream file("input");
    file >> in;
    
    for(char c : in) {
        if (c == '(') ans++;
        else ans--;
    }
    
    cout << "Part 1 : " << ans << endl;

    return 0;
}
