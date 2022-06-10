#include "BST.h"

/* The constructor for the BST class. */
template<typename T>
inline BST<T>::BST()
{
	root = nullptr;
	size = 0;
}

// copy constructor
template<typename T>
BST<T>::BST(const BST<T>& original)
{
	root = nullptr;
	size = 0;
	copy(root, original.root);
}

// copy helper function
template<typename T>
void BST<T>::copy(TreeNode<T>*& root, TreeNode<T>* original)
{
	// if the original is nullptr, return
	if (original == nullptr)
	{
		return;
	}
	// create a new node with the same data
	else
	{
		insert(original->data);
		copy(root->left, original->left);
		copy(root->right, original->right);
	}
}


// assignment operator
template<typename T>
BST<T>& BST<T>::operator=(const BST<T>& rhs)
{
	if (this != &rhs)
	{
		destroy(root);
		copy(root, rhs.root);
	}
	return *this;
}


// destory
/* Deleting the tree. */
template<typename T>
void BST<T>::destroy(TreeNode<T>*)
{
	// check if the tree is empty
	if(root == nullptr)
	{
		return;
	}
	// iterative,(P.S. recursion was too slow)
	TreeNode<T>* curr = root;
	TreeNode<T>* temp;
	while (curr != nullptr)
	{
		if (curr->left != nullptr)
		{
			temp = curr->left;
			curr->left = nullptr;
			curr = temp;
		}
		else
		{
			temp = curr->right;
			curr->right = nullptr;
			curr = temp;
		}
	}
}

// destructor
/* The destructor for the BST class. */
template<typename T>
BST<T>::~BST()
{
	destroy(root);
}

// insert
/* Inserting a node into the tree. */
template<typename T>
void BST<T>::insertHelper(TreeNode<T>*& root, T data)
{
	/* This is checking if the root is nullptr, if it is, it will create a new node with the data and
	return. */
	if (root == nullptr)
	{
		root = new TreeNode<T>(data);
		size++;
		return;
	}

	/* This is checking if the data is less than the root, if it is, it will check if the left node is
	nullptr. If it is, it will create a new node with the data and return. If it is not, it will call
	the insertHelper function again with the left node. */
	if (data < root->data)
	{
		if (root->left == nullptr)
		{
			root->left = new TreeNode<T>;
			root->left->data = data;
			root->left->left = root->left->right = nullptr;
			size++;
			return;
		}
		else
		{
			insertHelper(root->left, data);
		}
	}

	/* This is checking if the data is greater than the root, if it is, it will check if the right node is
	nullptr. If it is, it will create a new node with the data and return. If it is not, it will call
	the insertHelper function again with the right node. */
	else if (data > root->data)
	{
		if (root->right == nullptr)
		{
			root->right = new TreeNode<T>;
			root->right->data = data;
			root->right->left = root->right->right = nullptr;
			size++;
			return;
		}
		else
		{
			insertHelper(root->right, data);
		}
	}
	// data is equal to the root, do nothing
	
		return;
}

template<typename T>
void BST<T>::insert(T data)
{
	insertHelper(root, data);
}

// remove
template<typename T>
void BST<T>::removeHelper(TreeNode<T>*& root, T data)
{
	/* This is checking if the root is equal to the data and if the left and right nodes are nullptr. If
	they are, it will delete the root and set it to nullptr. It will also decrease the size by one and
	return. */
	if (root->data == data && root->left == nullptr && root->right == nullptr)
	{
		delete root;
		root = nullptr;
		size--;
		return;
	}

	/* This is checking if the root is nullptr. If it is, it will return. */
	if (root == nullptr)
	{
		return;
	}
	// data is less than the root, go left
	if (data < root->data)
	{
		removeHelper(root->left, data);
	}
	// data is greater than the root, go right
	else if (data > root->data)
	{
		removeHelper(root->right, data);
	}
	// data is equal to the root, remove it
	else
	{
		/* This is checking if the root has no children. If it does not, it will delete the root and set it
		to nullptr. It will also decrease the size by one and return. */
		if (root->left == nullptr && root->right == nullptr)
		{
			delete root;
			root = nullptr;
			size--;
			return;
		}

		/* Checking if the root has one child. If it does, it will delete the root and set the root to the
		child. It will also decrease the size by one and return. */
		else if (root->left == nullptr)
		{
			TreeNode<T>* temp = root;
			root = root->right;
			delete temp;
			size--;
			return;
		}
		else if (root->right == nullptr)
		{
			TreeNode<T>* temp = root;
			root = root->left;
			delete temp;
			size--;
			return;
		}
		// node has two children
		/* Finding the smallest value in the right subtree and replacing the root with that value. */
		else
		{
			TreeNode<T>* temp = root->right;
			while (temp->left != nullptr)
			{
				temp = temp->left;
			}
			root->data = temp->data;
			removeHelper(root->right, temp->data);
		}
	}
}

/* remove function. It is calling the removeHelper function with the root and the data. */
template<typename T>
void BST<T>::remove(T data)
{
	removeHelper(root, data);
}

/* Calling the removeHelper function with the root and the it. */
template<typename T>
void BST<T>::remove(TreeNode<T>* it)
{
	removeHelper(root, it);
}

/* Removing a node from the tree. */
template<typename T>
void BST<T>::removeHelper(TreeNode<T>*& root, TreeNode<T>* it)
{
	/* Checking if the root or the it is nullptr. If it is, it will return. */
	if (root == nullptr || it == nullptr)
	{
		return;
	}
	// data is less than the root, go left
	if (it->data < root->data)
	{
		removeHelper(root->left, it);
	}
	// data is greater than the root, go right
	else if (it->data > root->data)
	{
		removeHelper(root->right, it);
	}
	// data is equal to the root, remove it
	else
	{
		// node has no children
		if (root->left == nullptr && root->right == nullptr)
		{
			// remove parent
			delete root;
			root = nullptr;
			size--;
			return;
		}
		// node has one child
		else if (root->left == nullptr)
		{
			TreeNode<T>* temp = root;
			root = root->right;
			delete temp;
			size--;
			return;
		}
		else if (root->right == nullptr)
		{
			TreeNode<T>* temp = root;
			root = root->left;
			delete temp;
			size--;
			return;
		}
		// node has two children
		else
		{
			TreeNode<T>* temp = root->right;
			while (temp->left != nullptr)
			{
				temp = temp->left;
			}
			root->data = temp->data;
			removeHelper(root->right, temp);
		}
	}
}

// inorder
template<typename T>
void BST<T>::inorder()
{
	inorderHelper(root);
}

template<typename T>
void BST<T>::inorderHelper(TreeNode<T>* root)
{
	// write inorder using recursion
	if (root == nullptr)
	{
		return;
	}
	inorderHelper(root->left);
	cout << root->data << " ";
	inorderHelper(root->right);
}

// preorder
template<typename T>
void BST<T>::preorder()
{
	preorderHelper(root);
}

template<typename T>
void BST<T>::preorderHelper(TreeNode<T>* root)
{
	// write preorder using recursion
	if (root == nullptr)
	{
		return;
	}
	cout << root->data << " ";
	preorderHelper(root->left);
	preorderHelper(root->right);
}

// postorder
template<typename T>
void BST<T>::postorder()
{
	postorderHelper(this->root);
}

template<typename T>
void BST<T>::postorderHelper(TreeNode<T>* root)
{
	// write postorder using recursion
	if (root == nullptr)
	{
		return;
	}
	postorderHelper(root->left);
	postorderHelper(root->right);
	cout << root->data << " ";
}

// search
template<typename T>
TreeNode<T>* BST<T>::search(T data)
{
	return searchHelper(this->root, data);
}

template<typename T>
TreeNode<T>* BST<T>::searchHelper(TreeNode<T>* root, T data)
{
	// write search using recursion
	if (root == nullptr) return 0;
	if (root->data == data) return root;

	if (data < root->data)
	{
		return searchHelper(root->left, data);
	}
	else if (data > root->data)
	{
		return searchHelper(root->right, data);
	}
}

// print
template<typename T>
void BST<T>::print()
{
	printHelper(root);
}

template<typename T>
void BST<T>::printHelper(TreeNode<T>* root)
{
	preorderHelper(root);
}

template class BST<int>;