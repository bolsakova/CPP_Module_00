#include <iostream>
#include <cstring>
#include <cctype>

int main(int ac, char *av[]) {
	if (ac != 2) {
		return 1;
	}
	auto str = std::string(av[1]);
	for (auto& symbol : str) {
		if (std::islower(symbol)) {
			symbol = std::toupper(symbol);
		}
		std::cout << symbol;
	}
	std::cout << std::endl;
	return 0;
}
