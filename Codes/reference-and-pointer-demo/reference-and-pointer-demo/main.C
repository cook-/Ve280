#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
    cout << "------Using Reference------" << endl;
    int x = 0;
    int &rx = x;
    cout << "(x = 0; rx = x;)" << endl;
    cout << "> rx = " << rx << "; x = " << x << endl;

    rx = 1;
    cout << "(rx = 1;)" << endl;
    cout << "> rx = " << rx << "; x = " << x << endl;

    int y = 2;
    rx = y;
    cout << "(y = 2; rx = y;)" << endl;
    cout << "> rx = " << rx << "; x = " << x
        << "; y = " << y << endl;

    rx = 3;
    cout << "(rx = 3;)" << endl;
    cout << "> rx = " << rx << "; x = " << x
        << "; y = " << y << endl;

    cout << "------Using Pointer------" << endl;
    int a = 0;
    int *p = &a;
    cout << "(a = 0; *p = &a;)" << endl;
    cout << "> *p = " << *p << "; a = " << a << endl;

    *p = 1;
    cout << "(*p = 1;)" << endl;
    cout << "> *p = " << *p << "; a = " << a << endl;

    int b = 2;
    p = &b;
    cout << "(b = 2; p = &b;)" << endl;
    cout << "> *p = " << *p << "; a = " << a
        << "; b = " << b << endl;

    *p = 3;
    cout << "(*p = 3;)" << endl;
    cout << "> *p = " << *p << "; a = " << a
        << "; b = " << b << endl;

    return 0;
}
