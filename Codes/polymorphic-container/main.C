#include <iostream>
#include <cassert>
#include "bigthing_t.h"
//#include "object_t.h"
#include "list_t.h"
using namespace std;

int main(int argc, char *argv[])
{
	List l;
	BigThing *a = new BigThing(5); // Must dynamically allocate the object
	l.insert(a);
    // l is (5)

	List ll;
	BigThing *b = new BigThing(4);
	ll.insert(b);
    // ll is (4)
	ll = l; // call assignment operator
    // ll is (5)
	BigThing *c = new BigThing(3);
	ll.insert(c);
    // ll is (3 5)

	BigThing *d = dynamic_cast<BigThing*>(ll.remove());
	assert(d);
	cout << d->get_value() << endl;
	delete d; // Must delete d!

	return 0;
}
