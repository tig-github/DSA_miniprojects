// Persistent Implementation of RedBlack Tree
// limited path copying using fat node method
#ifndef REDBLACK
#define REDBLACK

#include <functional>
#include <iostream>
#include <algorithm>

template <typename T>
class RedBlackTree
{
public:
    struct Node
    { // parent pointer implementation
        T data;
        Node *left;
        Node *right;
        Node *fat; //fat node approach, note that k=1 is sufficient to achieve good complexity
        int color; // red = 1, black = 0
        int height;
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
    void insert(Node* node, const T value, int h = 1);
    void remove(Node* node, const T value);
    T search(Node* node, const T value);
    bool contains(Node* node, const T value) const;
    int height(Node* node) const;

    // traversals
    void inorder(Node *root, V visit) const;
    void preorder(Node *root, V visit) const;
    void postorder(Node *root, V visit) const;
    void printTree(Node* root) const;

private:
    void deleteTree(Node *tree);
    RedBlackTree<T> copyTree(RedBlackTree<T> copy);
    void balanceTree(Node *tree); //handles RB tree rotations
    void pathCopy(Node *tree); //handles limited path copying
};


// implementations
template <typename T>
RedBlackTree<T>::RedBlackTree()
{
    root = nullptr;
    sz = 0;
}

template <typename T>
RedBlackTree<T>::RedBlackTree(const RedBlackTree<T> &tree)
{
    root = copyTree(tree);
    sz = 0;
}

template <typename T>
RedBlackTree<T>::~RedBlackTree() noexcept
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
    if (tree == nullptr){
        return;
    }
    deleteTree(tree->left);
    deleteTree(tree->right);
    delete tree;
}

template <typename T>
RedBlackTree<T> RedBlackTree<T>::copyTree(RedBlackTree<T> copy)
{
    if (copy.head == nullptr){
        return nullptr;
    }
    Node *origin = new Node *{copy.root->data, nullptr, nullptr, nullptr, copy.head->color, 0};
    origin->left = copyTree(copy.root->left);
    origin->right = copyTree(copy.root->right);
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
    root = std::move(tree.root);
    sz = tree.sz;
    return *this;
}

template <typename T>
int RedBlackTree<T>::size() const noexcept
{
    return sz;
}

template <typename T>
bool RedBlackTree<T>::contains(Node* node, const T value) const {
    if (node == nullptr){
        return false;
    }
    else if (node->data == value) {
        return true;
    }
    return contains(node->left, value) || contains(node->right, value);
}

template <typename T>
int RedBlackTree<T>::height(Node* node) const {
    if (node == nullptr) {
        return 0;
    }
    if (node->left == nullptr && node->right == nullptr){
        return node->height;
    }
    return std::max(height(node->left), height(node->right));
}


template <typename T>
void RedBlackTree<T>::insert(Node* node, const T value, int h)
{
    if (node == nullptr)
    {
        root = new Node{value, nullptr, nullptr, nullptr, 0, 0};
        return;
    }
    if (node->data > value)
    {
        if (node->left != nullptr){
            insert(node->left, value, h+1);
        }
        else{
            node->left = new Node{value, nullptr, nullptr, nullptr, 0, h};
        }
    }
    if (node->data < value)
    {
        if (node->right != nullptr){
            insert(node->right, value, h+1);
        }
        else{
            node->right = new Node{value, nullptr, nullptr, nullptr, 0, h};
        }
    }
}

// persistent so nothing is removed, just requires fat-node path copying to replace with newer and save older
template <typename T>
void RedBlackTree<T>::remove(Node* node, const T value)
{
}

template <typename T>
T RedBlackTree<T>::search(Node* node, const T value)
{
    if (node->data == value || (node->left == nullptr && node->right == nullptr)){
        return node->data;
    }
    else if (node->data > value){
        return search(node->left, value);
    }
    else {
        return search(node->right, value);
    }
}


template <typename T>
void RedBlackTree<T>::inorder(Node *root, V visit) const
{
    if (root == nullptr){
        return;
    }
    inorder(root->left, visit);
    visit(root->data);
    inorder(root->right, visit);
}

template <typename T>
void RedBlackTree<T>::preorder(Node *root, V visit) const
{
    if (root == nullptr){
        return;
    }
    visit(root->data);
    preorder(root->left, visit);
    preorder(root->right, visit);
}

template <typename T>
void RedBlackTree<T>::postorder(Node *root, V visit) const
{
    if (root == nullptr){
        return;
    }
    postorder(root->left, visit);
    postorder(root->right, visit);
    visit(root->data);
}

template <typename T>
void RedBlackTree<T>::printTree(Node* node) const{
    if (node != nullptr){
        std::cout << node->data << " | ";
        printTree(node->left);
        printTree(node->right);
    }

}

#endif