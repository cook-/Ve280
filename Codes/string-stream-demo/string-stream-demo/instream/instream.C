#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main(int argc, char *argv[])
{
    string line;
    int foo;
    double bar;
    istringstream iStream;

    cout << "Please input an int and a double: " << flush;
    getline(cin, line);

    iStream.str(line);
    iStream >> foo >> bar;

    cout << foo << endl;
    cout << bar << endl;

    return 0;
}
