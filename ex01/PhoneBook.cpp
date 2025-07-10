#include "PhoneBook.hpp"

void Phonebook::addContact(Contact newContact) {
	
	if (count < 8) {
		contacts[count] = newContact;
		count++;
	}
	else if (count == 8) {
		contacts[oldest] = newContact;
		oldest++;
		if (oldest == 8)
			oldest = 0;
	}
	std::cout << std::endl;
}

void Phonebook::showContactsList() {
	std::cout << std::endl;
	if (count == 0)
		std::cout << "Phonebook is empty :(" << std::endl;
	else {
		for (int i = 0; i < count; i++) {
			std::string formattedFirstName = formatField(contacts[i].getFirstName());
			std::string formattedLastName = formatField(contacts[i].getLastName());
			std::string formattedNickname = formatField(contacts[i].getNickname());
			std::cout << std::setw(10) << i + 1 << "|" << formattedFirstName << "|" << formattedLastName << "|" << formattedNickname << std::endl;
		}
		std::cout << std::endl;
	}
}

std::string Phonebook::formatField(std::string field) {
	std::string formattedField;
	if (field.length() > 10) {
		formattedField = field.substr(0, 9) + ".";
		return formattedField;
	}
	else if (field.length() <= 10) {
		int spaceNum = 10 - field.length();
		std::string spacesStr(spaceNum, ' ');
		formattedField = spacesStr + field;
		return formattedField;
	}
	return 0;
}

void Phonebook::showContactDetails(int index) {
	std::cout << std::endl;
	if (index >= 1 && index <= count) {
		std::cout << "First name: " << contacts[index - 1].getFirstName() << std::endl;
		std::cout << "Last name: " << contacts[index - 1].getLastName() << std::endl;
		std::cout << "Nickname: " << contacts[index - 1].getNickname() << std::endl;
		std::cout << "Phone: " << contacts[index - 1].getPhone() << std::endl;
		std::cout << "Darkest secret: " << contacts[index - 1].getDarkestSecret() << std::endl;
	}
	else
		std::cout << "No such index :(" << std::endl;
	std::cout << std::endl;
}

int Phonebook::getCount() const {
	return count;
}
