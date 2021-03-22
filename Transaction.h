// Transaction.h
// @Author: Kray Nguyen
// 3/15/2021
// this class represents a transaction upon the customer request
#ifndef _TRANS_
#define _TRANS_
#include <fstream>
#include <iostream>
#include <vector>
#include <string.h>
#include <sstream>
#include "Customer.h"
#include "Bst.h"


using namespace std;

class Transaction{
    friend ostream& operator<<(ostream &the_stream,const Transaction &other){
        return the_stream;
    }

public:
    Transaction();
    bool setData(ifstream & fileName, Bst &customer_collection);
    bool setStars(int amount);
    bool setFunds(int amount);
    bool addFund(int amount);
    bool reduceFund(int amount);
    bool addStars(int amount);
    bool reduceStars(int amount);
    int getStars();
    int getFunds();
    bool setType(char type);
    char getType();
    bool setDescription(string line);
    string getDescription();
    
private:
    // basic info of a transaction
    // request, name, drinks, size, type, stars, funds, deposit amount
    string request, name, drinks, size;
    char trans_type;
    double stars, funds, dep_amount;
};

#endif