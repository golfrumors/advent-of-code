#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

int x = 1;
int cnt = 0;
int sm = 0;
vector<vector<char>> crt(6, vector<char>(40, ' '));

void cycle() {
  cnt += 1;
  if (cnt == 20 || cnt == 60 || cnt == 100 || cnt == 140 || cnt == 180 || cnt == 220) {
    sm += cnt * x;
  }
  if (abs((cnt - 1) % 40 - x) < 2) {
    crt[(cnt - 1) / 40][(cnt - 1) % 40] = '#';
  }
}

int main() {
  vector<string> ll;
  string line;
  ifstream input("input.txt");

  // Read input into ll
  while (getline(input, line)) {
    ll.push_back(line);
  }

  // Process instructions
  for (string line : ll) {
    if (line == "noop") {
      cycle();
    } else {
      int add = stoi(line.substr(5));
      cycle();
      cycle();
      x += add;
    }
  }

  // Print the result
  cout << sm << endl;
  for (auto line : crt) {
    for (char c : line) {
      cout << c;
    }
    cout << endl;
  }

  return 0;
}
