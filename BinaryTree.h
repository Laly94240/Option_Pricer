#pragma once
#include <iostream>
#include <vector>
#include <string>
using namespace std;

template <typename T>
class BinaryTree
{
public:
	int _depth = 0;
	vector<vector<T>> _tree;

private:
	void setDepth(int depth);
	void setNode(int level, int index, T value);
	T getNode(int level, int index);
	void display();
};
