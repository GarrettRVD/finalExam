// File: HouseFunc
// Created by Hugo Valle on 11/22/2017.
// Copyright (c) 2017 WSU
//

#include <iostream>
#include "stdafx.h"
#include <vector>
#include <map>
#include "HouseFunc.h"
#include "HousePrice.h"
#include "csv.h" // library to read csv files
#include <algorithm>
#include <iomanip>


using namespace std;

/*!
* Read CSV Mock Data. Parses each record in the file to
* an object of HousePrice house. Then, populate a vector
* of HousePrice objects with all the records.
* It uses special library to parse CSV file "csv.h"
* @param fileIn File name <string>
* @param hp Reference to Vector of HousePrice Objects
*/
void readCSV(const string fileIn, vector<HousePrice>& hp)
{
    io::CSVReader<7> in(fileIn);
    in.read_header(io::ignore_extra_column, "id", "number", "street", "city", "state", "postalCode", "price");
    int id;
    int number;
    string street;
    string city;
    string state;
    int postalCode;
    double price;

    while (in.read_row(id, number, street, city, state, postalCode, price))
    {
        HousePrice house(id, number, street, city, state, postalCode, price);

        hp.push_back(house);
    }

    for (auto item : hp)
    {
        cout << item << endl;
    }

}




/*!
* Sort the Vector of HousePrice Objects by price. Display the most affordable
* and the most expensive house from the vector.
* @param hp Reference to vector<HousePrice>
*/
void houseMarketValues(vector<HousePrice> &hp)
{
    // Sort by Price
    sort(begin(hp), end(hp));

    auto min = min_element(begin(hp), end(hp));
    cout << "Most Affordable Home: " << *min << endl;

    auto max = max_element(begin(hp), end(hp));
    cout << "Most Expensive Home: " << *max << endl;

}


/*!
* Sort the Vector of HousePrice Objects by state. Display the
* number of houses per state.
* It uses a map to count instances per state.
* @param hp Reference to vector<HousePrice>
*/
void houseMarketPerState(vector<HousePrice> &hp)
{
    // Sort by State
    map<string, int> state;

    for (auto item : hp)
    {
        if (state.find(item.getState()) == state.end())
        {
            //Not found
            state[item.getState()] = 1;
        }
        else
        {
            //Found
            state[item.getState()]++;
        }
    }

    int i = 0;

    cout << "#Homes per State:" << endl;

    for (auto ip = state.begin(); ip != state.end(); ip++)
    {
        // the two components of my map are:
        // key->first             value->second

        cout << ip->first << " " << setw(4) << left << ip->second;

        i++;
        if (i == 10)
        {
            cout << endl;
            if (i == 10)
            {
                i = 0;
            }
        }
    }

}
