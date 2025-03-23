//ProjectItem.cpp - main program
#include "CProjectItem.h"
#include <iostream>
#include <iomanip>
#include <fstream>

CItem list[5];
int numItems = 0;
int code;

void DoDisplayFullPriceList(void);
void DoDisplayItem(void);
void DoTotalInvoice(void);

int main()
{
    //todo:DRG:option.1 DoInitializePriceList
    //option.2 DoDisplayFullPriceList
    //option.3 DoAddItemToList
    //option.4 DoSetItemPrice
    //option.5 DoSetItemDiscountRate
    //option.6 DoDisplayItem
    //option.7 DoOrderCost
    //todo:MS:option.8 DoTotalInvoice
    //option.9 DoRemoveItemFromList
}

void DoDisplayFullPriceList(void)
{
    for (int i = 0; i < 5; i++)
    {
        cout << "Item " << list[i].GetCode() << " is a " << list[i].GetDescription()<<" and costs €"<<list[i].GetPrice()<<" before discount is applied";
    }
}

void DoDisplayItem(void)
{
    for (int i = 0; i < 4; i++)
    {
        cout << "Please enter item code for details: ";
        cin >> code;
        if (code != list[i].GetCode())
            cout << "Invalid item code entered";
        else if (code == list[i].GetCode())
            
    }
}

void DoTotalInvoice(void)
{

}
