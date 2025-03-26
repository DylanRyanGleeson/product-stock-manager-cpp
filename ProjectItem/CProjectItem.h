//CProjectItem.h - class definition file
#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;

/// <summary>
/// A class to represent a Product 
/// </summary>
class CItem {
private:
	int m_Code;
	string m_Description;
	double m_Price;
	double m_DiscountRate;

public:
	CItem(void);
	//'new item constructor'
	CItem(int code, string description);
	/// <summary>
	/// 
	/// </summary>
	/// <param name="code"></param>
	/// <param name="description"></param>
	/// <param name="price"></param>
	/// <param name="discountRate"></param>

	//'database constructor'
	CItem(int code, string description, double price, double discountRate);
	/// <summary>
	/// Sets the price of the Product
	/// </summary>
	/// <param name="price"></param>
	void SetPrice(double price);
	void SetDiscountRate(double discountRate);
	int GetCode(void);
	string GetDescription(void);
	double GetPrice(void);
	double GetDiscountRate(void);
	bool HasCode(int searchCode);
	void Display(void);
	double GetDiscount(void);
};
