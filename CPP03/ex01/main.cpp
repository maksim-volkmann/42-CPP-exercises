/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvolkman <mvolkman@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 09:54:30 by mvolkman          #+#    #+#             */
/*   Updated: 2024/09/06 15:13:53 by mvolkman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main() {
	ClapTrap clap("Clappy");
	ScavTrap scav("Scavvy");

	std::cout << "-----------------------------" << std::endl;

	clap.attack("target1");
	scav.attack("target2");

	std::cout << "-----------------------------" << std::endl;

	clap.takeDamage(3);
	scav.takeDamage(10);

	std::cout << "-----------------------------" << std::endl;

	clap.beRepaired(5);
	scav.beRepaired(20);

	std::cout << "-----------------------------" << std::endl;

	scav.guardGate();

	std::cout << "-----------------------------" << std::endl;

	// Test energy
	for (int i = 0; i < 50; ++i) {
		scav.attack("target");
	}

	std::cout << "-----------------------------" << std::endl;

	scav.attack("target3");
	scav.beRepaired(10);

	std::cout << "-----------------------------" << std::endl;

	// Test copying and assignment
	ScavTrap scavCopy(scav);  // Copy constructor
	ScavTrap scavAssign("AnotherScav");
	scavAssign = scav;  // Copy assignment

	std::cout << "-----------------------------" << std::endl;

	return 0;
}
