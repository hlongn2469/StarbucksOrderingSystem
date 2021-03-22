// Customer.h
// @Author: Kray Nguyen
// 3/15/2021
// this class represents starbucks customer account and main operations around ordering, funds, and stars.

#ifndef _CUS_
#define _CUS_
#include <string>
#include <iostream>
#include <vector>
#include <queue>
#include "Order.h"

using namespace std;

class Customer{
    // operator << print account balance, stars, and customer name
    friend ostream& operator<<(ostream &the_stream,const Customer &other){
        cout << other.name << " Account balance: " << other.funds << " Stars: " << other.stars << "*" << endl;
        for(int i = 0; i < other.order_history.size(); i++){
            cout << other.order_history[i] << endl;
        }
        return the_stream;
    }

public:
    Customer();
    Customer(string name, double dep_amount, string request);
    void addHistory(Order order);
    void setOrder(vector <string> order_list);
    string getName();
    bool reduceFund(double amount);
    bool addStars(double amount);
    bool addFund(double amount);
    vector<string> getOrder();
    double getStars();
    double getFunds();
    bool operator<(const Customer& other) const;
    bool operator>(const Customer& other) const;
    bool operator==(const Customer& other) const;
    bool operator!=(const Customer& other) const;
private:
    // order
    Order order;

    // necessary infos of a starbucks customer
    string name;
    string request;
    double account_id, stars, funds;

    // order history for later display
    vector <Order> order_history;

    // queues of ordering list
    queue<vector<string>> order_lists;
};

#endif //_CUS_