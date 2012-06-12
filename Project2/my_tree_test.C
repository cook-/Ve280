#include <iostream>
#include "recursive.h"
#include "p2.h"
using namespace std;

int main()
{
	tree_t treeA;
	treeA = tree_make(4,
			  tree_make(2, 
			    tree_make(), 
				tree_make(3, 
				  tree_make(6, tree_make(), tree_make()), 
				  tree_make(7, tree_make(), tree_make()))), 
			  tree_make(5, 
			    tree_make(), 
				tree_make(8, tree_make(), tree_make())));
	tree_print(treeA);
	cout << endl;
	cout << "sum of treeA: " << tree_sum(treeA) << endl;
	cout << "7 is in treeA?: " << tree_search(treeA, 7) << endl;
	cout << "depth of treeA: " << depth(treeA) << endl;
	cout << "minimum of treeA: " << tree_min(treeA) << endl;
	cout << "traversal of treeA: ";
	list_print(traversal(treeA));
	cout << endl;
	return 0;
}
