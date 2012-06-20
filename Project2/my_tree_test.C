#include <iostream>
#include "recursive.h"
#include "p2.h"
using namespace std;

int main()
{
	tree_t treeA;
	tree_t treeB;
	tree_t treeC;
	tree_t treeD;
	tree_t sorted_binary_tree;
	treeA = tree_make(4,
			  tree_make(2, 
			    tree_make(), 
				tree_make(3, 
				  tree_make(6, tree_make(), tree_make()), 
				  tree_make(7, tree_make(), tree_make()))), 
			  tree_make(5, 
			    tree_make(), 
				tree_make(8, tree_make(), tree_make())));
	treeB = tree_make(4,
			  tree_make(2, 
			    tree_make(1, tree_make(), tree_make()), 
				tree_make(3, 
				  tree_make(6, tree_make(), tree_make()), 
				  tree_make(7, tree_make(), tree_make()))), 
			  tree_make(5, 
			    tree_make(), 
				tree_make(8, tree_make(), tree_make())));
	treeC = tree_make();
	treeD = tree_make(3,
			  tree_make(6, tree_make(), tree_make()),
			  tree_make());
	sorted_binary_tree = tree_make(4, 
						   tree_make(2, 
						     tree_make(), 
							 tree_make(3, tree_make(), tree_make())), 
						   tree_make(5, tree_make(), tree_make()));
	tree_print(treeA);
	cout << endl;
	cout << "sum of treeA: " << tree_sum(treeA) << endl;
	cout << "7 is in treeA?: " << tree_search(treeA, 7) << endl;
	cout << "depth of treeA: " << depth(treeA) << endl;
	cout << "minimum of treeA: " << tree_min(treeA) << endl;
	cout << "traversal of treeA: ";
	list_print(traversal(treeA));
	cout << endl;
	cout << "treeA has a path of sum 16?: " << tree_hasPathSum(treeA, 16) << endl;
	tree_print(mirror(treeA));
	cout << endl;
	cout << "treeA is covered by treeB?: " << covered_by(treeA, treeB) << endl;
	cout << "treeA is covered by treeC?: " << covered_by(treeA, treeC) << endl;
	cout << "treeD is covered by treeA?: " << contained_by(treeD, treeA) << endl;
	cout << "treeD is covered by treeC?: " << contained_by(treeD, treeC) << endl;
	tree_print(insert_tree(1, sorted_binary_tree));
	cout << endl;
	return 0;
}
