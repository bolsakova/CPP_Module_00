#include "PhoneBook.hpp"

const char* prompts[5] = {
	"Enter first name: ",
	"Enter last name: ",
	"Enter nickname: ",
	"Enter phone: ",
	"Enter the darkest secret: "
};

int main() {
	Phonebook phonebook;
	while (1) {
		std::cout << "Enter the command you would like to use :)" << std::endl;
		std::string command;
		std::getline(std::cin, command);
		if (std::cin.eof() || std::cin.fail())
			return 0;
		if (command == "ADD") {
			Contact contact;
			// создан массив с подсказками, чтобы программа их печатала поочередно
			// создан массив для хранения данных с класса Контакт (полей), так как к ним нельзя обратиться напрямую
			std::string field_data[5];
			for (int i = 0; i < 5; i++) {
				while (field_data[i] == "") {
					std::cout << prompts[i];
					std::getline(std::cin, field_data[i]);
					if (std::cin.eof() || std::cin.fail())
						return 0;
				}
			}
			contact.setFirstName(field_data[0]);
			contact.setLastName(field_data[1]);
			contact.setNickname(field_data[2]);
			contact.setPhone(field_data[3]);
			contact.setDarkestSecret(field_data[4]);
			phonebook.addContact(contact);
		}
		else if (command == "SEARCH") {
			phonebook.showContactsList();
			if (phonebook.getCount() != 0) {
				std::string index_str; // input is always with type string
				std::cout << "Enter index of chosen Contact: ";
				std::getline(std::cin, index_str);
				if (std::cin.eof() || std::cin.fail())
					return 0;
				// проверяем весь диапазон строки, состоит ли он из цифр
				if (!std::all_of(index_str.begin(), index_str.end(), ::isdigit)) {
					std::cout << std::endl << "No such index :(" << std::endl << std::endl;
					continue;
				}
				int index_num = std::stoi(index_str);
				phonebook.showContactDetails(index_num);
			}
		}
		else if (command == "EXIT")
			return 0;
	}
}
