//by Daniel Moreno in COSC 1437

#include <iostream>
#include <string>
#include <math.h>
using namespace std;

void towers(int number, string start, string finish, string extra){
	if (number == 0) {
		return;
	} else {
		//move n-1 discs to temporary peg before moving final disc to final peg
		towers(number - 1, start, extra, finish);
		cout << "Move disk " << number << " from rod " << start << " to rod " << finish << endl;
		//move n-1 discs to final peg from temporary peg
		towers(number - 1, extra, finish, start);
	}
}

int main() {
	int numDiscs;

	cout << "Please enter the number of discs to move ";
	cin >> numDiscs;

	//For n discs, it takes 2^n - 1 moves
	int moves = pow(2, numDiscs) - 1;
	cout << "Number of moves to solve: " << moves << endl;
	towers(numDiscs, "A", "C", "B");
	system("pause");
}