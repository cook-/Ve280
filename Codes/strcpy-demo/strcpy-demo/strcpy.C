#include <iostream>
using namespace std;

void strcpy(char *dest, char *src)
// REQ: src is a NULL-terminated string
//      dest is big enough to hold a copy of src
// MOD: dest
// EFF: place a copy of src in dest
{
    while (*src)
    {
        *dest++ = *src++;
    }
    *dest = '\0';
}

void strncpy(char *dest, const char *src,
             unsigned int length)
// REQ: src is NUL-terminated string
//     dest has room for length+1 characters
// MOD: dest
// EFF: copy src to dest up to and including
//     the first length characters;
//     terminate dest with NUL
{
    while (length-- && *src)
    {
        *dest++ = *src++;
    }
    *dest = '\0';
}

int main(int argc, char *argv[])
{
    //char hello[] = "HELLO";
    char hello_world[] = "HELLO WORLD AND VE280!";
    char hello_cpy[11];
    
    //strcpy(hello_cpy, hello);
    //cout << hello_cpy << endl;

    //strcpy(hello_cpy, hello_world);
    strncpy(hello_cpy, hello_world, 10);
    cout << hello_cpy << endl;

    return 0;
}

