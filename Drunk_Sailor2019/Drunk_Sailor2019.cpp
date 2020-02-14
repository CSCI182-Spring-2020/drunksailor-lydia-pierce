/* Lydia Pierce
Intro to Data Structures
Drunk_Sailor2019.cpp
v1.0 2/12/2020
*/


#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>		// For the clock to seed the random number
using namespace std;

/// <summary>
/// Defines the constant variables in the program
/// </summary>
constexpr auto Array_WIDTH = 20;
constexpr auto Array_HEIGHT = 20;
constexpr auto MAX_STEPS = 1000;

enum Direction { NORTH, EAST, SOUTH, WEST };	// Create an enum for the direction he goes

int nMapArray[Array_WIDTH][Array_HEIGHT];		// Declare the array

int main()
{
	srand(time(NULL));		// Seed the random number with the computer clock
	
	// Zero out the array
	for (int xcounter = 0; xcounter < Array_WIDTH; xcounter++)
		for (int ycounter = 0; ycounter < Array_HEIGHT; ycounter++)
			nMapArray[xcounter][ycounter] = 0;
	
	int x = Array_WIDTH / 2;		// Set the starting point on the array
	int y = Array_HEIGHT / 2;
	int StepCount = 0;
	
	// Depending on the direction he goes determined by the random number, move the sailor and increment the value of the array in that spot
	while (StepCount < MAX_STEPS)
	{
		Direction nNextStep = static_cast<Direction>(rand() % 4);
		int nCurrentValue = nMapArray[x][y];
		switch (nNextStep)
		{
		case NORTH:
			if (y > 0) { y--; nMapArray[x][y]++; break; }
			else { nMapArray[x][y]++; break; }
		case EAST:
			if (x > 0) { x--; nMapArray[x][y]++; break; }
			else { nMapArray[x][y]++; break; }
		case SOUTH:
			if (y > 0) { y++; nMapArray[x][y]++; break; }
			else { nMapArray[x][y]++; break; }
		case WEST:
			if (x > 0) { x++; nMapArray[x][y]++; break; }
			else { nMapArray[x][y]++; break; }
		}
		StepCount++;
	}

	// Print the array to the screen with the values of how many times he stepped there
	for (x = 0; x < Array_WIDTH; x++)
	{
		for (y = 0; y < Array_HEIGHT; y++)
		{
			cout << nMapArray[x][y] << "\t";
		}
		std::cout << endl;
	}
	return 0;
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
