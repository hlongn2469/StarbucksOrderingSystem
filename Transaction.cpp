// Transaction.cpp
// @Author: Kray Nguyen
// 3/15/2021
// this class represents a transaction upon the customer request
#include "Transaction.h"

// default constructor
Transaction::Transaction(){
    funds = 0;
    stars = 0;
}

// set data from file and process each request, either deposit or order
// @param {ifstream &fileName} - fileName: input file for processubg
// @param {Bst&} - customer_collection: Bst object storing customers
// @pre: param is valid
// @post: deposit case - customer added to the Bst
//        ordering case - customer account stars and funds adjusted upon order request
// @return: true if process sucessfully

bool Transaction::setData(ifstream & fileName, Bst &customer_collection){
    string description;
    while(getline(fileName, description)){
        request = description;
        char *token = strtok((char*) description.c_str(), " ");
        stringstream copy(description);
        // Deposit case
        if(description.at(0) == 'D'){
            Customer* account;
            trans_type = 'D';
            token = strtok(nullptr, " ");
            name = token;
            token = strtok(nullptr, " ");
            name += " ";
            name += token;
            token = strtok(nullptr, " ");
            dep_amount = stoi(token);
            // if the account is already opened, we deposit the new amount into their account
            if(customer_collection.retrieve(name, account)){
                account->addFund(dep_amount);
            // if not, we open one for them and initialize their first deposit
            } else {
                account = new Customer(name, dep_amount, request);
                
                customer_collection.insert(account);
            }
        // ordering case
        } else {
            string beverage;
            istringstream ss(description);
            trans_type = 'O';
            name = token;
            token = strtok(nullptr, " ");
            name += " ";
            name += token;
            token = strtok(nullptr, "\t");

            Customer* account;
            vector<string> order_list;
            if(!customer_collection.retrieve(name, account)){
                cout << name << ": Customer is new, needs deposit first" << endl;
            } else {
                // while there are remaining orders
                while(getline(ss, beverage)){
                    order_list.push_back(token);
                }   

                account->setOrder(order_list);

                // create new order
                Order* new_order = new Order(order_list);
                // get the order stars and due amount
                stars = new_order->getStars();
                funds = new_order->getFunds();

                // plus stars and subtract funds from the customer account
                if(!account->reduceFund(funds)){
                    cout << name << " not enough money, please deposit more" << endl;
                }

                account->addStars(stars);

                account->addHistory(*new_order);
            }
        }
    }
    return true;
}

// setter for funds
bool Transaction::setFunds(int amount){
    this->funds = amount;
    return true;
}

// setter for stars
bool Transaction::setStars(int amount){
    this->stars = amount;
    return true;
}

// add customer funds from given amount
// @param {double} - amount: amount of deposit amount
// @pre: param valid, fund is positive
// @post: funds added from the given amount
// @return: true if add fund sucessfully
// @function called: none
bool Transaction::addFund(int amount){
    this->funds += amount;
    return true;
}

// reduce customer funds from given amount
// @param {double} - amount: amount of cost
// @pre: param valid, fund is positive
// @post: funds reduced from the given amount
// @return: true if reduce fund sucessfully
// @function called: none
bool Transaction::reduceFund(int amount){
    this->funds -= amount;
    if(funds < 0){
        funds+= amount;
        return false;
    }
    return true;
}

// add customer stars from given amount
// @param {double} - amount: amount of stars need to be added
// @pre: param valid
// @post: stars added from the given amount
// @return: true if add stars sucessfully
// @function called: none
bool Transaction::addStars(int amount){
    this->stars += amount;
}

// reduce customer stars from given amount
// @param {double} - amount: amount of stars need to be reduced
// @pre: param valid
// @post: stars reduced from the given amount
// @return: true if reduce stars sucessfully
// @function called: none
bool Transaction::reduceStars(int amount){
    this->stars -= amount;
    if(stars < 0){
        return false;
    }
    return true;
}

// getter for stars
int Transaction::getStars(){
    return stars;
}

// getter for funds
int Transaction::getFunds(){
    return funds;
}

// getter for transaction type
char Transaction::getType(){
    return this->trans_type;
}

// setter for transaction type
bool Transaction::setType(char type){
    this->trans_type = type;
    return true;
}


// setter for request file description
bool Transaction::setDescription(string line){
    this->request = line;
    return true;
}

// getter for request file description
string Transaction::getDescription(){
    return request;
}