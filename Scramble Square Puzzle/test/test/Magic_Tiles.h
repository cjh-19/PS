#pragma once

#ifndef MAGIC_TILES
#define MAGIC_TILES

#include <fstream>
#include <string>
using namespace std;

struct Tile {			// Struct to represent each tile with name, edges values and orientation.
	string name;
	int numArray[4];
	int rotation = 0;
};

class Magic_Tiles
{
public:
	Magic_Tiles(ifstream& inFile);	// Constructor
	void solve(int index);			// Solves puzzle
	void rotateBoard();				// Rotates entire board
	void printBoard();				// Prints current board configuration
	~Magic_Tiles();

private:
	bool found = false;				
	void swap(int x, int y);		// Swap function for parmutations
	void rotateTile(int tileNum);	// rotates a tile
	bool edgesMatch(int position);	// Compares edges based on position
	Tile tileArray[9];		
};
#endif

