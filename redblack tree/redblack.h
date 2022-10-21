#ifndef REDBLACK
#define REDBLACK

#include <functional>

template <typename T>
class RedBlackTree
{
public:
    struct Node
    { // parent pointer implementation
        T data;
        Node *left;
        Node *right;
    };

public:
    using V = std::function<void(const T &)>;
    Node *root;
    int sz;

    RedBlackTree();
    RedBlackTree(const RedBlackTree<T> &tree);
    ~RedBlackTree() noexcept;
    RedBlackTree(RedBlackTree<T> &&tree) noexcept;
    RedBlackTree<T> operator=(const RedBlackTree<T> &tree);
    RedBlackTree<T> operator=(const RedBlackTree<T> &&tree) noexcept;
    int size() const noexcept;
    void add(const T value)
    {
    }
    void remove(const T value)
    {
    }
    Node *search(const T value)
    {
    }
    bool contains(const T value) const
    {
    }
    int height() const noexcept
    {
    }

    // traversals
    void inorder(V visit) const
    {
    }
    void preorder(V visit) const
    {
    }
    void postorder(V visit) const
    {
    }

private:
    void deleteTree(Node *tree);
    RedBlackTree<T> copyTree(RedBlackTree<T> copy);
};

template <typename T>
RedBlackTree<T>::RedBlackTree()
{
    root = new Node{null, null, null};
    sz = 0;
}

template <typename T>
RedBlackTree<T>::RedBlackTree(const RedBlackTree<T> &tree)
{
    root = copyTree(tree);
    sz = 0;
}

template <typename T>
RedBlackTree<T>::~RedBlackTree()
{
    deleteTree(root);
}

template <typename T>
RedBlackTree<T>::RedBlackTree(RedBlackTree<T> &&tree) noexcept
{
    root = std::move(tree.root);
    sz = std::move(tree.sz);
}

template <typename T>
void RedBlackTree<T>::deleteTree(Node *tree)
{
    deleteTree(tree->left);
    deleteTree(tree->right);
    delete tree;
}

template <typename T>
RedBlackTree<T> RedBlackTree<T>::copyTree(RedBlackTree<T> copy)
{
    Node *origin = new Node *{null, null, null};
    origin->left = copyTree(copy.head->left);
    origin->right = copyTree(copy.head->right);
    return origin;
}

template <typename T>
RedBlackTree<T> RedBlackTree<T>::operator=(const RedBlackTree<T> &tree)
{
    root = copyTree(tree.node);
    sz = tree.sz;
    return *this;
}

template <typename T>
RedBlackTree<T> RedBlackTree<T>::operator=(const RedBlackTree<T> &&tree) noexcept
{
    root = std::move(tree.node);
    sz = tree.sz;
    return *this;
}

template <typename T>
int RedBlackTree<T>::size() const noexcept
{
    return sz;
}
#endif