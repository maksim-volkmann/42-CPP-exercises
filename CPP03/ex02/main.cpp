/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvolkman <mvolkman@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 09:54:30 by mvolkman          #+#    #+#             */
/*   Updated: 2024/09/11 10:32:21 by mvolkman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main() {
	ClapTrap arnold("Arnold");
	ScavTrap olivia("Olivia");
	FragTrap danial("Danial");

	danial.highFivesGuys();

	std::cout << "-----------------------------" << std::endl;

	arnold.attack("target");
	olivia.attack("target");
	danial.attack("target");

	std::cout << "-----------------------------" << std::endl;

	arnold.takeDamage(100);
	olivia.takeDamage(3);
	danial.takeDamage(30);

	std::cout << "-----------------------------" << std::endl;

	olivia.beRepaired(2);
	danial.beRepaired(40);

	std::cout << "-----------------------------" << std::endl;

	FragTrap oliviaFrag("OliviaFrag");
	oliviaFrag = danial;
	oliviaFrag.attack("target");
	danial.highFivesGuys();

	std::cout << "-----------------------------" << std::endl;

	return 0;
}
