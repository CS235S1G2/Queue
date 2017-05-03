/***********************************************************************
* Implementation:
*    STOCK
* Summary:
*    This will contain the implementation for stocksBuySell() as well
*    as any other function or class implementation you need
* Author
*    <your names here>
**********************************************************************/

#include <iostream>    // for ISTREAM, OSTREAM, CIN, and COUT
#include <string>      // for STRING
#include <sstream>
#include <cassert>     // for ASSERT
#include "stock.h"     // for STOCK_TRANSACTION
#include "dollars.h"   // used to handle currency
//TODO add back in queue #include "queue.h"     // for QUEUE
#include <queue>
using namespace std;

queue <int> qShares;
queue <Dollars> qDollars;
queue <string> qSellHistory;

void buyStock(int sharesToBeBought, Dollars buyPrice)
{
	qShares.push(sharesToBeBought);
	qDollars.push(buyPrice);
}

Dollars sellStock(int sharesToBeSold, Dollars sellPrice)
{
	int soldShares = 0;
	Dollars proceeds = 0;
	// While we haven't sold enough shares
	while (soldShares < sharesToBeSold)
	{
		// while adding one transaction still won't be enough keep 
		// adding transactions
		while ((soldShares + qShares.front()) < sharesToBeSold)
		{
			// add shares of one transaction
			soldShares += qShares.front();
			// figure out the proceeds 
			proceeds += (sellPrice - qDollars.front()) * qShares.front();
			// remove that transaction
			qShares.pop();
			qDollars.pop();
			// update the count of the shares we still need to sell
			sharesToBeSold -= soldShares;
		}
		// adding one is more than enough so add part of a transaction
		// get rid of some of the shares in the front transaction of the queue
		qShares.front() -= (sharesToBeSold);
		soldShares += sharesToBeSold;
		// proceeds = buying price * the rest of the shares we need to sell
		proceeds += (sellPrice - qDollars.front()) * (sharesToBeSold);
	}
		// We sold all the shares we needed to sell, update the record
		sharesToBeSold = 0;
		stringstream ss;
		string s1 = "Sold ";
		string s2 = " shares at ";
		string s3 = " for a profit of ";
		string s4 = " for a loss of ";
		// We made a profit
		if (proceeds >= 0)
			ss << s1 << soldShares << s2 << sellPrice << s3 << proceeds;
		// We made a loss
		else
		{
			proceeds = proceeds * -1;
			ss << s1 << soldShares << s2 << sellPrice << s4 << proceeds;
		}
		s1 = ss.str();
		qSellHistory.push(s1);
		return proceeds;
}

void display(Dollars proceeds)
{
	queue <Dollars> qTempDollars(qDollars);
	queue <int> qTempShares(qShares);
	cout << "Currently held:\n";
	while (!qTempShares.empty())
	{
		cout << "\tBought " << qTempShares.front() << " shares at " << qTempDollars.front();
		qTempShares.pop();
		qTempDollars.pop();
	}
	if (!qSellHistory.empty())
		cout << "\nSell History:\n";
	// while the queue is not empty
	while(!qSellHistory.empty())
	{
		cout << "\t" << qSellHistory.front() << endl;
		qSellHistory.pop();
	}
	cout << "Proceeds: " << proceeds << endl;
}

/************************************************
* STOCKS BUY SELL
* The interactive function allowing the user to
* buy and sell stocks
***********************************************/
void stocksBuySell()
{
	// instructions
	cout << "This program will allow you to buy and sell stocks. "
		<< "The actions are:\n";
	cout << "  buy 200 $1.57   - Buy 200 shares at $1.57\n";
	cout << "  sell 150 $2.15  - Sell 150 shares at $2.15\n";
	cout << "  display         - Display your current stock portfolio\n";
	cout << "  quit            - Display a final report and quit the program\n";

	Dollars proceeds;
	stringstream ss;
	string userInput;
	int shares = 0;
	string command; // ex. buy, sell, display
	Dollars price;
	while (userInput != "quit")
	{
		getline(cin, userInput);
		istringstream ss(userInput);
		ss >> command >> shares >> price;
		if (command == "buy")
		{
			buyStock(shares, price);
		}
		else if (command == "sell")
		{
			proceeds = sellStock(shares, price);
		}
		else if (command == "display")
		{
			display(proceeds);
		}
	}
}

