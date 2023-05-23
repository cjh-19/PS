//OLA 4.2

#include <fstream>
#include <iostream>
#include <string>
#include "Magic_Tiles.h"
using namespace std;

int main() {
	char moreSolutions;
	ifstream inFile;
	inFile.open("ola4data.txt");

	Magic_Tiles ola4(inFile);	// Creates instance of the puzzle board.
	ola4.solve(0);				// Solves puzzle.

	cout << endl << "Would you like to see the other three solutions?" << endl;

	cout << "Enter Y for yes, or any key to quit: ";
	cin >> moreSolutions;							// As there are four solutions, after finding one
	moreSolutions = toupper(moreSolutions);			// the user is asked if they would like to see the 
													// other 3 solutions.
	if (moreSolutions == 'Y') {
		for (int i = 2; i < 5; i++) {
			cout << endl << "Solution " << i << " of 4:" << endl;
			ola4.rotateBoard();						// Rotates the board and prints other valid solutions.
			ola4.printBoard();
		}
	}
	cout << endl << "Good-Bye!" << endl;

	inFile.close();
	return 0;
}