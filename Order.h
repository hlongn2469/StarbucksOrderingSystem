// Order.h
// @Author: Kray Nguyen
// 3/15/2021
// this class represents a starbucks order which includes item and its size with the price and stars of the total order
#ifndef _ORD_
#define _ORD_
#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <string.h>
#include <sstream>

using namespace std;

// fixed value of starbucks size price
// can add more size
const double venti = 5.75;
const double grande = 4.5;
const double tall = 3.25;

class Order{
    // operator << printing out order item, its size, and its price
    friend ostream& operator<<(ostream &the_stream,const Order &other){
        for(int i = 0; i < other.order_items.size(); i++){
            cout << other.order_items[i] << " [" << other.order_size[i] << "] $" 
            << other.price << endl;
        }
        return the_stream;
    }

public:
    Order();
    Order(vector<string> order_list);
    double getFunds();
    double getStars();

private:
    // stars and price
    double stars;
    double price;
    string recent_item, size;
    int order_num;

    // list of order_items and size
    vector<string> order_items;
    vector<string> order_size;
};

#endif //_ORD_