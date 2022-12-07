#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() { 
    ifstream input("input.txt"); 
    string value; 
    getline(input, value); 
    vector<char> a; 
    int i = 0; 
    while (a.size() < 4){ 
        if (find(a.begin(), a.end(), value[i]) == a.end()){ 
            a.push_back(value[i]); 
        } else { 
            a.erase(a.begin(), find(a.begin(), a.end(), value[i]) + 1);
            a.push_back(value[i]); 
        } 
        i++; 
    } 
    cout << "Answer for part one: " << i << endl; 

    i = 0;

    while (a.size() < 14){ 
        if (find(a.begin(), a.end(), value[i]) == a.end()){ 
            a.push_back(value[i]); 
        } else { 
            a.erase(a.begin(), find(a.begin(), a.end(), value[i]) + 1);
            a.push_back(value[i]); 
        } 
        i++; 
    } 

    cout << "Answer for part two: " << i << endl;

    return 0; 
}