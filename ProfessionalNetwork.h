#pragma once
#include "stdafx.h"

class ProfessionalNetwork
{
public:
	void addUser(User usr);
	void deleteUser(int id);
	void DisplayUsers();
	void GetUsersByName(std::string name);
	void FindUsersByMinExperience(int exp);
	void GetUserBySkills(std::set<std::string> skills);
	void GetUserConnections(User usr);
	ProfessionalNetwork() = default;
private:
	
	std::map<int, User> m_users;
};
