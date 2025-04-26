//ProjectItem.cpp - main program
#include "CProjectItem.h"
#include <iostream>
#include <iomanip>
#include <fstream> 
using namespace std;
#include "CUser.h"

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

CUser users[3] = {
	CUser("Tom", "1234", 'M'),
	CUser("Fred", "9876", 'A'),
	CUser("Ger", "4321", 'A')
};

int ShowMenu(char uType);
void DoQuit(void);

void DoDisplayFullPriceList(void);
void DoDisplayItem(void);
void DoTotalInvoice(void);
void DoInitializePriceList(void);
void DoSetItemPrice(void);
void DoRemoveItemFromList(void);
void DoAddItemToList(void);
void DoSetItemDiscountRate(void);
void DoOrderCost(void);

void DoAddUser(void);
void DoEditUser(void);


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

	string Username, uPassword;
	char uType = ' ';
	bool loginSuccess = false;

	cout << "Enter user name : ";
	cin >> Username;
	cout << "Enter password: ";
	cin >> uPassword;
	cout << "Enter user type (M / A): ";
	cin >> uType;
	//heck to see if a matching user exists 
	for (int i = 0; i < 3; i++)
	{
		if (users[i].Match(Username, uPassword))
		{
			uType = users[i].GetType();
			loginSuccess = true;
			break;
		}

	}
	if (!loginSuccess)
	{
		cout << "Invalid username or password." << endl;
		return 0;
	}

	// Menu
	int option;
	do {
		option = ShowMenu(uType);

		try {
			switch (option) {
			case 1:
				if (uType == 'M')
					DoInitializePriceList();
				else
					cout << "Invalid option for Assistant.\n";
				break;
			case 2:
				DoDisplayFullPriceList();
				break;
			case 3:
				if (uType == 'M')
					DoAddItemToList();
				else
					cout << "Invalid option for Assistant.\n";
				break;
			case 4:
				DoSetItemPrice();
				break;
			case 5:
				DoSetItemDiscountRate();
				break;
			case 6:
				DoDisplayItem();
				break;
			case 7:
				DoOrderCost();
				break;
			case 8:
				DoTotalInvoice();
				break;
			case 9:
				if (uType == 'M')
					DoRemoveItemFromList();
				else
					cout << "Invalid option.\n";
				break;
			case 10:
				if (uType == 'M')
					DoAddUser();
				else
					cout << "Invalid option\n";
				break;

			case 11:
				if (uType == 'M')
					DoEditUser();
				else
					cout << "Invalid option.\n";
				break;
			case 0:
				DoQuit();
				break;
			default:
				cout << "Invalid option. Please try again.\n";
			}
		}
		catch (...) {
			cout << "!!! Error !!!" << endl;
			cout << "Returning to menu..." << endl;
		}

	} while (option != 0);

	return 0;
}
int ShowMenu(char uType)
{
	int option;
	cout << "\t Shopping List Menu " << endl;
	if (uType == 'M')
	{
		cout << "\t1. Initialize Price List" << endl;
		cout << "\t2. Display Full Price List" << endl;
		cout << "\t3. Add Item to List" << endl;
		cout << "\t4. Set Item Price" << endl;
		cout << "\t5. Set Item Discount Rate" << endl;
		cout << "\t6. Display Item" << endl;
		cout << "\t7. Order Cost" << endl;
		cout << "\t8. Total Invoice" << endl;
		cout << "\t9. Remove Item from List" << endl;
		cout << "\t10. Add User" << endl;
		cout << "\t11. Edit User" << endl;
		cout << "\t0. Quit" << endl;
	}
	else if (uType == 'A')
	{
		cout << "\t2. Display Full Price List" << endl;
		cout << "\t4. Set Item Price" << endl;
		cout << "\t5. Set Item Discount Rate" << endl;
		cout << "\t6. Display Item" << endl;
		cout << "\t7. Order Cost" << endl;
		cout << "\t8. Total Invoice" << endl;
		cout << "\t0. Quit" << endl;
	}
	cout << "\n\tEnter option : ";
	cin >> option;
	return option;
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
		// list.clear(); -- Error
		cout << "Enter details for 5 items:\n";
		/* -- Eroor
		for (int i = 0; i < 5; ++i) {
			int code;
			string description;
			double price, discountRate;
			cout << "Enter code, description, price, and discount rate for item " << i + 1 << ": ";
			cin >> code >> description >> price >> discountRate;
			list.emplace_back(code, description, price, discountRate); r
		}*/
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
	/*  -- Error
	for (auto it = list.begin(); it != list.end(); ++it) {
		if (it->HasCode(code)) {
			i.erase(it);
			cout << "Item removed.\n";
			return;
		}
	}*/
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
// exit menu
void DoQuit(void)
{
	cout << "Exit. Goodbye!" << endl;
}

void DoAddUser(void)
{
	string name, password;
	char type;

	cout << "Enter new user name: ";
	cin >> name;
	cout << "Enter new user password: ";
	cin >> password;
	cout << "Enter user type (M/A): ";
	cin >> type;

	CUser newUser(name, password, type);

	for (int i = 0; i < 25; i++)
	{
		if (users[i].GetUserName() == "")
		{
			users[i] = newUser;
			cout << "User added!" << endl;
			return;
		}
	}

	cout << "User list is full" << endl;
}

void DoEditUser(void)
{
	string name, newPassword;
	cout << "Enter the username to edit: ";
	cin >> name;

	for (int i = 0; i < 25; i++)
	{
		if (users[i].GetUserName() == name)
		{
			cout << "Enter new password: ";
			cin >> newPassword;
			users[i] = CUser(name, newPassword, users[i].GetType());
			cout << "Password updated!" << endl;
			return;
		}
	}

	cout << "User not found." << endl;
}




