/*
 * implementation of linked list.
 */

struct node {
	node *next;
	int value;
};

class IntList {
	node *first;
	void removeAll();
	void copyList(node *list);
public:
	bool isEmpty();
	void insert(int v);
	int remove();
	IntList();								// default constructor
	IntList(const IntList &l);				// copy constructor
	~IntList();								// deconstructor
	IntList &operator=(const IntList &l);	// assignment
};

void
IntList::removeAll()
{
	while (!isEmpty())
		remove();
}

void
IntList::copyList(node *list)
{
	if (!list) return;
	copyList(list->next);
	insert(list->value);
}

bool
IntList::isEmpty()
{
	return !first;
}

void
IntList::insert(int v)
{
	node *np = new node;
	np->value = v;
	np->next = first;
	first = np;
}

int
IntList::remove()
{
	if (isEmpty()) {
		listIsEmpty e;
		throw e;
	}
	node *victim = first;
	int result = first->value;
	first = first->next;
	delete victim;
	return result;
}

IntList::IntList(): first(NULL) {}

IntList::IntList(const IntList &l): first(NULL)
{
	copyList(l.first);
}

IntList::~IntList()
{
	removeAll();
}

IntList::operator=(const IntList &l)
{
	if (this != &l) {
		removeAll();
		copyList(l.first);
	}
	return *this;
}
