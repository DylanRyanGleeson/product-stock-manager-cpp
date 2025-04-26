#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;
class CUser
{
private:
	string m_userName;
	string m_password;
	char m_type;
public:
	//constructors
	CUser(void);
	CUser(string m_userName, string m_password);
	CUser(string m_userName, string m_password, char m_type);
	// getters
	string GetUserName();
	string GetPassword();
	char GetType();

	bool Match(string userName, string password);

};

