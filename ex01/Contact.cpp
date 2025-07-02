#include "Contact.hpp"

void Contact::setFirstName(std::string newFirstName) {
	FirstName = newFirstName;
}
void Contact::setLastName(std::string newLastName) {
	LastName = newLastName;
}
void Contact::setNickname(std::string newNickname) {
	Nickname = newNickname;
}
void Contact::setPhone(std::string newPhone) {
	Phone = newPhone;
}
void Contact::setDarkestSecret(std::string newDarkestSecret) {
	DarkestSecret = newDarkestSecret;
}

std::string Contact::getFirstName() const {
	return FirstName;
}
std::string Contact::getLastName() const {
	return LastName;
}
std::string Contact::getNickname() const {
	return Nickname;
}
std::string Contact::getPhone() const {
	return Phone;
}
std::string Contact::getDarkestSecret() const {
	return DarkestSecret;
}
