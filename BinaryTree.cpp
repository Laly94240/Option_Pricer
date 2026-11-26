#include "BinaryTree.h"
#include <iostream>
#include <string>

using namespace std;

template <typename T>
void BinaryTree<T>::setDepth(int depth)
{
	_depth = depth;
	_tree.assign(depth + 1, vector<T>());
	for (int i = 0; i <= depth; ++i)
	{
		_tree[i].resize(1 << i); // 2^i nodes at level i
	}
}

template <typename T>
void BinaryTree<T>::setNode(int level, int index, T value)
{
	_tree[level][index] = value;
}

template <typename T>
T BinaryTree<T>::getNode(int level, int index) const
{
	return _tree[level][index];
}

template <typename T>
void BinaryTree<T>::display() const
{
	int width = (1 << (_depth + 1)) * 4;
	vector<string> lines(2 * _depth + 1, string(width, ' '));

	// Nodes
	for (int i = 0; i <= _depth; i++)
	{
		int spacing = 1 << (_depth - i);
		for (int j = 0; j < (int)_tree[i].size(); j++)
		{
			int pos = (2 * j + 1) * spacing * 2;
			string value = to_string(_tree[i][j]);
			lines[2 * i].replace(pos, value.size(), value);
		}
	}

	// Branches
	for (int i = 1; i <= _depth; i++)
	{
		int spacing = 1 << (_depth - i);
		for (int j = 0; j < (int)_tree[i].size(); j++)
		{
			int pos = (2 * j + 1) * spacing * 2;
			int parentPos = (j / 2 * 2 + 1) * spacing * 4;
			int branchPos = (pos + parentPos) / 2;
			lines[2 * i - 1][branchPos] = (j % 2 == 0) ? '/' : '\\';
		}
	}

	for (const string& line : lines)
		cout << line << endl;
}

// Instanciations explicites : necessaires car l'implementation du template est dans ce .cpp.
// Pour utiliser BinaryTree avec un autre type, ajoute une ligne ici.
template class BinaryTree<int>;
template class BinaryTree<double>;
template class BinaryTree<bool>;
