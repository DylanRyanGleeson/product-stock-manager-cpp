//ProjectItem.cpp - main program
#include "CProjectItem.h"
#include <iostream>
#include <iomanip>
#include <fstream>

constexpr int SIZE = 5;

CItem list[SIZE];

int numItems = 0;
int code;

void FillDummyData();

void DoDisplayFullPriceList(void);
void DoDisplayItem(void);
void DoTotalInvoice(void);

int main()
{
	FillDummyData();
	DoDisplayItem();
    //todo:LS:option.1 DoInitializePriceList
    //todo:DRG:option.2 DoDisplayFullPriceList
    //option.3 DoAddItemToList
    //todo:LS:option.4 DoSetItemPrice
    //option.5 DoSetItemDiscountRate
    //todo:DRG:option.6 DoDisplayItem
    //option.7 DoOrderCost
    //todo:DRG:option.8 DoTotalInvoice
    //option.9 DoRemoveItemFromList
}

void DoDisplayFullPriceList(void)
{
    for (int i = 0; i < SIZE; i++)
    {
        cout << "Item " << list[i].GetCode() << " is a " << list[i].GetDescription()<<" and costs €"<<list[i].GetPrice()<<" before discount is applied";
    }
}

void DoDisplayItem(void)
{
    for (int i = 0; i < SIZE; i++)
    {
        cout << "Please enter item code for details: ";
        cin >> code;
        if (code != list[i].GetCode())
            cout << "Invalid item code entered";
        else if (code == list[i].GetCode())
			list[i].Display();
            
    }
}

void DoTotalInvoice(void)
{

}

void FillDummyData(void)
{
    list[0] = CItem(1, "Item 1", 10.00, 0.10);
    list[1] = CItem(2, "Item 2", 20.00, 0.15);
    list[2] = CItem(3, "Item 3", 30.00, 0.20);
    list[3] = CItem(4, "Item 4", 40.00, 0.25);
    list[4] = CItem(5, "Item 5", 50.00, 0.30);
}
