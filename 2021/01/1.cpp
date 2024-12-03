// read from file of depth numbers, spit out how many of them are larger than the first
// golfrumros 2022-11-15

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

vector<int> fileToVector(string file){
    int depth;
    string tmp;
    vector<int> depths_coll = {};
    ifstream depthFile(file);

    while(depthFile >> tmp){
        depth = stoi(tmp);
        depths_coll.push_back(depth);
    }

    depthFile.close();
    return depths_coll;
}

//takes our
int part_one(vector<int>& v){
    
    int count = 0;

    for(int i = 1; i < v.size(); i++){
        if(v[i] > v[i-1]){
            count++;
        }
    }

    return count;
}

int part_two(vector<int>& v){
    int count = 0;
    int sum1 = 0, sum2 = 0;

    for(int i = 3; i < v.size(); i++){
        sum1 = v[i-1] + v[i-2] + v[i-3];
        sum2 = v[i] + v[i-1] + v[i-2];
        if(sum2 > sum1){
            count++;
        }
    }

    return count;
}

int main(){
    vector<int> depths = fileToVector("1.txt");
    cout << "Answer for part one: " << part_one(depths) << endl;
    cout << "Answer for part two: " << part_two(depths) << endl;
    return 0;
}