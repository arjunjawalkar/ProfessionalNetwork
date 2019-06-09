// ProfessionalNetwork.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


void ProfessionalNetwork::addUser(User usr)
{
	m_users.emplace(usr.id, usr);
}
void ProfessionalNetwork::deleteUser(int id)
{
	auto itr = m_users.find(id);
	if (itr != m_users.end())
	{
		m_users.erase(itr);
	}
	/*
	To-Do
	Implement code to remove the user from all connections
	*/

}
void ProfessionalNetwork::DisplayUsers()
{
	for (auto itr : m_users)
		cout << itr.second;
}
void ProfessionalNetwork::GetUsersByName(string name)
{
	for (auto itr : m_users)
	{
		if (itr.second.fullname.find(name) != string::npos)
		{
			cout << itr.second << endl;
		}
	}
}

void ProfessionalNetwork::FindUsersByMinExperience(int exp)
{
	for (auto itr : m_users)
	{
		if (itr.second.experience >= exp)
		{
			cout << itr.second << endl;
		}
	}
}

void ProfessionalNetwork::GetUserBySkills(std::set<std::string> skills)
{
	set<User> my_set;//To Remove duplicates
	for (auto skill : skills)
	{
		for (auto itr : m_users)
		{

			auto skills_itr = itr.second.skills.find(skill);
			if (skills_itr != itr.second.skills.end())
			{
				my_set.insert(itr.second);
				//cout << itr.second << endl;
			}
		}
	}
	for (auto itr : my_set)
	{
		cout << itr << endl;
	}
}
void ProfessionalNetwork::GetUserConnections(User usr)
{
	for (auto itr : usr.connections)
	{
		cout << itr->id << "->";
		cout << itr->fullname << endl;
	}
}
int main()
{
	ProfessionalNetwork pn;
	while (1)
	{
		
		cout << "1. Add User";
		cout << "2. Remove User";
		cout << "3. Display Users";
		cout << "4. Search User by Name";
		cout << "5. Find Users with minimum experience";
		cout << "6. Find Users by skills";
		cout << "7. Get Connection of User";
		cout << "8. Exit";
		cout << "-----------------------------------" << endl;
		cout << "Select your operation:" << endl;
		int op;
		cin >> op;

		switch (op)
		{
			case 1:
			{
				User usr;
				//usr.CreateUser();
				pn.addUser(usr.CreateUser());
				break;
			}
			case 2:
			{
				pn.DisplayUsers();
				cout << "Enter id of the user who's profile needs to be deleted:" << endl;
				int id;
				cin >> id;
				pn.deleteUser(id);
				break;
			}
			case 3:
			{
				pn.DisplayUsers();
				break;
			}
			case 4:
			{
				string name;
				cout << "Enter name of the user:" << endl;
				cin >> name;
				pn.GetUsersByName(name);
				break;
			}
			case 5:
			{
				int val;
				cout << "Enter the minimum experience you  want to search for:" << endl;
				cin >> val;
				pn.FindUsersByMinExperience(val);
				break;
			}
			case 6:
			{
				string line;
				cout << "Enter skills to search seperated by ',':" << endl;
				cin >> line;
				stringstream ss(line);
				string skill;
				set<string> skills;
				while (getline(ss, skill, ','))
				{
					skills.insert(skill);
				}
				pn.GetUserBySkills(skills);

				break;
			}
			case 7:
			{
			
				break;
			}
			case 8:
			{
				exit(1);
			}
			default:
			{
				cout << "Wrong choise" << endl;
				break;
			}
			
		}
	}
    return 0;
}

