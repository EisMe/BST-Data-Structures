#pragma once
#include "TreeNode.h"
#include <iostream>
using namespace std;

// class BST
template<typename T>
class BST
{
	friend TreeNode<T>;
public:

	BST();
	~BST();
	void destroy(TreeNode<T>*);

	// insert
	void insert(T);
	void insertHelper(TreeNode<T>*&, T);

	// remove
	void remove(T data);
	void remove(TreeNode<T>*);
	void removeHelper(TreeNode<T>*&, T);
	void removeHelper(TreeNode<T>*&, TreeNode<T>*);

	// inorder
	void inorder();
	void inorderHelper(TreeNode<T>*);

	// preorder
	void preorder();
	void preorderHelper(TreeNode<T>*);

	// postorder
	void postorder();
	void postorderHelper(TreeNode<T>*);

	// search
	TreeNode<T>* search(T data);
	TreeNode<T>* searchHelper(TreeNode<T>*, T);

	// preorder print
	void print();
	void printHelper(TreeNode<T>*);

private:
	TreeNode<T>* root;
	int size;
};