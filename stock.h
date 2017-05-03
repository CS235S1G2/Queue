/***********************************************************************
 * Header:
 *    STOCK
 * Summary:
 *    This will contain just the prototype for stocksBuySell(). You may
 *    want to put other class definitions here as well.
 * Author
 *    <your names here>
 ************************************************************************/

#ifndef STOCK_H
#define STOCK_H

#include "dollars.h"   // for Dollars defined in StockTransaction
#include <queue>
 //TODO #include "queue.h"     // for QUEUE
#include <iostream>    // for ISTREAM and OSTREAM

// the interactive stock buy/sell function
void stocksBuySell();

void buyStock(int shares, double dollars);
void sellStock(int shars, double dollars);

void display();

std::queue<int> sharesBought;
std::queue<int> sharesSold;
std::queue<double> dollarsBought;
std::queue<double> dollarsSold;




#endif // STOCK_H

