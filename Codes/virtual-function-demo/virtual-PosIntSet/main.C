#include <iostream>
#include "IntSet.h"

using namespace std;

int main() 
{
    PosIntSet s;
/*
    try {
          s.insert(-1);
    } catch (int i) {
          cout << "Exception thrown" << endl;
    }
*/
/*
    IntSet& r = s;
    try {
          r.insert(-1);
    } catch (int i) {
          cout << "Exception thrown" << endl;
    }
*/
    IntSet* p = &s;
    try {
          p->insert(-1);
    } catch (int i) {
          cout << "Exception thrown" << endl;
    }
    return 0;
}
