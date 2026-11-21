#pragma once
#include <iostream>
#include <vector> 
using namespace std;

template <typename T>
class BinaryTree
{
private:
	int _depth;
	vector<vector<T>> _tree;

public:
	void setDepth(int depth);
	void setNode(int, int, T);
	int getNode(int, int);
	void display();
};

