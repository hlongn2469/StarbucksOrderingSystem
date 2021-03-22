// Bst.h
// @Author: Kray Nguyen
// 3/15/2021

#ifndef _BST_
#define _BST_
#include <iostream>
#include <string>
#include "Customer.h"

using namespace std;

// this class represents a binary search tree to store starbucks customer account
class Bst {
    friend ostream& operator<<(ostream & the_stream, const Bst& rhs){
        rhs.print(the_stream);
        return the_stream;
    }
public:
    Bst();
    ~Bst();

    bool isEmpty() const;

    void flush();

    bool retrieve(string name, Customer *& value);

    bool insert(Customer* cus);

private:
    struct Node{
        Customer* value;
        Node* left;
        Node* right;
    };
    Node* root_;

    bool retrieveHelper(Node* current, string target_name, Customer *& value);

    bool insertHelper(Node*& root, Customer* cus);

    void flushHelper(Node* root);

    void printHelper(ostream & the_stream, Node* root) const;

    void print(ostream & the_stream) const;
};

#endif