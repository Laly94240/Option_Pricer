#include "BinaryTree.h"
#include <iostream>
#include <vector> 
#include <string>

using namespace std;

template <typename T>
void BinaryTree<T>::setDepth(int depth)
{
    _depth = depth;
    _tree.resize(depth + 1);
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
T BinaryTree<T>::getNode(int level, int index)
{
    return _tree[level][index];
}


//verify the ouput bc not quite sure if it's what i waaaaaant
void BinaryTree<int>::display()
{
    int width = (1 << (_depth + 1)) * 4;

    vector<string> lines(2 * _depth + 1, string(width, ' '));

    // Display nodes
    for (int i = 0; i <= _depth; i++)
    {
        int spacing = 1 << (_depth - i);

        for (int j = 0; j < _tree[i].size(); j++)
        {
            int pos = (2 * j + 1) * spacing * 2;

            string value = to_string(_tree[i][j]);

            lines[2 * i].replace(pos, value.size(), value);
        }
    }

    // Display branches
    for (int i = 1; i <= _depth; i++)
    {
        int spacing = 1 << (_depth - i);

        for (int j = 0; j < _tree[i].size(); j++)
        {
            int pos = (2 * j + 1) * spacing * 2;
            int parentPos = (j / 2 * 2 + 1) * spacing * 4;

            int branchPos = (pos + parentPos) / 2;

            if (j % 2 == 0)
                lines[2 * i - 1][branchPos] = '/';
            else
                lines[2 * i - 1][branchPos] = '\\';
        }
    }

    for (string line : lines)
        cout << line << endl;
}