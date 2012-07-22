#include <iostream>
using namespace std;

int strlen(const char *s)
  // REQUIRES: s is a NUL-terminated
  //           C-string
  // EFFECTS: returns the length of s,
  //          not counting the NUL.  For
  //          example, strlen("foo")
  //          returns 3.
{
    const char *p = s;
    while(*p++) ;
    return (p-s-1);
}

int main(int argc, char *argv[])
{
    char empty[] = "";
    char one[] = "0";
    char hello[] = "hello";

    cout << "The length of string empty is " << strlen(empty)
        << endl;
    cout << "The length of string one is " << strlen(one)
        << endl;
    cout << "The length of string hello is " << strlen(hello)
        << endl;

    return 0;
}
