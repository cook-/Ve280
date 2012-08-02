#include <iostream>
#include "list.h"
#include "list.C"
using namespace std;

int main(int argc, char *argv[])
{
	List<int> li; // call default constructor
	li.insert(1);
	li.insert(5);
    // li is (5 1)

	List<int> lp(li); // call copy constructor
    // lp is (5 1)

	List<int> ln;
	ln = li;    // call assignment operator
    // ln is (5 1)

    // lp is (5 1)
	cout << lp.remove() << " "<< flush;
    cout << lp.remove() << endl;

	ln.insert(4);
    // ln is (4 5 1)
	cout << ln.remove() << " " << flush;
    cout << ln.remove() << " " << flush;
    cout << ln.remove() << endl;

	return 0;
}
