// Single-line comment
/*
 * Multiple line comment
 */

#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>

#include <algorithm>

using namespace std;

enum class Group : int {Friends, Family, Coworker, Acquaintance};

class Contact
{
	string first_name;
	string last_name;
	string phone_primary;
	string phone_secondary;
	string email;
	string address;
	string company;
	Group group;
public:
	Contact(
		string first_name, 
		string last_name, 
		string phone_primary, 
		string phone_secondary, 
		string email, 
		string address, 
		string company, 
		Group group):
			first_name{first_name}, 
			last_name{last_name}, 
			phone_primary{phone_primary}, 
			phone_secondary{phone_secondary}, 
			email{email}, 
			address{address}, 
			company{company}, 
			group{group}
	{
	}

	string get_first_name() const
	{
		return this->first_name;
	}
	string get_last_name() const
	{
		return this->last_name;
	}
	string get_phone_primary() const
	{
		return this->phone_primary;
	}
	string get_phone_secondary() const
	{
		return this->phone_secondary;
	}
	string get_email() const
	{
		return this->email;
	}
	string get_address() const
	{
		return this->address;
	}
	string get_company() const
	{
		return this->company;
	}
	Group get_group() const
	{
		return this->group;
	}
};

std::ostream & operator << (std::ostream &out, const Group &group)
{
	switch(static_cast<int>(group))
	{
		case static_cast<int>(Group::Friends):
			cout << "Friends";
			break;
		case static_cast<int>(Group::Family):
			cout << "Family";
			break;
		case static_cast<int>(Group::Coworker):
			cout << "Coworker";
			break;
		case static_cast<int>(Group::Acquaintance):
			cout << "Acquaintance";
			break;
	}

	return out;
}

void _print(const Contact &contact)
{
	cout << contact.get_first_name() << endl;
	cout << contact.get_last_name() << endl;
	cout << contact.get_phone_primary() << endl;
	cout << contact.get_phone_secondary() << endl;
	cout << contact.get_email() << endl;
	cout << contact.get_address() << endl;
	cout << contact.get_company() << endl;
	cout << contact.get_group() << endl;
	cout << "----------------------------------------" << endl;
}

void _print(vector<Contact> contacts)
{
	std::for_each(contacts.begin(), contacts.end(),
		[](const Contact &contact)
		{
			_print(contact);
		});
}

vector<Contact> contacts =
{
	Contact{"Rostyslav", 
		"Nikitin", 
		"+380675617956", 
		"+38073xxxxxxxx", 
		"rostislav.nikitin@gmail.com", 
		"Vol.Vern st.1/81", 
		"Dealer-Fx", 
		Group::Coworker},
	Contact{"Valvemar", 
		"Afonasiev", 
		"", 
		"+38076xxxxxxxx", 
		"valdemar.afonasiev@gmail.com", 
		"Sichevih Streltsiv st.11/67", 
		"Other Co", 
		Group::Acquaintance},
	Contact{"Dmitry", 
		"Petrov", 
		"+3802349056", 
		"+38084xxxxxxxx", 
		"dmitry.petrov@gmail.com", 
		"Peremogy st. 12/64", 
		"Dealer-Fx", 
		Group::Coworker}
};


void _sort_by_first_name_asc()
{
	std::sort(contacts.begin(), contacts.end(), [](const Contact &c1, const Contact &c2)
		{
			return c1.get_first_name() < c2.get_first_name();
		});
}

void _sort_by_last_name_asc()
{
	std::sort(contacts.begin(), contacts.end(), [](const Contact &c1, const Contact &c2)
		{
			return c1.get_last_name() < c2.get_last_name();
		});
}

void _filter_out_by_empty_primary_phone_number()
{
	std::for_each(contacts.begin(), contacts.end(), [](const Contact &contact)
		{
			if(contact.get_phone_primary() != "")
			{
				_print(contact);
			}
		});
}

void _group_by_group_type()
{
	multimap<Group, Contact> contacts_map {};
	for(const Contact &c : contacts)
		contacts_map.insert({c.get_group(), c});

	for_each(contacts_map.begin(), contacts_map.end(), [](const pair<Group, Contact> &p)
		{
			_print(p.second);
		});
	
}

void _search_by_first_name(const string &first_name)
{
	
	unordered_multimap<string, Contact> contacts_map {};
	for(const auto &c : contacts)
	{
		contacts_map.insert(pair<string, Contact>(c.get_first_name(), c));
	}

	//auto itr = contacts_map.find(first_name);
	auto itr_pair = contacts_map.equal_range(first_name);
	while(itr_pair.first != itr_pair.second)
	{
		_print(itr_pair.first->second);
		++itr_pair.first;
	}
}

void _search_by_last_name(const string &last_name)
{
	
	unordered_multimap<string, Contact> contacts_map {};
	for(const auto &c : contacts)
	{
		contacts_map.insert(pair<string, Contact>(c.get_last_name(), c));
	}

	auto itr_pair = contacts_map.equal_range(last_name);
	while(itr_pair.first != itr_pair.second)
	{
		_print(itr_pair.first->second);
		++itr_pair.first;
	}
}

void _count_by_company()
{
	set<string> companies;
	multimap<string, Contact> contacts_map;

	for(const auto &c : contacts)
	{
		companies.insert(c.get_company());
		contacts_map.insert({c.get_company(), c});
	}

	for(const auto &company : companies)
		cout << "Count [by company] " << company << "  : " << contacts_map.count(company) << endl;
	cout << "----------------------------------------" << endl;
}

void _count_by_group()
{
	set<Group> groups;
	multimap<Group, Contact> contacts_map;

	for(const auto &c : contacts)
	{
		groups.insert(c.get_group());
		contacts_map.insert({c.get_group(), c});
	}

	for(const auto &group: groups)
		cout << "Count [by group] " << group << "  : " << contacts_map.count(group) << endl;

	cout << "----------------------------------------" << endl;
}

void _count_by_company_and_group()
{
	_count_by_company();
	_count_by_group();
}

const int CHOISE_EXIT = 0;

int _menu_choise()
{
	cout << "1. Show contacts [sorted by first name]" << endl;
	cout << "2. Show contacts [sorted by last name]" << endl;
	cout << "3. Show only first name with primary phone number" << endl;
	cout << "4. Display contacts based on group type" << endl;
	cout << "5. Search contact [by first name]" << endl;
	cout << "6. Search contact [by last name]" << endl;
	cout << "7. Display contacts count by company and group" << endl;
	cout << CHOISE_EXIT << ". Exit" << endl;

	cout << "Enter menu item number: ";

	int choise;
	cin >> choise;

	cout << endl;

	return choise;

}

void _menu()
{

	string name {};
	int choise {};
	do
	{
		choise = _menu_choise();

		switch(choise)
		{
			case 1:
				_sort_by_first_name_asc();
				_print(contacts);
				break;
			case 2:
				_sort_by_last_name_asc();
				_print(contacts);
				break;
			case 3:
				_filter_out_by_empty_primary_phone_number();
				break;
			case 4:
				_group_by_group_type();
				break;
			case 5:
				cout << "Entrt first name: ";
				cin >> name;
				_search_by_first_name(name);
				break;
			case 6:
				cout << "Entrt last name: ";
				cin >> name;
				_search_by_last_name(name);
				break;
			case 7:
				_count_by_company_and_group();
				break;
		}
	}
	while(choise != CHOISE_EXIT);	
}

int main()
{
	_menu();
	//_print(contacts);
	return 0;
}
