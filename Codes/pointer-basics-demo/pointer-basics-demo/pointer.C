#include <iostream>
using namespace std;

void add_one(int *x)
{
    *x = *x+1;
}

int main(int argc, char *argv[])
{
    int foo;
    int *bar;
    bar = &foo;
    foo = 1;
    *bar = 2;
    add_one(bar);
    return 0;
}

