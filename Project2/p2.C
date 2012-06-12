#include "recursive.h"
using namespace std;

// Funcitions for lists
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

// Functions for binary trees
int larger(int a, int b)
{
	return (a >= b) ? a : b;
}

int smaller(int a, int b)
{
	return (a < b) ? a : b;
}
int tree_sum(tree_t tree)
{
	if (tree_isEmpty(tree))
		return 0;
	else
		return tree_elt(tree) + tree_sum(tree_left(tree)) + tree_sum(tree_right(tree));
}

bool tree_search(tree_t tree, int key)
{
	if (tree_isEmpty(tree))
		return false;
	else
		return tree_elt(tree) == key || tree_search(tree_right(tree), key) || tree_search(tree_left(tree), key);
}

int depth(tree_t tree)
{
	if (tree_isEmpty(tree))
		return 0;
	else
		return larger(depth(tree_left(tree)), depth(tree_right(tree))) + 1;
}

int tree_min(tree_t tree)
{
	if (tree_isEmpty(tree_left(tree)) && tree_isEmpty(tree_right(tree)))
		return tree_elt(tree);
	else if (tree_isEmpty(tree_left(tree)) && !tree_isEmpty(tree_right(tree))) 
		return smaller(tree_elt(tree), tree_min(tree_right(tree)));
	else if (!tree_isEmpty(tree_left(tree)) && tree_isEmpty(tree_right(tree))) 
		return smaller(tree_elt(tree), tree_min(tree_left(tree)));
	else
		return smaller(tree_elt(tree), smaller(tree_min(tree_left(tree)), tree_min(tree_right(tree))));
}

list_t traversal(tree_t tree)
{
	if (tree_isEmpty(tree))
		return list_make();
	else
		return append(traversal(tree_left(tree)), list_make(tree_elt(tree), traversal(tree_right(tree))));
}

bool tree_hasPathSum(tree_t tree, int sum)
{
	if (sum == 0) 
		return true;
	else if (tree_isEmpty(tree))
		return false;
	else
		return tree_hasPathSum(tree_left(tree), sum - tree_elt(tree)) || tree_hasPathSum(tree_right(tree), sum - tree_elt(tree));
}

tree_t mirror(tree_t tree)
{
	if (tree_isEmpty(tree))
		return tree_make();
	else
		return tree_make(tree_elt(tree), mirror(tree_right(tree)), mirror(tree_left(tree)));
}

bool covered_by(tree_t A, tree_t B)
{
	if (tree_isEmpty(A))
		return true;
	else if (tree_isEmpty(B))
		return false;
	else if (tree_elt(A) != tree_elt(B))
		return false;
	else
		return covered_by(tree_left(A), tree_left(B)) && covered_by(tree_right(A), tree_right(B));
}

bool contained_by(tree_t A, tree_t B)
{
	if (tree_isEmpty(B))
		return covered_by(A, B);
	else
		return covered_by(A, B) || contained_by(A, tree_left(B)) || contained_by(A, tree_right(B));
}

tree_t insert_tree(int elt, tree_t tree)
{
	if (tree_isEmpty(tree))
		return tree_make(elt, tree_make(), tree_make());
	else if (elt < tree_elt(tree))
		return tree_make(tree_elt(tree), insert_tree(elt, tree_left(tree)), tree_right(tree));
	else
		return tree_make(tree_elt(tree), tree_left(tree), insert_tree(elt, tree_right(tree)));
}
