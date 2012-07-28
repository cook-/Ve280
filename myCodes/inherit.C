#include <iostream>
using namespace std;

class A
{
public:
	void A1() { cout << "A1() is called." << endl; }
};

class B: public A
{
public:
	void A1() { cout << "B1() is called." << endl; }
};

// ambiguous
/*
class C: public B, public A
{

};
*/

int
main()
{
	A a;
	B b;
	C c;
	a.A1();
	b.A1();
//	c.A1();
	return 0;
}
