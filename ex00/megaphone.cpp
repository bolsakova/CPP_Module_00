#include <iostream>
#include <string>
// #include <cstring>
// #include <cctype>

// int main(int ac, char *av[]) {
// 	if (ac != 2) {
// 		return 1;
// 	}
// 	auto str = std::string(av[1]);
// 	for (auto& symbol : str) {
// 		if (std::islower(symbol)) {
// 			symbol = std::toupper(symbol);
// 		}
// 		std::cout << symbol;
// 	}
// 	std::cout << std::endl;
// 	return 0;
// }

int main(int ac, char *av[]) {
	if (ac != 2)
		return 1;
	std::string str = av[1];
	for (size_t i = 0; i < str.length(); i++) {
		if (std::islower(str[i]))
			str[i] = std::toupper(str[i]);
		std::cout << str[i];
	}
	std::cout << std::endl;
	return 0;
}
