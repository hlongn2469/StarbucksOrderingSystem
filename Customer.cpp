// Customer.cpp
// @Author: Kray Nguyen
// 3/15/2021
// this class represents starbucks customer account and main operations around ordering, funds, and stars.
#include "Customer.h"
#include <string>
#include <iostream>

using namespace std;

// default constructor
Customer::Customer(){
    stars = 0;
    funds = 0;
    
}

// parametized constructor
// @param {string} - name: customer name
// @param {double} - dep_amount: deposit amount
// @param {string} - request: order request
// @pre: param is valid
// @post: name,funds, request is set
// @return: none
// @function called: none
Customer::Customer(string name, double dep_amount, string request){
    this->name = name;
    this->funds = dep_amount;
    this->request = request;
}

// set list of current order to total order list
// @param {vector<string>} - order_list: current ordering list
// @pre: order list is not empty
// @post: order added to customer total ordering list
// @return: none
// @function called: push()
void Customer::setOrder(vector <string> order_list){
    order_lists.push(order_list);
}

// get list of order from total order list
// @param {vector<string>} - order_list: current ordering list
// @pre: order list is not empty
// @post: front item of order_lists popped
// @return: none
// @function called: front(), pop()
vector<string> Customer::getOrder(){
    vector<string> return_order = order_lists.front();
    order_lists.pop();
    return return_order;
}

// getter for customer name
string Customer::getName(){
    return this->name;
}

// getter for customer stars
double Customer::getStars(){
    return this->stars;
}

// getter for customer funds
double Customer::getFunds(){
    return this->funds;
}

// reduce customer funds from given amount
// @param {double} - amount: amount of cost
// @pre: param valid, fund is positive
// @post: funds reduced from the given amount
// @return: true if reduce fund sucessfully
// @function called: none
bool Customer::reduceFund(double amount){
    funds -= amount;
    if(funds < 0){
        funds += amount;
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
bool Customer::addStars(double amount){
    stars += amount;
    return true;
}

// add customer funds from given amount
// @param {double} - amount: amount of deposit amount
// @pre: param valid, fund is positive
// @post: funds added from the given amount
// @return: true if add fund sucessfully
// @function called: none
bool Customer::addFund(double amount){
    this->funds += amount;
    return true;
}

// add current order into ordering history
// @param {Order} - Order: order needs to be stored in order history
// @pre: param valid
// @post: the new order is added to the order history
// @return: none
// @function called: push_back()
void Customer::addHistory(Order order){
    order_history.push_back(order);
}

// operator less than
bool Customer::operator<(const Customer& other) const {
    return name < other.name;
}

// operator greater
bool Customer::operator>(const Customer& other) const {
    return name > other.name;
}

// operator equal
bool Customer::operator==(const Customer& other) const {
    return name == other.name;
}

// operator not equal
bool Customer::operator!=(const Customer & other) const {
    return name != other.name;
}
