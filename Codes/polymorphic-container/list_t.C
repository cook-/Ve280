#include "list_t.h"

List::List(): first(0)
{
}

bool List::isEmpty()
{
	return (!first);
}

void List::insert(Object *v)
{
	node *np = new node;
	np->value = v;
	np->next = first;
	first = np;
}

Object *List::remove()
{
	if(isEmpty())
	{
		listIsEmpty e;
		throw e;
	}
	
	node *victim = first;
	Object *result = victim->value;
	first = victim->next;
	delete victim;
	return result;
}

void List::copyList(node *np)
{
	if(!np) return;
	copyList(np->next);
	Object *op = np->value->clone();
	insert(op);
}

void List::removeAll()
{
	while(!isEmpty())
	{
		Object *op = remove();
		delete op;
	}
}

List::~List()
{
	removeAll();
}

List::List(const List &l): first(0)
{
	copyList(l.first);
}

List& List::operator=(const List &l)
{
	if(this != &l)
	{
		removeAll();
		copyList(l.first);
	}
	return *this;
}
