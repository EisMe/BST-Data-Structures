#include "BST.h"

int main()
{
	// testing the BST class and functions
	BST<int> bst;
	// inserting integers
	bst.insert(11);
	bst.insert(7);
	bst.insert(13);
	bst.insert(2);
	bst.insert(9);
	bst.insert(17);
	bst.insert(13); // inserting value twice does nothing.
	bst.insert(22);
	bst.insert(12);
	// tree looks like this:
	/*
			 11
			/ \
		   /   \
		  7     \
		 / \     13
		2   9   / \
			   12  \
					17
				     \
				      22
	
	*/

	// testing functions
	bst.print();
	// expected outcome:
	//	11, 7, 2, 9, 13, 12, 27, 22

	// testing search
	cout << "\nSearching for 13: ";
	auto it = bst.search(13);
	if(it != nullptr)
		cout << "Found 13 at " << it << endl;
	else
		cout << "13 not found" << endl;
	
	// testing remove
	bst.remove(22);
	bst.print();
	cout << endl;
	// expected outcome:
	//	11, 7, 2, 9, 12, 17

	// testing remove on the root
	bst.remove(11);
	bst.print();
	cout << endl;
	// expected outcome:
	//	12, 7, 2, 9, 13, 17 

	
	
}