//ProjectItem.cpp - main program
#include "CProjectItem.h"
#include <iostream>
#include <iomanip>
#include <fstream>

constexpr int SIZE = 25;
// keep in mind, check that the first record is not greater than size
// any code that reads through the remaining records and writes to the array
// don't do it more times than the number of elements in the array
// e.g. first record says 6 upcoming records but array size is 5
//       don't use first record (6) in for loop because it will go out of bounds
//       use array size (5) in for loop
// this would be done by a an if statement comparing SIZE with the first record
// leave all this till later - when doing enhancements
CItem list[SIZE];

int numItems = 0;

//void FillDummyData();

void DoDisplayFullPriceList(void);
void DoDisplayItem(void);
void DoTotalInvoice(void);

int main()
{
	//Process the file
	ifstream infile("Items.txt");
	if (!infile)
	{
		cout << "Error opening file\n";
		cout << "Use menu option 3 to add items to the list\n";
	}
    else
    {
		infile >> numItems;
		if (numItems > SIZE)
		{
			cout << "Too many items in file\n";
			cout << "Only the first " << SIZE << " items will be processed\n";
			numItems = SIZE;
		}
        int code;
		double price, discountRate;
		string description;
        for (int i = 0; i < numItems; i++)
        {
			infile >> code >> description >> price >> discountRate;
			CItem item(code, description, price, discountRate);
			list[i] = item;
        }
    }
	//opt.2
    DoDisplayFullPriceList();
	cout << endl;
	//opt.8
	DoTotalInvoice();
	cout << endl;
	//opt.6
	DoDisplayItem();
    //todo:LS:opt.1 DoInitializePriceList
    //todo:MS:opt.3 DoAddItemToList
    //todo:LS:opt.4 DoSetItemPrice
    //todo:MS:opt.5 DoSetItemDiscountRate
    //todo:MS:opt.7 DoOrderCost
    //todo:LS:opt.9 DoRemoveItemFromList
}

void DoDisplayFullPriceList(void)
{
   
    for (int i = 0; i < numItems; i++)
    {
        cout << "Item " << list[i].GetCode() << " is a " << list[i].GetDescription()
        <<" and costs "<<list[i].GetDiscount()<<" euros "<<"with a "
        <<list[i].GetDiscountRate()*100<<"% discount applied\n";
    }
}

void DoDisplayItem(void)
{
    int code; 
    cout << "Please enter item code for details: ";
    cin >> code;

	//error handling for code not found
	bool itemFound = false;
	for (int i = 0; i < numItems; i++)
	{
		if (list[i].HasCode(code))
		{
			list[i].Display();
			itemFound = true;
			break;
		}
	}
	if (!itemFound)
	{
		cout << "Item does not exist\n";
	}
}

void DoTotalInvoice(void)
{
	double total = 0;
	for (int i = 0; i < numItems; i++)
	{
		total += list[i].GetDiscount();
	}
	cout << "Total invoice amount: " << total << " euros\n";
}


