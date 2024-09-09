/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvolkman <mvolkman@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 09:54:30 by mvolkman          #+#    #+#             */
/*   Updated: 2024/09/07 10:14:54 by mvolkman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main() {
	ClapTrap arnold("Arnold");
	ScavTrap olivia("Olivia");

	std::cout << "-----------------------------" << std::endl;

	arnold.attack("target1");
	olivia.attack("target2");

	std::cout << "-----------------------------" << std::endl;

	arnold.takeDamage(3);
	olivia.takeDamage(10);

	std::cout << "-----------------------------" << std::endl;

	arnold.beRepaired(5);
	olivia.beRepaired(20);

	std::cout << "-----------------------------" << std::endl;

	olivia.guardGate();

	std::cout << "-----------------------------" << std::endl;

	// Test energy
	for (int i = 0; i < 50; ++i) {
		olivia.attack("target");
	}

	std::cout << "-----------------------------" << std::endl;

	olivia.attack("target3");
	olivia.beRepaired(10);

	std::cout << "-----------------------------" << std::endl;

	// Test copying and assignment
	ScavTrap danial(olivia);  // Copy constructor
	ScavTrap morty("Morty");
	morty = olivia;  // Copy assignment

	std::cout << "-----------------------------" << std::endl;

	return 0;
}
