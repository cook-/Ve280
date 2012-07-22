#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
    int a = 0;
    const int *b = &a;
    int c;
    b = &c;
    //*b = 5;

    //int *const d = &a;
    //*d = 5;
    //d = &c;
    return 0;
}

