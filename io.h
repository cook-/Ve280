#ifndef IO_H
#define IO_H

#include <string>
using namespace std;

double getParam(const string& prompt);
// EFFECTS: prints the prompt, and reads a double from cin.
// Returns the value it reads.

void printHeader();
// EFFECTS: prints out a nice header for the table recording the
// simulation process.
// MODIFIES: cout

void printData(int second, double mouseAngle, double catAngle,
	double catRadius);
// EFFECTS: prints out a row in the simulation table.
// MODIFIES: cout

void printResult(bool catches);
// EFFECTS: prints out the final result of whether the cat catches
// the mouse.
// MODIFIES: cout

#endif
