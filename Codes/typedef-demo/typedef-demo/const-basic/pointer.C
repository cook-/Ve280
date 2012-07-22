#include <iostream>
using namespace std;

typedef const int constInt;
typedef constInt * ptrConstInt;

typedef int * ptrInt;
typedef const ptrInt constPtrInt;

int main(int argc, char *argv[])
{
    int a = 0;
    ptrConstInt b = &a;
    int c;
    b = &c;
    //*b = 5;

    constPtrInt d = &a;
    *d = 5;
    //d = &c;
    return 0;
}
