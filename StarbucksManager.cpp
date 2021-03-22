// StarbucksManager.cpp
// @Author: Kray Nguyen
// 3/15/2021
// This class models the starbucks manager which process the file to the system
// and display all customers info with their transcation history
#include "StarbucksManager.h"

StarbucksManager::StarbucksManager() {

}

StarbucksManager::~StarbucksManager() {

}
    
// Takes in everyline and push every line of transaction description to the queue of
// transaction objects
void StarbucksManager::processFile(ifstream & fileName) {

    // check file exist or not
    if (!fileName) {
        cerr << "Could not read file" << endl;
        return;
    }

    Transaction* ptrTransaction = nullptr;

    // while there is still transaction to process
    while(!fileName.eof()){
        
        ptrTransaction = new Transaction();

        // check valid transaction
        if(ptrTransaction->setData(fileName, customer_collection)){
            
            // push to queue for later process
            collectionTransactions.push(*ptrTransaction);
        }

        // delete pointer to prevent mem leaks
        delete ptrTransaction;
    }
    
}

// show report of all open account in the BST
void StarbucksManager::displayHistory() {

    // read all file from bst
    cout << "Processing Done. Final Balances" << endl;
    cout << customer_collection << endl;
}