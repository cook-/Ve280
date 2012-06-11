#include "recursive.h"
using namespace std;

static int size_helper(list_t list, int result)
{
	if (list_isEmpty(list))
		return result;
	else 
		return size_helper(list_rest(list), result + 1);
}

int size(list_t list)
{
	return size_helper(list, 0);
}

int getNth(list_t list, int n)
{
	if (n == 1)
		return list_first(list);
	else
		return getNth(list_rest(list), n - 1);
}

static int sum_helper(list_t list, int result)
{
	if (list_isEmpty(list))
		return result;
	else
		return sum_helper(list_rest(list), list_first(list) + result);
}

int sum(list_t list)
{
	return sum_helper(list, 0); 
}

static int product_helper(list_t list, int result)
{
	if (list_isEmpty(list))
		return result;
	else
		return product_helper(list_rest(list), list_first(list)*result);
}

int product(list_t list)
{
	return product_helper(list, 1);
}

int accumulate_helper(list_t list, int (*fn)(int, int), int result)
{
	if (list_isEmpty(list))
		return result;
	else
		return accumulate_helper(list_rest(list), fn, fn(list_first(list), result));
}

int accumulate(list_t list, int (*fn)(int, int), int base)
{
	return accumulate_helper(list, fn, base);
}

list_t reverse_helper(list_t list, list_t result)
{
	if (list_isEmpty(list))
		return result;
	else
		return reverse_helper(list_rest(list), list_make(list_first(list), result));
}

list_t reverse(list_t list)
{
	return reverse_helper(list, list_make());
}



