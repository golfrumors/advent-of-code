#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void solutionPt1(){
    ifstream file("input.txt");
    string key;
    int value = 0;
    unsigned long long sumForward = 0, sumUp = 0, sumDown = 0;

    while(file >> key >> value){
        if(key == "down"){
            sumDown += value;
        }
        else if(key == "up"){
            sumUp += value;
        }
        else{
            sumForward += value;
        }
    }

    sumDown -= sumUp;

    cout << "Sum of forward distance " << sumForward << endl;
    cout << "Sum of downward distance " << sumDown << endl;
    cout << "Final vector of distance (multiplied) " << (sumForward * sumDown) << endl;
}

void solutionPt2(){
    ifstream file("input.txt");
    string key;
    unsigned  long  long value = 0, totalDistance = 0, aim = 0, sumForward = 0;


    while(file >> key >> value){
        if(key == "down"){
            aim += value;
        }
        else if(key == "up"){
            aim -= value;
        }
        else{
            sumForward += value;
            totalDistance += (value * aim);
        }
    }

    cout << "Sum of aim " << aim << endl;
    cout << "Sum of distance " << totalDistance << endl;

    cout << "Final vec (multiplied): " << (totalDistance * sumForward) << endl;
}

int main(){
    
    cout << "Solution for part one: \n";
    solutionPt1();
    cout << endl;
    cout << "Solution for part two: \n";
    solutionPt2();
    
    return 0;
}
