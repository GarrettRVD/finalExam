// File: HousePrice
// Created by Hugo Valle on 11/22/2017.
// Copyright (c) 2017 WSU
//

#ifndef HW8_HOUSEPRICE_H
#define HW8_HOUSEPRICE_H

#include <iostream>
#include <string>
using namespace std;

/*!
 * Class HousePrice
 */
class HousePrice
{
private:
    int id;
    int number;
    string street;
    string city;
    string state;
    int postalCode;
    double price;
public:
    HousePrice();
    HousePrice(int i, int num, const string & strt,
               const string & cy, const string & st,
               int pc, double p);

    double getPrice() const;

    const string &getState() const;

    friend ostream & operator << (ostream &os, const HousePrice &price);
};
//friend ostream & operator << (ostream &os, const HousePrice &price);


#endif //HW8_HOUSEPRICE_H
