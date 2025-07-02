#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

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
