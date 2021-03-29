#include <functional>
#include <iostream>
#include <ostream>
#include <stdio.h>
#include <stdlib.h>

#include "../src/BinaryTree.hpp"
#include "../src/HoeffdingTree.hpp"
#include "Tester.hpp"

int main() {

    // Run tests
    Tester ts;

#ifdef __BINARY_TREE_HPP__
    ts.addTest("Root Node Exists", []() {
        BinaryTree tree;
        return tree.getRootNode();
    });

    ts.addTest("New tree has size 1", []() {
        BinaryTree tree;
        return tree.getSize() == 1;
    });

    ts.addTest("Add node", []() {
        BinaryTree tree;
        BinaryTree::Node *root = tree.getRootNode();

        root->addLeftChild();
        return tree.getSize() == 2;
    });

    ts.addTest("Add Left Child", []() {
        BinaryTree tree;
        BinaryTree::Node *root = tree.getRootNode();
        root->addLeftChild();

        return root->getLeftChild();
    });

    ts.addTest("Add Right Child", []() {
        BinaryTree tree;
        BinaryTree::Node *root = tree.getRootNode();
        root->addRightChild();

        return root->getRightChild();
    });

    ts.addTest("Root with left child has size 2", []() {
        BinaryTree tree;
        BinaryTree::Node *root = tree.getRootNode();
        root->addLeftChild();

        return tree.getSize() == 2;
    });

    ts.addTest("Root with right child has size 2", []() {
        BinaryTree tree;
        BinaryTree::Node *root = tree.getRootNode();
        root->addRightChild();

        return tree.getSize() == 2;
    });

    ts.addTest("Add 2 childs", []() {
        BinaryTree tree;
        BinaryTree::Node *root = tree.getRootNode();
        root->addLeftChild()->addLeftChild();

        return tree.getSize() == 3;
    });

    ts.addTest("Add 2 childs, remove both", []() {
        BinaryTree tree;
        BinaryTree::Node *root = tree.getRootNode();
        root->addLeftChild()->addLeftChild();

        if (root->hasLeftChild())
            return root->getLeftChild()->hasLeftChild();

        return false;
    });
#endif
#ifdef __HOEFFDING_TREE_HPP__

    /*ts.addTest("Train Hoeffding Tree", []() {
        HoeffdingTree tree;
        return tree.train();
    });*/

#endif

    ts.runTestSuite(false);

    return 0;
}
