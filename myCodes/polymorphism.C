#include <iostream>
using namespace std;

class A
{
public:
	void foo() { cout << "A::foo() is called." << endl; }
};

class B: public A
{
public:
	void foo() { cout << "B::foo() is called." << endl; }
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
	return 0;
}
