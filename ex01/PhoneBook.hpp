#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <iomanip>
# include <string>

class Contact {
private:
	std::string FirstName;
	std::string LastName;
	std::string Nickname;
	std::string Phone;
	std::string DarkestSecret;

public:
	void setFirstName(std::string newFirstName);
	void setLastName(std::string newLastName);
	void setNickname(std::string newNickname);
	void setPhone(std::string newPhone);
	void setDarkestSecret(std::string newDarkestSecret);

	std::string getFirstName() const;
	std::string getLastName() const;
	std::string getNickname() const;
	std::string getPhone() const;
	std::string getDarkestSecret() const;
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
	int getCount() const;
};

#endif
