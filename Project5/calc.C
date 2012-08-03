#include "dlist.h"
#include "dlist.C"
#include <iostream>
#include <string>
#include <cstdlib>
#include <cassert>
using namespace std;

void plus(Dlist<int> &);	
void minus(Dlist<int> &);
void multiply(Dlist<int> &);
void divide(Dlist<int> &);
void negate(Dlist<int> &);
void duplicate(Dlist<int> &);
void reverse(Dlist<int> &);
void print(Dlist<int> &);
void clear(Dlist<int> &);
void printAll(Dlist<int> &);
void quit(Dlist<int> &);
bool checkValid(const string);

int
main()
{
	Dlist<int> ilist;
	int *ip = 0;
	string cmd;
	cin >> cmd;
	if (cmd.size() == 1)
		switch (cmd[0])
		{
			case '+': pluss(ilist);		break;
			case '-': minus(ilist);		break;
			case '*': multiply(ilist);	break;
			case '/': divide(ilist);	break;
			case 'n': negate(ilist);	break;
			case 'd': duplicate(ilist);	break;
			case 'r': reverse(ilist);	break;
			case 'p': print(ilist);		break;
			case 'c': clear(ilist);		break;
			case 'a': printAll(ilist);	break;
			case 'q': quit(ilist);			break;
		}

	else {
		if (!checkValid(cmd))
			cout << "Bad input\n";
		else {
			ip = new int(atoi(cmd.c_str()));
			ilist.insertFront(ip);
		}
	}


	return 0;
}

void pluss(Dlist<int> &ilist)
{
	
}

void minus(Dlist<int> &ilist){}
void multiply(Dlist<int> &ilist){}
void divide(Dlist<int> &ilist){}
void negate(Dlist<int> &ilist){}
void duplicate(Dlist<int> &ilist){}
void reverse(Dlist<int> &ilist){}
void print(Dlist<int> &ilist){}
void clear(Dlist<int> &ilist){}
void printAll(Dlist<int> &ilist){}
void quit(Dlist<int> &ilist){}

bool checkValid(string str)
{
	return true;
}
