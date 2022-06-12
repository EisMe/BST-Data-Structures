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
	//constructor
	BST();
	
	// destructor
	~BST();
	void destroy(TreeNode<T>*);

	// copy constructor
	BST(const BST<T>&);
	void copy(TreeNode<T>*&, TreeNode<T>*);

	// assignment operator
	BST<T>& operator=(const BST<T>&);

	// insert
	void insert(T);
	void insertHelper(TreeNode<T>*&, T);
	void copyInsertHelper(TreeNode<T>*& , T);

	// remove
	void remove(T);
	void remove(TreeNode<T>*);
	void removeHelper(TreeNode<T>*&, T);
	void removeHelper(TreeNode<T>*&, TreeNode<T>*);

	// inorder
	void inorder()const;
	void inorderHelper(TreeNode<T>*)const;

	// preorder
	void preorder()const;
	void preorderHelper(TreeNode<T>*)const;

	// postorder
	void postorder()const;
	void postorderHelper(TreeNode<T>*)const;

	// search
	TreeNode<T>* search(T)const;
	TreeNode<T>* searchHelper(TreeNode<T>*, T)const;

	// preorder print
	void print()const;
	void printHelper(TreeNode<T>*)const;

private:
	TreeNode<T>* root;
	int size;
};