// copy string from src to dest.

#include <iostream>
#include <string>
using namespace std;

char *
strncpy(char *, const char *, size_t);

int 
main()
{
	const char *str = "C++ language";
	for (size_t i = 0; i != 13; ++i)
		cout << str[i];
	cout << endl;
	
	char str_cpy[20];
	strncpy(str_cpy, str, 20);
	for (size_t i = 0; i != 20; ++i)
		cout << str_cpy[i];
	cout << endl;
	return 0;
}

char *
strncpy(char *dest, const char *src, size_t n)
{
	size_t i;
	for (i = 0; i != n && src[i] != '\0'; ++i)
		dest[i] = src[i];
	for (; i != n; ++i)
		dest[i] = '\0';
	return dest;
}
