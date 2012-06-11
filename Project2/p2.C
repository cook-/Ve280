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

int product_helper(list_t list, int result)
{
	if (list_isEmpty)
		return 1;
	else
		return product_helper(list_rest(list), list_first(list)*result);
}
int product(list_t list)
{
	return product_helper(list, 1);
}







