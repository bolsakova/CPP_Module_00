#include <iostream>
#include <cstring>
#include <cctype>

int main(int ac, char *av[]) {
	if (ac != 2) {
		return 1;
	}
	// std::strlen(av[1]);
	for (int i = 0; i < std::strlen(av[1]); i++) {
		if (std::islower(av[1][i])) {
			av[1][i] = std::toupper(av[1][i]);
		}
		std::cout << av[1][i];
	}
	std::cout << std::endl;
	return 0;
}
