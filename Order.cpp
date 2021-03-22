// Order.cpp
// @Author: Kray Nguyen
// 3/15/2021
// this class represents a starbucks order which includes item and its size with the price and stars of the total order
#include "Order.h"
#include <string>
#include <iostream>

using namespace std;

// constructor default
Order::Order(){
    price = 0;
    stars = 0;
}


// parametized constructor
// set order_item and order_size
// @param {vector<string>} - order_list: list of order for extraction
// @pre: param is valid
// @post: order_item and order_size is updated for process
// @return: none
// @function called: none
Order::Order(vector<string> order_list){
    price = 0;
    stars = 0;

    // extracting size information of every order
    for(int i = 0; i < order_list.size();i++){
        recent_item = order_list[i];
        for(int j = 0; j < recent_item.length(); j++){
            if(recent_item[j] == '['){
                size = "";
                int k = j+1;
                while(recent_item[k] != ']'){
                    size += recent_item[k];
                    k++;
                }
                break;
            }
        }

        // token extracting each order item
        char *token = strtok((char*) recent_item.c_str(), "[");

        order_items.push_back(token);
        order_size.push_back(size);
    }
}

// getter for funds
double Order::getFunds(){
    price = 0;

    // welcome to add short, trenta, etc. size price
    for(int i = 0; i < order_items.size(); i++){
        if(order_size[i] == "Venti"){
            price += venti;
        } else if (order_size[i] == "Tall"){
            price += tall;
        } else if (order_size[i] == "Grande"){
            price += grande;
        }
    }
    return price;
}

// getter for stars from the order cost
// basic star algorithm: 2*/$1
double Order::getStars(){
    return getFunds() *2.0;
}
