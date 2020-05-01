#include"BinaryTree.h"
#include <iostream>
#include<string>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");
	BinaryTree<int> Tree;
	vector<int> Path;
	vector<int> Leaves;
	Tree.insert(2);
	Tree.insert(14);
	Tree.insert(8);
	Tree.insert(10);
	Tree.insert(32);
	Tree.remove(14);
	cout << "Дерево: " << (string)Tree << endl;
	Path = Tree.buildPath();
	cout << "Путь обхода вершин: ";
	for (int i = 0; i < Path.size(); i++) cout << Path[i] << " "; cout << endl;
	Leaves = Tree.listOfLeaves();
	cout << "Список листьев: ";
	for (int i = 0; i < Leaves.size(); i++) cout << Leaves[i] << " "; cout << endl;

	if (Tree.Search(2)) cout << "Элемент найден!" << endl;
	Tree.remove(2);
	if (!Tree.Search(2)) cout << "Элемент не найден!" << endl;

	Tree.insert(12);
	Tree.insert(3);
	Tree.insert(9);
	Tree.insert(5);
	Tree.insert(7);
	Tree.insert(6);
	Tree.insert(18);
	cout << "Дерево: " << (string)Tree << endl;

	Path = Tree.buildPath();
	cout << "Путь обхода вершин: ";
	for (int i = 0; i < Path.size(); i++) cout << Path[i] << " "; cout << endl;

	Leaves = Tree.listOfLeaves();
	cout << "Список листьев: ";
	for (int i = 0; i < Leaves.size(); i++) cout << Leaves[i] << " "; cout << endl;

}