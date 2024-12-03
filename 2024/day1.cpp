#include <bits/stdc++.h>

using namespace std;

int main() {
    vector<int> a(1000), b(1000);
    unordered_map<int, int> freqB;
    long long result = 0;
    long long result2 = 0;

    for(int i = 0; i <= 1000; i++) {
        cin >> a[i] >> b[i];
        freqB[b[i]]++;
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    for(int i = 0; i <= 1000; i++) {
        result += abs(a[i] - b[i]);
        result2 += a[i] * freqB[a[i]];
    }

    cout << "Part 1 : " << result << endl;
    cout << "Part 2 : " << result2 << endl;

    return 0;
}
