// main.cpp
// @Author: Kray Nguyen
// 3/15/2021
// Input: a desired txt file of orders
// Output: customer account printed alphabetical order with their name, account balance, stars, and transaction history
// Usage: ./a.out TuesdayOrder.txt
// Assumption: only 1 parameter is passed through the command line
// Assumption: There are still hidden errors that require tracking and improvement since this program is written from scratch
// Major algorithms: BST implemented to store customer account
#include "StarbucksManager.h"
#include <iostream>
#include <ostream>
#include <fstream>


using namespace std;

int main(int argc, char *argv[]){
    // manager object
    StarbucksManager manager;

    // grab file
    string file_name = argv[1];
    ifstream orderFile(file_name);

    // process file
    manager.processFile(orderFile);

    // display history after processing the transaction file
    manager.displayHistory();
    return 0;
}   