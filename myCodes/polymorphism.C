#include <iostream>
using namespace std;

class A
{
public:
	virtual void foo() { cout << "A::foo() is called." << endl; }
};

class B: public A
{
public:
	virtual void foo() { cout << "B::foo() is called." << endl; }
};

void bar(A *a)
{
	a->foo();
}

int main()
{
	A *a = new A;
	B *b = new B;
	bar(a);
	bar(b);
	A a1;
	a1.foo();
	return 0;
}
