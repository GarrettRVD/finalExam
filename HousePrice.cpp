// File: HousePrice
// Created by Hugo Valle on 11/22/2017.
// Copyright (c) 2017 WSU
//

#include "stdafx.h"
#include "HousePrice.h"

/*!
 * Constructor : Default Constructor
 */
HousePrice::HousePrice()
{

}

/*!
 * Constructor : Constructor with 7 arguments
 * @param i : id
 * @param num : number
 * @param strt : street
 * @param cy : city
 * @param st : state
 * @param pc : postalCode
 * @param p : price
 */
HousePrice::HousePrice(int i, int num, const string & strt,
                       const string & cy, const string & st,
                       int pc, double p)
{
    id = i;
    number = num;
    street = strt;
    city = cy;
    state = st;
    postalCode = pc;
    price = p;
}

/*!
 * getPrice : get the price of the HousePrice object
 * @return : price
 */
double HousePrice::getPrice() const
{
    return price;
}

/*!
 * getState : get the state of the HousePrice object
 * @return : state
 */
const string &HousePrice::getState() const
{
    return state;
}

/*!
 * operator < overload that compares two HousePrice objects
 * @param lhs : first HousePrice object to compare
 * @param rhs : second HousePrice object to compare
 * @return : if the comparison is true or false
 */
bool operator < (const HousePrice & lhs, const HousePrice & rhs)
{
    return lhs.price < rhs.price;
}

/*!
 * operator << overload to output HousePrice objects
 * @param os : ostream
 * @param price : price of HousePrice object
 * @return : the output for os
 */
ostream &operator<<(ostream &os, const HousePrice &price)
{
    os << "id: " << price.id << " number: " << price.number << " postalCode: "
       << price.postalCode << " street: " << price.street << " city: " << price.city
       << " state: " << price.state << " price: " << price.price;
    return os;
}
