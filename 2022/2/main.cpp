#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main(){
	ifstream file("input.txt");
	vector<char> move, Sug;
	char m, s;
	int points;

	//a = rock b = paper c = scissors
	//x = rock y = paper c = scissors

	while(file >> m >> s){
		move.push_back(m);
		Sug.push_back(s);
	}

	for(int i = 0; i < move.size(); i++){
		if(move[i] == 'A' && Sug[i] == 'Y'){
			points += 6;
		}

		if(move[i] == 'B' && Sug[i] == 'Z'){
			points += 6;
		}

		if(move[i] == 'C' && Sug[i] == 'X'){
			points += 6;
		}

		if(Sug[i] == 'X'){
			points += 1;
		} else if(Sug[i] == 'Y'){
			points += 2;
		} else {
			points += 3;
		}

		if(move[i] == 'A' && Sug[i] == 'X' || move[i] == 'B' && Sug[i] == 'Y' || move[i] == 'C' && Sug[i] == 'Z') {
			points += 3;
		}

	}

	cout << "Total of points for part one: " << points;

	points = 0;

	for(int i = 0; i < move.size(); i++){
		switch(move[i]){
			case 'A':
				if(Sug[i] == 'X'){
					points += 3; 
				} else if(Sug[i] == 'Y'){
					points += 3;
					points += 1;
				} else if(Sug[i] == 'Z'){
					points += 6;
					points += 2;
				}
				break;
			case 'B':
				if(Sug[i] == 'X'){
					points += 1;
				} else if(Sug[i] == 'Y'){
					points += 3;
					points += 2;
				} else if(Sug[i] == 'Z'){
					points += 6;
					points += 3;
				}
				break;
			case 'C':
				if(Sug[i] == 'X'){
					points += 2;
				} else if(Sug[i] == 'Y'){
					points += 3;
					points += 3;
				} else if(Sug[i] == 'Z'){
					points += 6;
					points += 1;
				}
				break;
		}
	}

	cout << "\nTotal of points for part two: " << points;

	return 0;
}