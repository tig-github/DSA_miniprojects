#ifndef REDBLACK
#define REDBLACK

#include <functional>

template <typename T>
class RedBlackTree
{
private:
    struct Node
    { // parent pointer implementation
        T data;
        Node *left;
        Node *right;
    };

public:
    using V = std::function<void(const T &)>;

    RedBlackTree();
    RedBlackTree(const RedBlackTree<T> &tree);
    ~RedBlackTree() noexcept
    {
    }
    RedBlackTree(RedBlackTree<T> &&tree) noexcept
    {
    }
    RedBlackTree<T> operator=(const RedBlackTree<T> &tree)
    {
    }
    RedBlackTree<T> operator=(const RedBlackTree<T> &&tree) noexcept
    {
    }
    int size() const noexcept
    {
    }
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
};

template <typename T>
RedBlackTree<T>::RedBlackTree()
{
}

template <typename T>
RedBlackTree<T>::RedBlackTree(const RedBlackTree<T> &tree)
{
}

#endif