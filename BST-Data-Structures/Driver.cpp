#include "BST.h"

int main()
{
#pragma region test_insert
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
	
	// keep the original
	BST<int> bst_m(bst);
	
	/* tree looks like this:
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

#pragma endregion
	
#pragma region test
	
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
	
#pragma region test_remove
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

#pragma endregion

#pragma region copy_and_assignment
	// testing copy constructor
	BST<int> bst2(bst);
	cout << "\nCopied tree: ";
	bst2.print();
	// expected outcome:
	//	12, 7, 2, 9, 13, 17 
	cout << endl;

	// testing assignment operator
	BST<int> bst3;
	bst3 = bst;
	cout << "\nAssigned tree: ";
	bst3.print();
	// expected outcome:
	//	12, 7, 2, 9, 13, 17
	cout << endl;
#pragma endregion
	
#pragma region traverse
	// testing all traverse functions
	cout << "\nPreorder: ";
	bst_m.preorder();
	cout << endl;
	// expected outcome:
	//	11, 7, 2, 9, 13, 12, 17, 22
	
	cout << "\nInorder: ";
	bst_m.inorder();
	cout << endl;
	// expected outcome:
	//	2, 7, 9, 11, 12, 13, 17, 22
	
	cout << "\nPostorder: ";
	bst_m.postorder();
	cout << endl;
	// expected outcome:
	//	2, 9, 7, 12, 22, 17, 13, 11
	
	
#pragma endregion
	
#pragma endregion test
	return 0;
}