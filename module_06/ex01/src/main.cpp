#include "Data.hpp"
#include "Serializer.hpp"
#include <iostream>
#include <cstdlib>

int main(void)
{
	Data data = {.first_name = "Peter",
				 .last_name = "Molnar",
				 .email_address = "peter_molnar@email.com",
				 .phone_number = "01-234-5678"};

	std::cout << "Data dump pre serialization:\n";
	std::cout << "first_name = " << data.first_name << '\n';
	std::cout << "last_name = " << data.last_name << '\n';
	std::cout << "email_address = " << data.email_address << '\n';
	std::cout << "phone_number = " << data.phone_number << '\n';
	std::cout << "\n";

	uintptr_t serialized_data = Serializer::serialize(&data);
	Data *data_ptr = Serializer::deserialize(serialized_data);

	std::cout << "Data dump post serialization:\n";
	std::cout << "first_name = " << data_ptr->first_name << '\n';
	std::cout << "last_name = " << data_ptr->last_name << '\n';
	std::cout << "email_address = " << data_ptr->email_address << '\n';
	std::cout << "phone_number = " << data_ptr->phone_number << '\n';
	std::cout << "\n";

	std::cout << "address of data " << &data << '\n';
	std::cout << "value of data_ptr " << data_ptr << '\n';
	std::cout << "the original and deserialised address are ";

	if (&data == data_ptr)
		std::cout << "the same\n";
	else
		std::cout << "not the same\n";
	return EXIT_SUCCESS;
}
