/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvolkman <mvolkman@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 09:54:30 by mvolkman          #+#    #+#             */
/*   Updated: 2024/09/10 16:36:13 by mvolkman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main() {
	ClapTrap arnold("Arnold");
	ScavTrap olivia("Olivia");

	std::cout << "-----------------------------" << std::endl;

	arnold.attack("target");
	olivia.attack("target");

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
		olivia.attack("target1");
	}

	std::cout << "-----------------------------" << std::endl;

	olivia.attack("target1");
	olivia.beRepaired(10);

	std::cout << "-----------------------------" << std::endl;

	ScavTrap morty("Morty");
	morty = olivia;
	morty.attack("target");

	std::cout << "-----------------------------" << std::endl;

	return 0;
}
