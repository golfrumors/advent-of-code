#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	ifstream file("input.txt");
	string tmp;
	int sum = 0;
	vector<int> elves;

	while(getline(file, tmp)){
		if(tmp == ""){
			elves.push_back(sum);
			sum = 0;
		} else {
			sum += stoi(tmp);
		}
	}

	sort(elves.begin(), elves.end(), greater<>());

	cout << "Elf with the most calories: " << elves[0];
	
	cout << "\nSum of the top three elves with the most calories: " << elves[0] + elves[1] + elves[2];

	return 0;
}
