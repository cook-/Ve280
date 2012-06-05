// Simulation of the hunting process. 
// Prompt the user to input the initial mouse_agl, cat_agl and cat_r, and the program will print a table and the final result.

#include "io.h"
#include <iostream>
#include <cmath>
#define pi 3.1415927

int main()
{
	const double base_r = 1;
	double mouse_agl, cat_agl, cat_r;

	// Get parameters from the user.
	mouse_agl = getParam("Please enter the initial mouse angle: ");
	cat_agl = getParam("Please enter the initial cat angle: ");
	while ((cat_r = getParam("Please enter the initial cat radius: ")) < base_r)
		cout << "Error: the cat radius is less than the base radius 1!" << endl;

	// Convert angles into the interval [0, 360).
	mouse_agl = fmod(mouse_agl, 360) + 360 * (mouse_agl < 0);
	cat_agl = fmod(cat_agl, 360) + 360 * (cat_agl < 0);

	const int max_time = 30;
	const double mouse_aglv = 1;
	const double cat_aglv = 1.25;
	const double cat_v = 1;
	const double critical_agl = (cat_aglv - mouse_aglv)/base_r * (180/pi);
	double diff_agl;
	bool catches = 0;
	int second = 0;

	// Print the table header.
	printHeader();

	// Print the table content.
	while (!catches && second != max_time + 1) {
		printData(second, mouse_agl, cat_agl, cat_r);

		diff_agl = mouse_agl - cat_agl;
		diff_agl += 360 * (diff_agl < 0);
		if (diff_agl <= critical_agl)
			catches = !catches;

		if (cat_r * cos((cat_agl - mouse_agl) * (pi/180)) < base_r)
			cat_agl += (cat_aglv/cat_r) * (180/pi);
		else if (cat_r - cat_v < base_r)
			cat_r = base_r;
		else
			cat_r -= cat_v;
		mouse_agl += (mouse_aglv/base_r) * (180/pi);

		cat_agl -= 360 * (cat_agl >= 360);
		mouse_agl -= 360 * (mouse_agl >= 360);

		++second;
	}

	if (catches)
		printData(second, mouse_agl, cat_agl, cat_r);

	// Print the result.
	printResult(catches);

	return 0;
}
