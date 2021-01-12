#include <iostream>
#include <string>
#include <ctime>
using namespace std;

int main(){
    string x[9] = {"A", "B+", "B", "C+", "C", "D+", "D", "F", "W"};
    srand(time(0));
    int grade;

    cout << "Press Enter 3 times to reveal your future.";
    cin.get();
    cin.get();
    cin.get();
    grade = rand()%9;

    cout << "You will get "<< x[grade] <<" in this 261102.";
    
    return 0;
}


