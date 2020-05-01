#pragma once
#include<iostream>
#include<string>
#include<vector>
using namespace std;

template<class T>
class BinaryTree
{
private:
	struct Node
	{
		T info;
		Node* left;
		Node* right;
		Node(T _info) :left(nullptr), info(_info), right(nullptr) {}
	};
	Node* root;

	void insert(T, Node*&);
	void remove(T, Node*&);
	void buildPath(vector<T>&, Node*);
	void listOfLeaves(Node*, vector<T>&);
	bool Search(T, Node*);
	string PrintTree(Node*);
public:
	void dispose(Node*);
	BinaryTree() : root(nullptr) {}
	~BinaryTree();
	void insert(T);
	void remove(T);
	vector<T> buildPath();
	vector<T> listOfLeaves();
	bool Search(T);
	operator string();
};

template<class T>
BinaryTree<T>::~BinaryTree()
{
	if (root) {
		this->dispose(this->root);
	}
}

template<class T>
void BinaryTree<T>::dispose(Node* root)
{
	if (root)
	{
		dispose(root->left);
		dispose(root->right);
		delete root;
	}
}

template <class T>
void  BinaryTree<T>::buildPath(vector<T>& top, Node* root)
{
	if (root) {
		buildPath(top, root->left);
		top.push_back(root->info);
		buildPath(top, root->right);
	}
}

template <class T>
vector<T> BinaryTree<T>::buildPath()
{
	vector<T> top;
	buildPath(top, this->root);
	return top;
}

template<class T>
void BinaryTree<T>::insert(T info)
{
	if (root == nullptr) root = new Node(info);
	else this->insert(info, root);
}

template<class T>
void BinaryTree<T>::insert(T info, Node*& node)
{
	if (node == nullptr) node = new Node(info);
	else if (info < node->info) this->insert(info, node->left);
	else if (info > node->info) this->insert(info, node->right);
	else throw "This element already exists!";
}

template<class T>
void BinaryTree<T>::remove(T info)
{
	this->remove(info, this->root);
}
template<class T>
void BinaryTree<T>::remove(T info, Node*& root) {
	if (root == nullptr) throw "This element was not found!";
	if (info > root->info) remove(info, root->right);
	else if (info < root->info) remove(info, root->left);
	else {
		Node* temp = root;
		if (temp->right == nullptr && temp->left == nullptr)
		{
			root = nullptr;
		}
		else if (temp->right == nullptr && temp->left != nullptr)
		{
			root = temp->left;
		}
		else if (temp->left == nullptr && temp->right != nullptr)
		{
			root = temp->right;
		}
		else
		{
			Node* maxNode = temp->left;
			while (maxNode->right) maxNode = maxNode->right;
			temp->info = maxNode->info;
			remove(maxNode->info, temp->left);
		}
	}
}

template<class T>
vector<T> BinaryTree<T>::listOfLeaves()
{
	vector<T> leafList;
	listOfLeaves(this->root, leafList);
	return leafList;
}

template<class T>
void BinaryTree<T>::listOfLeaves(Node* root, vector<T>& leaf)
{
	if (root->left == nullptr && root->right == nullptr)
	{
		leaf.push_back(root->info);
	}
	else
	{
		if (root->left) listOfLeaves(root->left, leaf);
		if (root->right) listOfLeaves(root->right, leaf);
	}
}

template<class T>
bool BinaryTree<T>::Search(T info)
{
	return Search(info, root);
}

template<class T>
bool BinaryTree<T>::Search(T info, Node* root)
{
	if (root == nullptr) return false;
	else if (root->info == info) return true;
	else if (info > root->info) return Search(info, root->right);
	else return Search(info, root->left);
}

template<class T>
string BinaryTree<T>::PrintTree(Node* node) {
	string leftChild = (node->left == nullptr) ? "()" : PrintTree(node->left);
	string rightChild = (node->right == nullptr) ? "()" : PrintTree(node->right);
	string result = "{" + leftChild + ", " + to_string(node->info) + ", " + rightChild + "}";
	return result;
}

template<class T>
BinaryTree<T>::operator string()
{
	if (root == nullptr) return "()";
	else return this->PrintTree(this->root);
}
