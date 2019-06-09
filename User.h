#pragma once
#include "stdafx.h"
#include<string>
class User
{
	static long int temp;
public:
	int id;
	std::string firstname;
	std::string lastname;
	std::string fullname;
	float experience;
	std::set<std::string> skills;
	std::set<User*> connections;
	std::string gender;

	User() = default;
	User& CreateUser();
	friend std::ostream & operator<<(std::ostream &out,const User &usr);
	bool operator<(const User& t) const;
	
	void ShowMyConnections();
};

class Engineers :public User
{
	//Who is engineer this is never explained.
};
