/**
C.ProjectItem.cpp - class implementation file
**/

#include "CProjectItem.h"

CItem::CItem(void) {
	m_Code = 0; m_Description = ""; m_Price = 0; m_DiscountRate = 0;
}

CItem::CItem(int code, string description) {
	m_Code = code; m_Description = description;
}

CItem::CItem(int code, string description, double price, double discountRate) {
	m_Code = code; m_Description = description; m_Price = price; m_DiscountRate = discountRate;
}

void CItem::SetPrice(double price) {
	m_Price = price;
}

void CItem::SetDiscountRate(double discountRate) {
	m_DiscountRate = discountRate;
}

int CItem::GetCode(void) {
	return m_Code;
}

string CItem::GetDescription(void) {
	return m_Description;
}

double CItem::GetPrice(void) {
	return m_Price;
}

double CItem::GetDiscountRate(void) {
	return m_DiscountRate;
}

bool CItem::HasCode(int searchCode) {
	if (m_Code == searchCode)
		return true;
	else
		return false;
}

void CItem::Display(void) {
	cout << "Item code: " << m_Code << endl;
	cout << "Item price: €" << m_Price << endl;
	cout << "Item description: " << m_Description << endl;
	cout << "Discount Rate: " << m_DiscountRate * 100 << "%" << endl;
}

double CItem::GetDiscount(void) {
	return m_Price * m_DiscountRate;
}