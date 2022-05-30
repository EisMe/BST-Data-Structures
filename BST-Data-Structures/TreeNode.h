#pragma once
// TreeNode
template<typename T>
class TreeNode
{
public:
	T data;
	TreeNode<T>* left;
	TreeNode<T>* right;
	TreeNode()
	{
		right = left = nullptr;
	}
	TreeNode(T data)
	{
		this->data = data;
		left = right = nullptr;
	}
};