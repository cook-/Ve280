#include <iostream>
#include <iomanip>
#include "io.h"

double getParam(const string& prompt)
{
	double result;
	cout << prompt;
	cin >> result;
    return result;
}

void printHeader()
{
    cout << endl;
    cout << "Second\tMouse Angle\tCat Angle\tCat Radius" << endl;
    cout << "------\t-----------\t---------\t----------" << endl;
}

void printData(int second, double mouseAngle, double catAngle,
	double catRadius)
{
    cout << second << "\t" << fixed << setprecision(2) 
	 << setw(11) << mouseAngle << "\t" 
	 << setw(9) << catAngle << "\t" 
	 << setw(10) << catRadius << endl;
}

void printResult(bool catches)
{
	cout << "The cat " << (catches?"catches":"does not catch")
		<< " the mouse!" << endl;
}
