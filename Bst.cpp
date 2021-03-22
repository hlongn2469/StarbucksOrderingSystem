// Bst.cpp
// @Author: Kray Nguyen
// 3/15/2021
// this class represents a binary search tree to store starbucks customer account
#include "Bst.h"
#include <string>
#include <iostream>

using namespace std;

Bst::Bst() {
    root_ = nullptr;
}

Bst::~Bst() {
    flush();
}

// check whether the BST is empty or not
// @pre: Bst object is initialized
// @post: none
// @return: true if Bst is empty
// @function called: none
bool Bst::isEmpty()const{
    return root_ == nullptr;
}

// deallocate memory to prevent memory leaks
// @pre: Bst object is initialized
// @post: all nodes deleted in the BST
// @return: true if Bst is empty
// @function called: flushHelper()
void Bst::flush(){
    if(root_ != nullptr){
        flushHelper(root_);
    }
    root_ = nullptr;
}

// helper method to deallocate memory leaks
// @param {Node*} - root: node pointers for tree traversal purposes
// @pre: Bst object is initialized, root is valid
// @post: all nodes deleted in the BST
// @return: none
// @function called: flushHelper()
void Bst::flushHelper(Node* root){
    if(root != nullptr){
        flushHelper(root -> left);
        flushHelper(root -> right);
        delete root;
    }
}

// retrieve customer account from the system if exists 
// @param {string} - name: target client name to find
// @param {Customer*&} - value: reference the customer if account found
// @pre: Bst object is initialized, param is valid
// @post: none
// @return: true if customer account exists 
// @function called: retrieverHelper()
bool Bst::retrieve(string name, Customer *& value){
    return retrieveHelper(root_, name, value);
}

// helper method to retrieve customer account from the system if exists 
// @param {Node*} - current: Node to traverse
// @param {string} - target_name: target client name to find
// @param {Customer*&} - retriever: reference the customer if account found
// @pre: Bst object is initialized, param is valid
// @post: none
// @return: true if customer account exists 
// @function called: retrieverHelper()
bool Bst::retrieveHelper(Node* current, string target_name, Customer *& retriever){
    // base case 
    if(current == nullptr){
        retriever = nullptr;
        return false;

    } else {
        // lesser case
        if(target_name < current->value->getName()){
            return retrieveHelper(current->left, target_name, retriever);

        // larger case
        } else if (target_name > current->value->getName()){
            return retrieveHelper(current->right, target_name, retriever);

        // found
        } else {
            retriever = current->value;
            return true;
        }
    }
    return false;
}

// Insert the customer into the system
// @param {Customer*} - current: insert pointer of the customer
// @pre: Bst object is initialized, Customer is valid
// @post: new customer inserted into the BST and remains the BST property
// @return: true if insert sucessfully, false otherwise
// @function called: insertHelper()
bool Bst::insert(Customer* cus){
    // if nothing in the system yet
    if(root_ == nullptr){
        // new customer account
        root_ = new Node{cus, nullptr, nullptr};
        return true;
    } else {
        return insertHelper(root_,cus);
    }
}

// helper method Insert the customer into the system
// @param {Node*&} - root: current root node for traversal purposes
// @param {Customer*} - cus: insert pointer of the customer
// @pre: Bst object is initialized, Customer is valid
// @post: new customer inserted into the BST and remains the BST property
// @return: true if insert sucessfully, false otherwise
// @function called: insertHelper()
bool Bst::insertHelper(Node*& root, Customer* cus){
    // base case -> insert new customer account
    if(root == nullptr){
        root = new Node {cus, nullptr, nullptr};
        return true;
    
    //lesser case
    } else if(*cus < *root->value){
        return insertHelper(root->left, cus);
    
    // greater case
    } else if(*cus > *root->value){
        return insertHelper(root->right, cus);
    }
    return false;
}

// print the enitre BST preorderly
// @param {ostream&} - the_stream: for output stream
// @pre: Bst object is initialized, param is valid
// @post: all client accounts info in alphatical order printed to the screen
// @return: none
// @function called: printHelper()
void Bst::print(ostream & the_stream) const{
    printHelper(the_stream, root_);
}

// print the enitre BST preorderly
// @param {ostream&} - the_stream: for output stream
// @param {Node*} - root: root node for traversal
// @pre: Bst object is initialized, param is valid
// @post: all client accounts info in alphatical order printed to the screen
// @return: none
// @function called: printHelper()
void Bst::printHelper(ostream & the_stream, Node* root) const{

    // base case
    if(root == nullptr){
        return;
    } else {
        // goes left
        printHelper(the_stream, root -> left);

        // print
        the_stream << *root->value << endl;

        // goes right
        printHelper(the_stream, root -> right);
    } 
}