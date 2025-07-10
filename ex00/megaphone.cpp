#include <iostream>
#include <string>

int main(int ac, char *av[]) {
	if (ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else {
		for (int j = 1; j < ac; j++) {
			std::string str = av[j];
			for (size_t i = 0; i < str.length(); i++) {
				if (std::islower(str[i]))
					str[i] = std::toupper(str[i]);
				std::cout << str[i];
			}
		}
	}
	std::cout << std::endl;
	return 0;
}
