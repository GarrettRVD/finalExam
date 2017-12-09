// File: HousePrice
// Created by Hugo Valle on 11/22/2017.
// Copyright (c) 2017 WSU
//

#include "HousePrice.h"


HousePrice::HousePrice()
{

}

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

double HousePrice::getPrice() const
{
    return price;
}

const string &HousePrice::getState() const
{
    return state;
}

ostream &operator<<(ostream &os, const HousePrice &price)
{
    os << "id: " << price.id << " number: " << price.number << " postalCode: "
       << price.postalCode << " street: " << price.street << " city: " << price.city
       << " state: " << price.state << " price: " << price.price;
    return os;
}
