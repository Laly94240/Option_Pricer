#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <stdexcept>

template <typename T>
class BinaryTree
{
public:
    void setDepth(int depth)
    {
        _depth = depth;
        _tree.resize(depth + 1);
        for (int n = 0; n <= depth; ++n)
            _tree[n].resize(n + 1);          // level n has n + 1 nodes
    }

    void setNode(int n, int i, T value)
    {
        check(n, i);
        _tree[n][i] = value;
    }

    T getNode(int n, int i) const
    {
        check(n, i);
        return _tree[n][i];
    }

    void display() const
    {
        // 1) values level by level
        for (int n = 0; n <= _depth; ++n)
        {
            for (int i = 0; i <= n; ++i)
                std::cout << _tree[n][i] << " ";
            std::cout << std::endl;
        }
        std::cout << std::endl;

        // 2) same values drawn as a triangle
        const int cell = 6;                  // width given to each value
        for (int n = 0; n <= _depth; ++n)
        {
            std::string indent((_depth - n) * cell / 2, ' ');
            std::cout << indent;
            for (int i = 0; i <= n; ++i)
                std::cout << std::setw(cell) << _tree[n][i];
            std::cout << std::endl;

            if (n < _depth)
            {
                std::cout << indent;
                for (int i = 0; i <= n; ++i)
                    std::cout << std::setw(cell) << "/ \\";
                std::cout << std::endl;
            }
        }
        std::cout << std::endl;
    }

private:
    int _depth = 0;
    std::vector<std::vector<T>> _tree;

    void check(int n, int i) const   // throws if (n, i) is outside the tree
    {
        if (n < 0 || n > _depth || i < 0 || i > n)
            throw std::out_of_range("BinaryTree: invalid node");
    }
};
