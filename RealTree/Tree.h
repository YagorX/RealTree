#pragma once

#include <cassert>

using namespace std;

template <class T>
struct TreeNode {
    T value;
    TreeNode* parent = nullptr;
    TreeNode* left = nullptr;
    TreeNode* right = nullptr;
};

template <class T>
void DeleteTree(TreeNode<T>* node) {
    if (!node) {
        return;
    }
    DeleteTree(node->left);
    DeleteTree(node->right);
    delete node;
}

template <typename T>
bool CheckTreeProperty(const TreeNode<T>* node) {
    if (node->left == nullptr && node->right == nullptr)
        return true;


    if (!(node->left->value < node->value && node->right->value > node->value))
        return false;
    else {
        return CheckTreeProperty(node->left) && CheckTreeProperty(node->right);
    }
}


template <class T>
void PrintTree(const TreeNode<T>* root, ostream& out = cout) {
    out << " ( "s;
    out << root->value;
    if (root->left || root->right) {
        if (root->left) {
            PrintTree(root->left, out);
        }
        else {
            out << "*"s;
        }
        if (root->right) {
            PrintTree(root->right, out);
        }
        else {
            out << "*"s;
        }
    }
    out << " ) "s;
}

template <class T>
ostream& operator << (ostream& out, const TreeNode<T>* node) {
    PrintTree(node, out);
    return out;
}

template <class T>
TreeNode<T>* begin(TreeNode<T>* node) {
    while (node->left != nullptr)
        node = node->left;
    return node;
}

template <class T>
TreeNode<T>* next(TreeNode<T>* node) {
    if (!node) { return nullptr; }

    if (node->right)
        return begin(node->right);

    TreeNode<T>* parent = node->parent;
    while (parent && node == parent->right) {
        node = parent;
        parent = parent->parent;
    }
    return parent;
}

// функция создаёт новый узел с заданным значением и потомками
TreeNode<int>* N(int val, TreeNode<int>* left = nullptr, TreeNode<int>* right = nullptr) {
    auto res = new TreeNode<int>{ val, nullptr, left, right };
    if (left) {
        left->parent = res;
    }
    if (right) {
        right->parent = res;
    }

    return res;
}


