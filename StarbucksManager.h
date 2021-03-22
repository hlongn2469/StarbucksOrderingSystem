#ifndef _STARBUCKS_MANAGER_
#define _STARBUCKS_MANAGER_

#include "Bst.h"
#include "Customer.h"
#include "Transaction.h"
#include <queue>
#include <string>
// StarbucksManager.h
// @Author: Kray Nguyen
// 3/15/2021
// This class models the starbucks manager which process the file to the system
// and display all customers info with their transcation history
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <sstream>

using namespace std;

class StarbucksManager {
public:

    // constructor
    StarbucksManager();
    ~StarbucksManager();
    
    // process file
    void processFile(ifstream & fileName);

    // show report
    void displayHistory();
private:
    string request, name, drinks, size;
    int dep_amount;
    Customer Cus;

    // BST storing customer objects
    Bst customer_collection;

    // queue of transactions
    queue<Transaction> collectionTransactions;
};

#endif //!_STARBUCKS_MANAGER_