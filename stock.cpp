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

void buyStock(int shares, Dollars dollars)
{
	qShares.push(shares);
	qDollars.push(dollars);
}

Dollars sellStock(int sharesToBeSold, Dollars dollars)
{
	int soldShares = 0;
	Dollars proceeds = 0;
	// While we haven't sold enough shares
	while (soldShares < sharesToBeSold)
	{
		// adding one still won't be enough
		if ((soldShares + qShares.front()) < sharesToBeSold)
		{
			// add shares of one transaction
			soldShares += qShares.front();
			// figure out the proceeds 
			proceeds += (dollars - qDollars.front()) * qShares.front();
			// remove that transaction
			qShares.pop();
			qDollars.pop();
		}
		// adding one is more than enough
		else
		{
			// get rid of some of the shares in the front transaction of the queue
			qShares.front() -= (sharesToBeSold - soldShares);
			// proceeds = buying price * the rest of the shares we need to sell
			proceeds += (dollars - qDollars.front()) * (sharesToBeSold - soldShares);
			// We sold all the shares we needed to sell, update the record
			soldShares = sharesToBeSold;
		}
	}
}

void display(Dollars proceeds)
{

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
	string instruction;
	int shares = 0;
	string command;
	char trash = ' ';
	double dollars;
	Dollars ddollars;
	while (instruction != "quit")
	{
		getline(cin, instruction);
		istringstream ss(instruction);
		ss >> command >> shares >> trash >> dollars;
		ddollars = dollars;
		cout << "command:" << command << " shares:" << shares << " trash:" << trash << " dollars:" << dollars;
		if (command == "buy")
		{
			buyStock(shares, ddollars);
		}
		else if (command == "sell")
		{
			proceeds = sellStock(shares, ddollars);
		}
		else if (command == "display")
		{
			display(proceeds);
		}
	}
}

// TODO delete main
int main()
{
	stocksBuySell();
	return 0;
};

