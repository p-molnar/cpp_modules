#include <iostream>
#include <array>

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

struct ContactDetails
{
	std::string first_name {};
	std::string last_name {};
	std::string nickname {};
	std::string contact_num {};
	std::string secret {};
};

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
		std::string	m_first_name {};
		std::string	m_last_name {};
		std::string	m_nickname {};
		std::string m_contact_num {};
		std::string	m_secret {};

	public:
		Contact(ContactDetails detail)
			: m_first_name{ detail.first_name }
			, m_last_name{ detail.last_name }
			, m_nickname{ detail.nickname }
			, m_contact_num{ detail.contact_num }
			, m_secret{ detail.secret }
		{
		}

		std::string getFirstName() { return m_first_name; }
		std::string getLastName() { return  m_last_name; }
		std::string getNickname() { return m_nickname; }
		std::string getContactNum() { return m_contact_num; }
		std::string getSecret() { return m_secret; }
};

class PhoneBook
{
	private:
		int m_last_contact_idx {0};
		std::array<Contact, CAPACITY> m_contacts;
	
	public:
		void add(Contact contact)
		{
			m_contacts[m_last_contact_idx] = contact;
			m_last_contact_idx = (m_last_contact_idx + 1) % CAPACITY;
		}
	
		void printContacts()
		{
			for (Contact contact : m_contacts)
			{
				std::cout << contact.getFirstName() << '\n';
				std::cout << contact.getLastName() << '\n';
				std::cout << contact.getNickname() << '\n';
				std::cout << contact.getContactNum() << '\n';
				std::cout << contact.getSecret() << '\n';
			}
		}
};

void display_available_commands()
{
	std::cout << "Available commands:" << std::endl;
	std::cout << "ADD to add a new contact\n";
	std::cout << "SEARCH to look up a contact\n";
	std::cout << "EXIT to close the program\n";
}

ContactDetails getContactDetails()
{
	ContactDetails contact;
	contact.first_name = prompt("first name: ");
	contact.last_name = prompt("last name: ");
	contact.nickname = prompt("nickname: ");
	contact.contact_num = prompt("phone number: ");
	contact.secret = prompt("darkest secret: ");
	return contact;
}

int main()
{
	std::string command;
	PhoneBook phonebook {};

	display_available_commands();
	while (command != "EXIT")
	{
		command = prompt("> ");
		if (command == "ADD")
		{
			ContactDetails details {getContactDetails()};
			Contact contact {details};
			phonebook.add(contact);
		}
		else if (command == "SEARCH")
		{
			std::cout << "search"; 
		}
		else if (command != "EXIT")
		{
			std::cout << "Illegal command: " << "'" << command << "'\n";
			display_available_commands();
		}
	}
	return (EXIT_SUCCESS);
}