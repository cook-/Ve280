// count the length of a C-style string not counting the NULL.

#include <iostream>
using namespace std;

int
strlen(const char *);

int
main()
{
	const char *str = "C++ language";
	cout << "string length of \"C++ language\" is " << strlen(str) << endl;
}

int
strlen(const char *str)
{
	int i = 0;
	while (str[i++] != '\0')
		;
	return i - 1;
}
