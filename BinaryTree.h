#pragma once
#include <iostream>
#include <vector> 
using namespace std;

template <typename T>
class BinaryTree
{
private:
	

public:
	int _depth;
	vector<vector<T>> _tree;
	void setDepth(int depth);
	void setNode(int, int, T);
	int getNode(int, int);
	void display();
};

