// for point location
#include <iostream>
#include "redblack.h"

int main()
{
    std::cout << "Hello world\n";
    RedBlackTree<int> tree;
    tree.insert(tree.root, 2);
    tree.insert(tree.root, 1);
    tree.insert(tree.root, 3);
    tree.insert(tree.root, 0);
    tree.insert(tree.root, -1);
    tree.insert(tree.root, -2);


    tree.printTree(tree.root);
    if (tree.contains(tree.root, 2)) {
        std::cout << "Contains 2\n";
    }
    std::cout << "Height = " << (tree.root)->left->left->left->left->height;
    return 0;
}