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

   stringstream ss;

   string instruction;
   
   string token;
   int shares = 0;
   string command;
   char trash = ' ';
   double dollars = 0;
   //string stringDollars;
   //cin >> instruction;
   while (instruction != "quit")
   {
	   getline(cin, instruction);
	   istringstream ss(instruction);
	   ss >> command >> shares >> trash >> dollars;
	   cout << "command:" << command << " shares:" << shares << " trash:" << trash << " dollars:" << dollars;
	  // int i = 0;
	  // switch (token)
	  //{
		 //  case 'b':
			//   i + 4;
			//   break;
		 //  case 's':
			//   i + 5;
		 //  break;
	  // }
	  // if (i == 4)
	  // {
		 //  while (isalnum(instruction[i]))
		 //  {
			//   numberOfShares.append(1, instruction[i]);
			//   i++;
		 //  }
		 //  while (i < instruction.length())
		 //  {
			//   stringDollars.append(1, instruction[i]);
			//   i++;
		 //  }
	  // }
	  // else if (i == 5)
	  // {

	  // }
	   if (command == "buy")
	   {
		   buyStock(shares, dollars);
	   }
	   else if (command == "sell")
	   {
		   sellStock(shares, dollars);
	   }
	   else if (command == "display")
	   {
		   display();
	   }
   }
}

void buyStock(int shares, double dollars)
{
}

void sellStock(int shars, double dollars)
{
}

void display()
{
}

// TODO delete main
//int main()
//{
//	return 0;
//};


