#include "BinaryTree.h"
#include <iostream>
#include <vector> 
using namespace std;

void BinaryTree::setDepth(int depth)
{
	_depth = depth;
	_tree.resize(depth + 1);
	for (int i = 0; i <= depth; ++i)
	{
		_tree[i].resize(1 << i); // 2^i nodes at level i
	}
}
