#include"stdafx.h"
long int User::temp = 1;

ostream & operator<<(ostream &out, const User &usr)
{
	out << "User ID:" << usr.id << endl;
	out << "User Name is:" << usr.firstname << " " << usr.lastname << endl;
	out << "Experience:" << usr.experience << " Years" << endl;
	out << "Gender:" << usr.gender << endl;
	out << "skills:" << endl; 
	for (auto itr : usr.skills)
	{
		cout << itr << endl;
	}
	cout << endl;

	return out;

}
bool User::operator<(const User& usr) const
{
	return (this->id < usr.id);
}

User& User::CreateUser()
{
	id = temp++;
	cout << "Enter First Name:" << endl;
	cin >> firstname;
	cout << "Enter Last Name:" << endl;
	cin >> lastname;
	fullname = firstname + " " + lastname;
	cout << "Enter Experience in Years" << endl;
	cin >> experience;
	cout << "Enter your skills seperated with ',' in between each skill:" << endl;
	string line;
	cin >> line;
	
	stringstream ss(line);
	string skill;
	while (getline(ss,skill,','))
	{
		skills.insert(skill);
	}
	connections = {};
	cout << "Enter your gender: Male/Female:" << endl;
	cin >> gender;

	return *this;
}
void User::ShowMyConnections()
{
	for (auto itr : connections)
	{
		cout << itr - id << ":";
		cout << itr->fullname << endl;
		
	}
}