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

static int accumulate_helper(list_t list, int (*fn)(int, int), int result)
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

static list_t reverse_helper(list_t list, list_t result)
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

list_t append(list_t first, list_t second)
{
	if (list_isEmpty(first))
		return second;
	else
		return append(reverse(list_rest(reverse(first))), list_make(list_first(reverse(first)), second));
}

static list_t filter_odd_helper(list_t list, list_t result)
{
	if (list_isEmpty(list))
		return result;
	else if (list_first(reverse(list)) % 2)
		return filter_odd_helper(reverse(list_rest(reverse(list))), list_make(list_first(reverse(list)), result));
	else
		return filter_odd_helper(reverse(list_rest(reverse(list))), result);
}

list_t filter_odd(list_t list)
{
	return filter_odd_helper(list, list_make());
}

static list_t filter_even_helper(list_t list, list_t result)
{
	if (list_isEmpty(list))
		return result;
	else if (!(list_first(reverse(list)) % 2))
		return filter_even_helper(reverse(list_rest(reverse(list))), list_make(list_first(reverse(list)), result));
	else
		return filter_even_helper(reverse(list_rest(reverse(list))), result);
}

list_t filter_even(list_t list)
{
	return filter_even_helper(list, list_make());
}

static list_t filter_helper(list_t list, bool (*fn)(int), list_t result)
{
	if (list_isEmpty(list))
		return result;
	else if (fn(list_first(reverse(list))))
		return filter_helper(reverse(list_rest(reverse(list))), fn, list_make(list_first(reverse(list)), result));
	else
		return filter_helper(reverse(list_rest(reverse(list))), fn, result);
}

list_t filter(list_t list, bool (*fn)(int))
{
	return filter_helper(list, fn, list_make());
}

static list_t insert_list_helper(list_t first, list_t second, unsigned int n, list_t tmp)
{
	if (n == 0)
		return append(reverse(tmp), append(second, first));
	else
		return insert_list_helper(list_rest(first), second, n - 1, list_make(list_first(first), tmp));
}

list_t insert_list(list_t first, list_t second, unsigned int n)
{
	return insert_list_helper(first, second, n, list_make());
}

static list_t removeNth_helper(list_t list, unsigned int n, list_t tmp)
{
	if (n == 1)
		return append(reverse(tmp), list_rest(list));
	else
		return removeNth_helper(list_rest(list), n - 1, list_make(list_first(list), tmp));
}

list_t removeNth(list_t list, unsigned int n)
{
	return removeNth_helper(list, n, list_make());
}

list_t chop(list_t list, unsigned int n)
{
	if (n == 0)
		return list;
	else
		return chop(reverse(list_rest(reverse(list))), n - 1);
}
