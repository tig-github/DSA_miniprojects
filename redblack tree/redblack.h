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
    void inorder(Node *root, V visit) const;
    void preorder(Node *root, V visit) const;
    void postorder(Node *root, V visit) const;

private:
    void deleteTree(Node *tree);
    RedBlackTree<T> copyTree(RedBlackTree<T> copy);
    void balanceTree(Node *tree);
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

template <typename T>
void RedBlackTree<T>::inorder(Node *root, V visit) const
{
    inorder(root->left, V);
    V(root);
    inorder(root->right, V);
}

template <typename T>
void RedBlackTree<T>::preorder(Node *root, V visit) const
{
    V(root);
    preorder(root->left);
    preorder(root->right);
}

template <typename T>
void RedBlackTree<T>::postorder(Node *root, V visit) const
{
    postorder(root->left);
    postorder(root->right);
    V(root);
}

#endif