#include "compare.h"

static int min(int a, int b)
// EFFECTS: returns the smaller of a and b.
{
	if(a < b)
		return a;
	else
		return b;
}

static int max(int a, int b)
// EFFECTS: returns the larger of a and b.
{
	if(a < b)
		return b;
	else
		return a;
}

static int compare_help(int so_far, list_t list,
	int (*fn)(int, int))
{
	if (list_isEmpty(list))
	{
		return so_far;
	}
	else
	{
		so_far = fn(so_far, list_first(list));
		return compare_help(so_far, list_rest(list), fn);
	}
}

int smallest(list_t list)
// REQUIRES: list is not empty
// EFFECTS: returns smallest element in list
{
	return compare_help(list_first(list),
		list_rest(list), min);
}

int largest(list_t list)
// REQUIRES: list is not empty
// EFFECTS: returns largest element in list
{
	return compare_help(list_first(list),
		list_rest(list), max);
}
