#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

//find the gamma rate
vector<char> calculateGammaRate(fstream& file){
	string tmp;
	vector<char> result;
	int zeroCounter = 0, oneCounter = 0;

	while(file >> tmp){
		//cout << tmp << endl;

		for(int i = 0; i < tmp.size(); i++){
			if(tmp[i] == '0'){
				zeroCounter++;
			} else {
				oneCounter++;
			}
		}

		if(zeroCounter > oneCounter){
			result.push_back('0');
		} else {
			result.push_back('1');
		}
		zeroCounter = oneCounter = 0;
	}

	return result;
}

//find the epsilon rate


//convert from binary to decimal


//multiply them by eachother, spit them out really pretty

//driver code
int main(){
	//string gammaRate = "", epsilonRate = "";
	vector<char> gammaRate;
	
	fstream file("test.txt");

	gammaRate = calculateGammaRate(file);

	for(int i = 0; i < gammaRate.size(); i++){
		cout << gammaRate[i] << " ";
	}


	return 0;
}