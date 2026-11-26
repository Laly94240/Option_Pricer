#pragma once
#include <vector>
using namespace std;

template <typename T>
class BinaryTree
{
public:
	int _depth = 0;
	vector<vector<T>> _tree;

	void setDepth(int depth);
	void setNode(int level, int index, T value);
	T getNode(int level, int index) const;
	void display() const;
};
