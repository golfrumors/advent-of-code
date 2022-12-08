#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <map>
#include <string>
#include <ranges>

using namespace std;

//find intersect of two strings
char strIntersect(string const&s1, string const&s2){

    vector<bool> presents(256, false);
    char intersection;

    for (auto c : s1) {
        presents[c] = true;
    }
    for (auto c : s2) {
        if (presents[c]){
            intersection = c;
            presents[c] = false;
        }
    }
    return intersection;
}

int calculatePriority(char const&c){
	int answer = int(c);

	if(toupper(c) == c){
		//character is capital
		answer -= 38;
	} else {
		answer -= 96;
	}

	return answer;
}

void partOne(ifstream& file){
	string p1, p2, tmp;
	int sum = 0;
	
	while(file >> tmp){
		p1 = tmp.substr(0, tmp.length()/2);
		p2 = tmp.substr(tmp.length()/2);
		sum += calculatePriority(strIntersect(p1, p2));

		p1 = "";
		p2 = "";
	}

	cout << "Answer for part one: " << sum << endl;
}

vector<string> parseInput(ifstream&file){
	vector<string> v;
	string tmp;

	while(file >> tmp){
		v.push_back(tmp);
	}

	return v;
}

uint64_t partTwo(vector<string> rucksacks) {
    // pre-sort the input
    std::ranges::for_each(rucksacks, ranges::sort);

    uint64_t result = 0;

    for (size_t i = 0; i+2 < rucksacks.size(); i+=3) {
        
        vector<char> tmp;
        std::ranges::set_intersection(rucksacks[i], rucksacks[i+1], back_inserter(tmp));
        
        vector<char> out;
        std::ranges::set_intersection(tmp, rucksacks[i+2], std::back_inserter(out));
        
        
        if (out.size() == 0) std::abort();
        else{
        	result += calculatePriority(out[0]);
        }
    }
    return result;
}

int main(){
	ifstream input("input.txt");
	vector<string> parsed = parseInput(input);

	partOne(input);
	uint64_t tmp = partTwo(parsed);

	cout << tmp;

	return 0;
}