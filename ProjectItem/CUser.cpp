#include "CUser.h"

// constructors
CUser::CUser(void)
{
	m_userName = "";
	m_password = "";
	m_type = ' ';
}
CUser::CUser(string userName, string password)
{
	m_userName = userName;
	m_password = password;
	m_type = ' ';
}
CUser::CUser(string userName, string password, char type)
{
	m_userName = userName;
	m_password = password;
	m_type = type;
}

// Getters
string CUser::GetUserName()
{
	return m_userName;
}

string CUser::GetPassword()
{
	return m_password;
}

char CUser::GetType()
{
	return m_type;
}

// Match function
bool CUser::Match(string userName, string password)
{
	return (m_userName == userName && m_password == password);
}
