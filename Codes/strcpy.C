// copy the C-style string from src to dest.

#include <iostream>
using namespace std;

int
strlen(const char *);
void
strcpy(char *, const char *);

int 
main()
{
	const char *str = "C++ language";
	for (int i = 0; i != strlen(str); ++i)
		cout << *(str + i);
	cout << endl;

	char *copied_str;
	strcpy(copied_str, str);
	for (int i = 0; i != strlen(copied_str); ++i)
		cout << *(copied_str + i);
	cout << endl;

	return 0;
}

int
strlen(const char * str)
{
	int *p = str;
	while (*p)
		++p;
	return (p - s);
}

void
strcpy(char *dest, const char *src)
{
	length = strlen(src);
	while (length-- && *src)
		*dest++ = *src++;
	*dest = '\0';
	return dest;
}
