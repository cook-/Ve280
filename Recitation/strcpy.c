// copy string from src to dest.

#include <iostream.h>
#include <string.h>

char *
strcpy(char *, const char *, size_t);

int 
main()
{
	char *str = "C++ language";
	for (size_t i = 0; i != 13; ++i)
		cout << str[i];
	cout << endl;
	
	char *str_cpy;
	strcpy(str_cpy, src, 20);
	for (size_t i = 0; i != 20; ++i)
		cout << str_cpy[i];
	cout << endl;
	return 0;
}

char *
strcpy(char *dest, const char *src, size_t n)
{
	for (size_t i = 0; i != n && src[i] != '\0'; ++i)
		dest[i] = src[i];
	for (; i != n; ++i)
		dest[i] = '\0';
	return dest;
}
