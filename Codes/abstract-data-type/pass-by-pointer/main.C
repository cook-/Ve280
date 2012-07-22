#include "anInt.h"
#include <iostream>

using namespace std;

void add_one(anInt *i)
{
    i->set_value(i->get_value()+1);
}

int main() 
{
    anInt foo;
    foo.set_value(0);
    add_one(&foo);
    cout << foo.get_value() << endl;
    return 0;
}
