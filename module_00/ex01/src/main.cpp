#include <iostream>
#include <array>
#include <iomanip>

#define CAPACITY 8

// class Prompt
// {
// 	private:
// 		std::string	content {};

// 	public:
// 		void get(std::string msg)
// 		{
// 			std::cout << msg;
// 			std::getline(std::cin >> std::ws, content);
// 		}

// 		std::string getContent() { return content; }
// };

// struct ContactDetails
// {
// 	std::string first_name {};
// 	std::string last_name {};
// 	std::string nickname {};
// 	std::string contact_num {};
// 	std::string secret {};
// };

std::string prompt(std::string_view msg)
{
	std::cout << msg;
	std::string prompt;
	std::getline(std::cin >> std::ws, prompt);
	return prompt;
}

class Contact
{
private:
	std::string m_first_name{};
	std::string m_last_name{};
	std::string m_nickname{};
	std::string m_contact_num{};
	std::string m_secret{};

public:
	void create()
	{
		m_first_name = prompt("enter first name: ");
		m_last_name = prompt("enter last name: ");
		m_nickname = prompt("enter nickname: ");
		m_contact_num = prompt("enter phone number: ");
		m_secret = prompt("enter darkest secret: ");
	}

	std::string getFirstName() { return m_first_name; }
	std::string getLastName() { return m_last_name; }
	std::string getNickname() { return m_nickname; }
	std::string getContactNum() { return m_contact_num; }
	std::string getSecret() { return m_secret; }
};

void printPhonebookHeader()
{
	int index{1};
	constexpr int column_count{4};
	std::array<std::string, column_count> column_name
		{"index", "first name", "last name", "nickname"};

	for (std::string name: column_name)
	{
		std::cout << std::setw(10) << name;
		std::cout << ((index < column_count) ? " | " : "\n");
		index++;
	}
	index = 1;
	for (std::string name: column_name)
	{
		std::cout << "----------";
		std:: cout << ((index < column_count) ? "-+-" : "\n");
		index++;
	}
}

void printPhonebookfooter()
{
	constexpr int column_count{4};
	constexpr int column_width{10};
	constexpr int separator_width{3};
	constexpr int total_width{column_count * column_width
		+ (column_count - 1) * separator_width};
	for (int i = 0; i < total_width; i++)
		std::cout << "-";
	std::cout << std::endl;
}

class PhoneBook
{
private:
	int m_last_contact_idx{0};
	std::array<Contact, CAPACITY> m_contacts{};

public:
	void add(Contact contact)
	{
		m_contacts[m_last_contact_idx] = contact;
		m_last_contact_idx = (m_last_contact_idx + 1) % CAPACITY;
	}

	void displayContacts()
	{
		int i{0};
		printPhonebookHeader();
		for (Contact contact : m_contacts)
		{
			if (contact.getFirstName() != "")
			{
				std::cout << std::setw(10) << i << " | ";
				std::cout << std::setw(10) << contact.getFirstName() << " | ";
				std::cout << std::setw(10) << contact.getLastName() << " | ";
				std::cout << std::setw(10) << contact.getNickname() << std::endl;
				i++;
			}
		}
		printPhonebookfooter();
	}

	// Contact search(int i)
	// {
	// }

	void printContacts()
	{
		for (Contact contact : m_contacts)
		{
			if (contact.getFirstName() != "")
			{
				std::cout << "first name: " << contact.getFirstName() << '\n';
				std::cout << "last name: " << contact.getLastName() << '\n';
				std::cout << "nickname: " << contact.getNickname() << '\n';
				std::cout << "phone number: " << contact.getContactNum() << '\n';
				std::cout << "darkest secret :" << contact.getSecret() << '\n';
			}
		}
	}
};

void display_available_commands()
{
	std::cout << "Available commands:" << std::endl;
	std::cout << "- ADD to add a new contact\n";
	std::cout << "- SEARCH to look up a contact\n";
	std::cout << "- EXIT to close the program\n";
}

// ContactDetails getContactDetails()
// {
// 	ContactDetails contact;
// 	contact.first_name = prompt("first name: ");
// 	contact.last_name = prompt("last name: ");
// 	contact.nickname = prompt("nickname: ");
// 	contact.contact_num = prompt("phone number: ");
// 	contact.secret = prompt("darkest secret: ");
// 	return contact;
// }

int main()
{
	std::string command;
	PhoneBook phonebook{};

	display_available_commands();
	while (command != "EXIT")
	{
		command = prompt("> ");
		if (command == "ADD")
		{
			Contact contact{};
			contact.create();
			phonebook.add(contact);
			// phonebook.printContacts();
		}
		else if (command == "SEARCH")
		{
			phonebook.displayContacts();
			// phonebook.search();
		}
		else if (command != "EXIT")
		{
			std::cout << "Illegal command: "
					  << "'" << command << "'\n";
			display_available_commands();
		}
	}
	return (EXIT_SUCCESS);
}