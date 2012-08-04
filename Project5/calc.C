#include "dlist.h"
#include "dlist.C"
#include <iostream>
#include <string>
#include <cstdlib>
#include <cassert>
using namespace std;

void Plus(Dlist<int> &);	
void Minus(Dlist<int> &);
void Multiply(Dlist<int> &);
void Divide(Dlist<int> &);
void Negate(Dlist<int> &);
void Duplicate(Dlist<int> &);
void Reverse(Dlist<int> &);
void Print(Dlist<int> &);
void Clear(Dlist<int> &);
void PrintAll(Dlist<int> &);
void Quit(Dlist<int> &);
bool CheckValid(const string &);

int
main()
{
	Dlist<int> ilist;
	int *ip = 0;
	string cmd;
	while (1) {
		cin >> cmd;
		if (!CheckValid(cmd))
			cout << "Bad input\n";
		else {
			if (cmd.size() == 1)
				switch (cmd[0])	{
					case '+': Plus(ilist);		break;
					case '-': Minus(ilist);		break;
					case '*': Multiply(ilist);	break;
					case '/': Divide(ilist);	break;
					case 'n': Negate(ilist);	break;
					case 'd': Duplicate(ilist);	break;
					case 'r': Reverse(ilist);	break;
					case 'p': Print(ilist);		break;
					case 'c': Clear(ilist);		break;
					case 'a': PrintAll(ilist);	break;
					case 'q': Quit(ilist);		break;
					default: {
						ip = new int(atoi(cmd.c_str()));
						ilist.insertFront(ip);
						}
					break;
				}
			else {
				ip = new int(atoi(cmd.c_str()));
				ilist.insertFront(ip);
			}
		}
	}

	return 0;
}

void Plus(Dlist<int> &ilist)
{
	int *ap = 0;
	int *bp = 0;

	if (ilist.isEmpty())
		cout << "Not enough operands\n";

	else {
		ap = ilist.removeFront();
		if (ilist.isEmpty()) {
			ilist.insertFront(ap);
			cout << "Not enough operands\n";
		}
		else {
			bp = ilist.removeFront();
			*bp += *ap;
			delete ap;
			ilist.insertFront(bp);
		}
	}
}

void Minus(Dlist<int> &ilist)
{
	int *ap = 0;
	int *bp = 0;

	if (ilist.isEmpty())
		cout << "Not enough operands\n";

	else {
		ap = ilist.removeFront();
		if (ilist.isEmpty()) {
			ilist.insertFront(ap);
			cout << "Not enough operands\n";
		}
		else {
			bp = ilist.removeFront();
			*bp -= *ap;
			delete ap;
			ilist.insertFront(bp);
		}
	}
}

void Multiply(Dlist<int> &ilist)
{
	int *ap = 0;
	int *bp = 0;

	if (ilist.isEmpty())
		cout << "Not enough operands\n";

	else {
		ap = ilist.removeFront();
		if (ilist.isEmpty()) {
			ilist.insertFront(ap);
			cout << "Not enough operands\n";
		}
		else {
			bp = ilist.removeFront();
			*bp *= *ap;
			delete ap;
			ilist.insertFront(bp);
		}
	}
}

void Divide(Dlist<int> &ilist)
{
	int *ap = 0;
	int *bp = 0;

	if (ilist.isEmpty())
		cout << "Not enough operands\n";

	else {
		ap = ilist.removeFront();
		if (ilist.isEmpty()) {
			ilist.insertFront(ap);
			cout << "Not enough operands\n";
		}
		else {
			bp = ilist.removeFront();
			*bp /= *ap;
			delete ap;
			ilist.insertFront(bp);
		}
	}
}

void Negate(Dlist<int> &ilist)
{
	int *ip = 0;
	if (ilist.isEmpty())
		cout << "Not enough operands\n";
	else {
		ip = ilist.removeFront();
		*ip *= -1;
		ilist.insertFront(ip);
	}
}

void Duplicate(Dlist<int> &ilist)
{
	int *ip = 0;
	if (ilist.isEmpty())
		cout << "Not enough operands\n";
	else {
		int *dup = new int;
		ip = ilist.removeFront();
		*dup = *ip;
		ilist.insertFront(ip);
		ilist.insertFront(dup);
	}
}

void Reverse(Dlist<int> &ilist)
{
	int *ap = 0;
	int *bp = 0;

	if (ilist.isEmpty())
		cout << "Not enough operands\n";

	else {
		ap = ilist.removeFront();
		if (ilist.isEmpty()) {
			ilist.insertFront(ap);
			cout << "Not enough operands\n";
		}
		else {
			bp = ilist.removeFront();
			ilist.insertFront(ap);
			ilist.insertFront(bp);
		}
	}
}

void Print(Dlist<int> &ilist)
{
	int *ip = 0;
	if (ilist.isEmpty())
		cout << "Not enough operands\n";
	else {
		ip = ilist.removeFront();
		cout << *ip << endl;
		ilist.insertFront(ip);
	}
}

void Clear(Dlist<int> &ilist)
{
	int *ip = 0;
	while (!ilist.isEmpty()) {
		ip = ilist.removeFront();
		delete ip;
	}
}

void PrintAll(Dlist<int> &ilist)
{
	Dlist<int> tmplist;
	int *ip = 0;

	if (ilist.isEmpty())
		cout << "\n";

	else {
		while (!ilist.isEmpty()) {
			ip = ilist.removeFront();
			cout << *ip << " ";
			tmplist.insertBack(ip);
		}
		cout << endl;

		while (!tmplist.isEmpty()) {
			ip = tmplist.removeFront();
			ilist.insertBack(ip);
		}
	}
}

void Quit(Dlist<int> &ilist)
{
	Clear(ilist);
	exit(0);
}

bool CheckValid(const string &str)
{
	bool isValid = true;

	if (str.size() == 1) {
		if (str[0] != '+' && str[0] != '-' && str[0] != '*' && str[0] != '/' 
		  && str[0] != 'n' && str[0] != 'd' && str[0] != 'r' && str[0] != 'p'
		    && str[0] != 'c' && str[0] != 'a' && str[0] != 'q'
			  && (str[0] < '0' || str[0] > '9'))
		  	isValid = false;
	}

	else {
		if (str[0] < '0' && str[0] > '9' && str[0] != '-')
			isValid = false;

		for (size_t i = 1; i != str.size(); ++i)
			if (str[i] < '0' || str[i] > '9')
				isValid = false;
	}

	return isValid;
}
