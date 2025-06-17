#include "PhoneBook.hpp"

class Contact {
private:
	std::string FirstName;
	std::string LastName;
	std::string Nickname;
	std::string Phone;
	std::string DarkestSecret;

public:
	void setFirstName(std::string newFirstName) {
		FirstName = newFirstName;
	}
	void setLastName(std::string newLastName) {
		LastName = newLastName;
	}
	void setNickname(std::string newNickname) {
		Nickname = newNickname;
	}
	void setPhone(std::string newPhone) {
		Phone = newPhone;
	}
	void setDarkestSecret(std::string newDarkestSecret) {
		DarkestSecret = newDarkestSecret;
	}

	std::string getFirstName() const {
		return FirstName;
	}
	std::string getLastName() const {
		return LastName;
	}
	std::string getNickname() const {
		return Nickname;
	}
	std::string getPhone() const {
		return Phone;
	}
	std::string getDarkestSecret() const {
		return DarkestSecret;
	}
};

class Phonebook {
private:
	Contact contacts[8];	// массив контактов - макс. 8
	int count = 0;				// переменная, к-рая отслеживает сколько контактов сохранено на данный момент
	int	oldest = 0;				// индекс самого старого контакта

public:
	void addContact(Contact newContact);		// добавить контакт
	void showContactsList();					// показать список
	void showContactDetails(int index);			// показать подробную информацию о контакте под индексом, который ввели
	std::string formatField(std::string field);	// форматирует строку, если строка больше или меньше 10 знаков
};

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
}

void Phonebook::showContactsList() {
	if (count == 0)
		std::cout << "Phonebook is empty :(";
	for (int i = 0; i < count; i++) {
		std::string formattedFirstName = formatField(contacts[i].getFirstName());
		std::string formattedLastName = formatField(contacts[i].getLastName());
		std::string formattedNickname = formatField(contacts[i].getNickname());
		std::cout << std::setw(10) << i + 1 << "|" << formattedFirstName << "|" << formattedLastName << "|" << formattedNickname << std::endl;
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
}

void Phonebook::showContactDetails(int index) {
	if (index >= 1 && index <= count) {
		std::cout << contacts[index - 1].getFirstName() << std::endl;
		std::cout << contacts[index - 1].getLastName() << std::endl;
		std::cout << contacts[index - 1].getNickname() << std::endl;
		std::cout << contacts[index - 1].getPhone() << std::endl;
		std::cout << contacts[index - 1].getDarkestSecret() << std::endl;
	}
	else
		std::cout << "No such index." << std::endl;
}

