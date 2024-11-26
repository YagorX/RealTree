#pragma once

#include "Tree.h"

using namespace std;

void TestTreeCheck() {
    using T = TreeNode<int>;
    T* root1 = N(6, N(4, N(3), N(5)), N(7));
    assert(CheckTreeProperty(root1));

    T* root2 = new T{ 6,
        new T{4, new T{3}, new T{5}}, new T{7, new T{8}} };
    assert(!CheckTreeProperty(root2));

    DeleteTree(root1);
    DeleteTree(root2);
}

void Test_ChechTreeIt() {
    using T = TreeNode<int>;

    T* root = N(6, N(4, N(3), N(5)), N(8, N(7)));
    cout << root << endl;

    T* iter = begin(root);

    while (iter) {
        cout << iter->value << " "s;
        iter = next(iter);
    }
    cout << endl;

    DeleteTree(root);
}