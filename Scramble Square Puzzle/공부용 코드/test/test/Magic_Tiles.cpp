#include "Magic_Tiles.h"
#include <iostream>
#include <fstream>
using namespace std;



Magic_Tiles::Magic_Tiles(ifstream& inFile){		// Constructor receives the filestream and construct the tile into an array.
	for (int i = 0; i < 9; i++) {				// Each tile has an array-representation of their edges values, as well as 
		Tile aTile;								// a rotation number to indicate its orientation.
		inFile >> aTile.name;
		for (int j = 0; j < 4; j++) {
			inFile >> aTile.numArray[j];
		}
		tileArray[i] = aTile;
	}
	cout << "Original Configuration: " << endl;
	printBoard();
	cout << endl;
}


void Magic_Tiles::solve(int index) {
	if (found)							// If found, the recursive calls are ended and the function returns.
		return;

	else if (index == 9) {				// If the index has reached , then all comparisons have evaluated as true and the solution
		cout << "Solution 1 of 4: " << endl;	// has been found. Result is printed, found made true to end calls, and the function returns.
		printBoard();
		found = true;
		return;
	}

	else {
		for (int i = index; i < 9; i++) {
			swap(index, i);
			for (int j = 0; j < 4; j++) {		// First-tile case, has no tiles for comparison.
				if (index == 0) {
					solve(index + 1);
					if (!found)
						rotateTile(index);
				}
				else if (edgesMatch(index)) {	// Tiles 2-9, will only proceed solving if edges match for current position.
					solve(index + 1);
				}
				else
					rotateTile(index);				// Rotates to look further for a match before placing a different tile.
			}
			if (found)							// Returns as soon as solution is found, rather than swapping 
				return;							// everything back after the solution is found.
			else
				swap(index, i);					// If solution is not found, swap is called to proceed to next permutation.
		}
	}
}

void Magic_Tiles::rotateBoard() {			// Rotates the entire the board to display other solutions.
	Tile tempTileArray[9];
	for (int i = 0; i < 9; i++) {rotateTile(i);}

	tempTileArray[0] = tileArray[6];
	tempTileArray[1] = tileArray[3];
	tempTileArray[2] = tileArray[0];
	tempTileArray[3] = tileArray[7];
	tempTileArray[4] = tileArray[4];
	tempTileArray[5] = tileArray[1];
	tempTileArray[6] = tileArray[8];
	tempTileArray[7] = tileArray[5];
	tempTileArray[8] = tileArray[2];

	for (int j = 0; j < 9; j++) {tileArray[j] = tempTileArray[j];}
}

void Magic_Tiles::printBoard() {			// Prints current configuration of the board.
	for (int i = 0; i < 9; i += 3) {
		cout << tileArray[i].name << tileArray[i].rotation << ' ';
		cout << tileArray[i + 1].name << tileArray[i + 1].rotation << ' ';
		cout << tileArray[i + 2].name << tileArray[i + 2].rotation << endl << endl;
	}
}

void Magic_Tiles::swap(int x, int y) {			// Swpas tiles on the board.
	Tile temp = tileArray[x];
	tileArray[x] = tileArray[y];
	tileArray[y] = temp;
}

void Magic_Tiles::rotateTile(int tileNum) {			// Rotates the current tile in use, advancing the numbers in the array-representation.
	int temp = tileArray[tileNum].numArray[3];
	for (int k = 3; k > 0; k--) {
		tileArray[tileNum].numArray[k] = tileArray[tileNum].numArray[k - 1];
	}
	tileArray[tileNum].numArray[0] = temp;
	if (tileArray[tileNum].rotation == 3)
		tileArray[tileNum].rotation = 0;
	else
		tileArray[tileNum].rotation++;
}

bool Magic_Tiles::edgesMatch(int position) {	// Comparing the edges of a tile to its 'placed' neighbors according to position.
	switch (position) {							// First position (0) has no comparison.

		case 1: return (tileArray[0].numArray[1] + tileArray[1].numArray[3] == 0);

		case 2: return (tileArray[1].numArray[1] + tileArray[2].numArray[3] == 0);

		case 3: return (tileArray[0].numArray[2] + tileArray[3].numArray[0] == 0);

		case 4: return (tileArray[3].numArray[1] + tileArray[4].numArray[3] == 0)
			&& (tileArray[1].numArray[2] + tileArray[4].numArray[0] == 0);

		case 5: return (tileArray[4].numArray[1] + tileArray[5].numArray[3] == 0)
			&& (tileArray[2].numArray[2] + tileArray[5].numArray[0] == 0);

		case 6: return (tileArray[3].numArray[2] + tileArray[6].numArray[0] == 0);

		case 7: return (tileArray[6].numArray[1] + tileArray[7].numArray[3] == 0)
			&& (tileArray[4].numArray[2] + tileArray[7].numArray[0] == 0);

		case 8: return (tileArray[7].numArray[1] + tileArray[8].numArray[3] == 0)
			&& (tileArray[5].numArray[2] + tileArray[8].numArray[0] == 0);

		default: return true;
	}
}

Magic_Tiles::~Magic_Tiles() {}