#ifndef DLIST_C
#define DLIST_C

template <class T>
bool
Dlist<T>::isEmpty()
{
	return (!first) && (!last);
}

template <class T>
void
Dlist<T>::insertFront(T *op)
{
	node *np = new node;
	if (isEmpty()) {
		first = np;
		last = np;
		np->next = 0;
		np->prev = 0;
		np->op = op;
	}
	else {
		first->prev = np;
		np->next = first;
		np->prev = 0;
		np->op = op;
		first = np;
	}
}

template <class T>
void
Dlist<T>::insertBack(T *op)
{
	node *np = new node;
	if (isEmpty()) {
		first = np;
		last = np;
		np->next = 0;
		np->prev = 0;
		np->op = op;
	}
	else {
		last->next = np;
		np->next = 0;
		np->prev = last;
		np->op = op;
		last = np;
	}
}

template <class T>
T *
Dlist<T>::removeFront()
{
	if (isEmpty()) {
		emptyList e;
		throw e;
	}

	node *victim = first;
	if (first == last) {
		last = 0;
		first = 0;
	}
	else {
		first = victim->next;
		victim->next->prev = 0;
	}

	T *result = victim->op;
	delete victim;
	return result;
}

template <class T>
T *
Dlist<T>::removeBack()
{
	if (isEmpty()) {
		emptyList e;
		throw e;
	}

	node *victim = first;
	if (first == last) {
		first = 0;
		last = 0;
	}
	else {
		last = victim->prev;
		victim->prev->next = 0;
	}

	T *result = victim->op;
	delete victim;
	return result;
}

template <class T>
Dlist<T>::Dlist(): first(0), last(0)
{
}

template <class T>
Dlist<T>::Dlist(const Dlist &l): first(0), last(0)
{
	copyAll(l);
}

template <class T>
Dlist<T> &
Dlist<T>::operator=(const Dlist &l)
{
	if (this != &l) {
		removeAll();
		copyAll(l);
	}
	return *this;
}

template <class T>
Dlist<T>::~Dlist()
{
	removeAll();
}

template <class T>
void
Dlist<T>::removeAll()
{
	while (!isEmpty()) {
		T *op = removeFront();
		delete op;
	}
}

template <class T>
void
Dlist<T>::copyAll(const Dlist &l)
{
	node *np = first;
	while (!np) {
		T object = *(np->op);
		T *op = &object;
		insertBack(op);
		np = np->next;
	}
}

#endif
