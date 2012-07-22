#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main(int argc, char *argv[])
{
    int foo = 512;
    int bar = 1024;
    string result;
    ostringstream oStream;
    oStream << foo << " " << bar << flush;

    result = oStream.str();
    cout << result << endl;

    return 0;
}
