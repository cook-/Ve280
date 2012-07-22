#include <iostream>
using namespace std;

int const_ptr(const int *a)
{
    return (*a);
}

int nonconst_ptr(int *a)
{
    return (*a);
}

int main(int argc, char *argv[])
{
    int a = 0;
    //int *b = &a;
    const int *c = &a;
    cout << const_ptr(b) << endl;
    //cout << nonconst_ptr(c) << endl;
    return 0;
}

