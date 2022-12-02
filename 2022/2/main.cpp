#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main(){
	ifstream file("input.txt");
	vector<char> move, sug; //array of moves and suggested moves/outcomes
	char m, s; //m being the move made, and s being the suggested move/outcome
	int points;

	//a = rock b = paper c = scissors
	//x = rock y = paper c = scissors

	while(file >> m >> s){
		move.push_back(m);
		sug.push_back(s);
	}

	for(int i = 0; i < move.size(); i++){
		if(move[i] == 'A' && sug[i] == 'Y'){
			points += 6;
		}

		if(move[i] == 'B' && sug[i] == 'Z'){
			points += 6;
		}

		if(move[i] == 'C' && sug[i] == 'X'){
			points += 6;
		}

		if(sug[i] == 'X'){
			points += 1;
		} else if(sug[i] == 'Y'){
			points += 2;
		} else {
			points += 3;
		}

		if(move[i] == 'A' && sug[i] == 'X' || move[i] == 'B' && sug[i] == 'Y' || move[i] == 'C' && sug[i] == 'Z') {
			points += 3;
		}

	}

	cout << "Total of points for part one: " << points;

	points = 0;

	for(int i = 0; i < move.size(); i++){
		switch(move[i]){
			case 'A':
				if(sug[i] == 'X'){
					points += 3; 
				} else if(sug[i] == 'Y'){
					points += 3;
					points += 1;
				} else if(sug[i] == 'Z'){
					points += 6;
					points += 2;
				}
				break;
			case 'B':
				if(sug[i] == 'X'){
					points += 1;
				} else if(sug[i] == 'Y'){
					points += 3;
					points += 2;
				} else if(sug[i] == 'Z'){
					points += 6;
					points += 3;
				}
				break;
			case 'C':
				if(sug[i] == 'X'){
					points += 2;
				} else if(sug[i] == 'Y'){
					points += 3;
					points += 3;
				} else if(sug[i] == 'Z'){
					points += 6;
					points += 1;
				}
				break;
		}
	}

	cout << "\nTotal of points for part two: " << points;

	return 0;
}