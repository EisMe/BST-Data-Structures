#include "BST.h"

// constructor
template<typename T>
inline BST<T>::BST()
{
	root = nullptr;
	size = 0;
}

// destory
template<typename T>
void BST<T>::destroy(TreeNode<T>*)
{
// iterative
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
template<typename T>
BST<T>::~BST()
{
	destroy(root);
}

// insert
template<typename T>
void BST<T>::insertHelper(TreeNode<T>* &root, T data)
{
	// tree is empty
	if (root == nullptr)
	{
		root = new TreeNode<T>(data);
		size++;
		return;
	}
	// data is less than the root, go left
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
	// data is greater than the root, go right
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
	else
	{
		return;
	}
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
	// remove function
	// if data is root's data and root has no children
	if (root->data == data && root->left == nullptr && root->right == nullptr)
	{
		delete root;
		root = nullptr;
		size--;
		return;
	}

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
			removeHelper(root->right, temp->data);
		}
	}
	
}

template<typename T>
void BST<T>::remove(T data)
{
	// write remove using recursion
	removeHelper(root, data);
}

template<typename T>
void BST<T>::remove(TreeNode<T>* it)
{
	removeHelper(root, it);

}

template<typename T>
void BST<T>::removeHelper(TreeNode<T>*& root, TreeNode<T>* it)
{
	if(root == nullptr || it == nullptr)
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
void BST<T>::postorderHelper(TreeNode<T>*root)
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

	if (root == nullptr)
	{
		return 0;
	}
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