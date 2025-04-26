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

void DoInitializePriceList(void);
void DoSetItemPrice(void);
void DoRemoveItemFromList(void);


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
//Do -  by Dylan
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

//Do  - by Luka
void DoInitializePriceList(void) {
	char choice;
	cout << "Initialize Price List: Do you want to start over? (y/n): ";
	cin >> choice;

	if (choice == 'y' || choice == 'Y') {
		list.clear();
		cout << "Enter details for 5 items:\n";
		for (int i = 0; i < 5; ++i) {
			int code;
			string description;
			double price, discountRate;
			cout << "Enter code, description, price, and discount rate for item " << i + 1 << ": ";
			cin >> code >> description >> price >> discountRate;
			list.emplace_back(code, description, price, discountRate);
		}
	}
}
void DoSetItemPrice(void) {
	int code;
	double price;
	cout << "Enter item code and new price: ";
	cin >> code >> price;
	for (auto& item : list) {
		if (item.HasCode(code)) {
			item.SetPrice(price);
			return;
		}
	}
	cout << "Item not found.\n";
}
void DoRemoveItemFromList(void) {
	int code;
	cout << "Enter item code to remove: ";
	cin >> code;
	for (auto it = list.begin(); it != list.end(); ++it) {
		if (it->HasCode(code)) {
			i.erase(it);
			cout << "Item removed.\n";
			return;
		}
	}
	cout << "Item not found.\n";
}

//Do - by Maksym
// C 
void DoAddItemToList(void)
{
	if (numItems >= SIZE)
	{
		cout << "Item list is full. Cannot add more items" << endl;
		return;
	}
	int code;
	string description;
	double price, discountrate;

	cout << "Enter code: ";
	cin >> code;
	cin.ignore();

	cout << "Enter description: ";
	getline(cin, description);

	CItem newItem(code, description);

	cout << "Enter price: ";
	cin >> price;

	cout << "Enter discount: ";
	cin >> discountrate;

	//ADD in class
	newItem.SetPrice(price);
	newItem.SetDiscountRate(discountrate);

	//ADD in list
	list[numItems] = newItem;
	numItems++;

	cout << "Item added successfully" << endl;
}
// E
void DoSetItemDiscountRate(void)
{
	int code;
	double discountrate;
	bool found = false;

	cout << "Enter code: ";
	cin >> code;


	// search code
	for (int i = 0; i < numItems; i++)
	{
		if (list[i].HasCode(code))
		{
			cout << "Enter discount rate: ";
			cin >> discountrate;

			list[i].SetDiscountRate(discountrate);
			cout << "Discount rate updated for item" << endl;
			found = true;
			break;
		}
	}
	if (!found)
	{
		cout << "Item with this code was not found." << endl;
	}
}
// G
void DoOrderCost(void)
{
	int code, quantity;
	string discount = "";

	cout << "Enter code: ";
	cin >> code;

	cout << "Enter quantity: ";
	cin >> quantity;

	//search
	for (int i = 0; i < numItems; i++)
	{
		if (list[i].HasCode(code))
		{
			double priceI = list[i].GetPrice();
			double discRI = list[i].GetDiscountRate();

			cout << "Whether a discount will be given  Y / N: ";
			cin >> discount;

			if (discount == "Y" || discount == "y")
			{
				double priceWithDiscount = priceI - (priceI * discRI);
				double total1 = priceWithDiscount * quantity;
				cout << fixed << setprecision(2);
				cout << "Order total with discount: " << total1 << " euros" << endl;
			}
			else
			{
				double total2 = priceI * quantity;
				cout << "Order total without discount: " << total2 << endl;
			}
			break;
		}
	}
}



