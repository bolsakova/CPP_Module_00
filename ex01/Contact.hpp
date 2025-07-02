#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iomanip>
# include <iostream>
# include <string>
# include <algorithm>
# include <cctype>

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

#endif