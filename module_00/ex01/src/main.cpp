#include <iostream>
#include <array>
#include <iomanip>

#include <utils.hpp>
#include <class_constants.hpp>

class Contact
{
private:
	std::string m_first_name{};
	std::string m_last_name{};
	std::string m_nickname{};
	std::string m_phone_num{};
	std::string m_secret{};
	bool m_is_created{false};

public:
	void create()
	{
		m_first_name = prompt("enter first name: ");
		m_last_name = prompt("enter last name: ");
		m_nickname = prompt("enter nickname: ");
		m_phone_num = prompt("enter phone number: ", &(isNumeric), "field can only contain numeric characters\n", true);
		m_secret = prompt("enter darkest secret: ");
		m_is_created = true;
	}

	void printDetails()
	{
		std::cout.width(10);
		std::cout << "first name: " << m_first_name << '\n';
		std::cout << "last name: " << m_last_name << '\n';
		std::cout << "nickname: " << m_nickname << '\n';
		std::cout << "phone number: " << m_phone_num << '\n';
		std::cout << "darkest secret: " << m_secret << '\n';
	}

	std::string getFirstName() { return m_first_name; }
	std::string getLastName() { return m_last_name; }
	std::string getNickname() { return m_nickname; }
	std::string getContactNum() { return m_phone_num; }
	std::string getSecret() { return m_secret; }
	bool isCreated() { return m_is_created; }
};

class PhoneBook
{
private:
	int m_last_contact_idx{0};
	std::array<Contact, CAPACITY> m_contacts{};

private:
	void printContactListHeader()
	{
		constexpr int column_count{4};
		std::array<std::string, column_count> column_name{"index",
														  "first name",
														  "last name",
														  "nickname"};

		for (std::string name : column_name)
			std::cout << std::setw(10) << name << " | ";
		std::cout << '\n';
		for (std::string name : column_name)
			std::cout << "----------"
					  << "-+-";
		std::cout << '\n';
	}

	void printContactListFooter()
	{
		constexpr int column_count{4};
		constexpr int column_width{10};
		constexpr int separator_width{3};
		constexpr int total_width{column_count *
								  (column_width + separator_width)};

		for (int i = 0; i < total_width; i++)
			std::cout << "-";
		std::cout << std::endl;
	}

public:
	void displayAvailableCommands()
	{
		std::cout << "Available commands:" << std::endl;
		std::cout << "- ADD to add a new contact\n";
		std::cout << "- SEARCH to look up a contact\n";
		std::cout << "- EXIT to close the program\n";
	}

	void add(Contact contact)
	{
		m_contacts[m_last_contact_idx] = contact;
		m_last_contact_idx = (m_last_contact_idx + 1) % CAPACITY;
	}

	void search(int i)
	{
		if (m_contacts[i].isCreated())
			m_contacts[i].printDetails();
		else
			std::cout << "contact at index '" << i << "' doesn't exist\n";
	}

	void displayContactList()
	{
		int i{0};
		constexpr int column_width{10};
		std::array<std::string, CONTACT_FIELDS_COUNT> field_value;
		printContactListHeader();
		for (Contact contact : m_contacts)
		{
			if (contact.isCreated())
			{
				field_value = {std::to_string(i),
							   contact.getFirstName(),
							   contact.getLastName(),
							   contact.getNickname()};
				for (std::string val : field_value)
					std::cout << std::setw(column_width)
							  << (val.length() > 10
									  ? stringSlice(val, 0, 9) + '.'
									  : val)
							  << " | ";
				std::cout << std::endl;
				i++;
			}
		}
		printContactListFooter();
	}
};

int main()
{
	std::string command{};
	PhoneBook phonebook{};
	int contact_index{};

	phonebook.displayAvailableCommands();
	while (command != "EXIT")
	{
		command = prompt();
		if (command == "ADD")
		{
			Contact contact{};
			contact.create();
			phonebook.add(contact);
		}
		else if (command == "SEARCH")
		{
			phonebook.displayContactList();
			contact_index = stoi(prompt("enter contact index: ",
										&(isInRange), "index out of range\n", true));
			phonebook.search(contact_index);
		}
		else if (command != "EXIT")
		{
			std::cout << "Illegal command: "
					  << "'" << command << "'\n";
			phonebook.displayAvailableCommands();
		}
	}
	return (EXIT_SUCCESS);
}