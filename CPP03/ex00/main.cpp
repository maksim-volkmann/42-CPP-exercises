/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvolkman <mvolkman@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 09:54:30 by mvolkman          #+#    #+#             */
/*   Updated: 2024/09/11 11:55:12 by mvolkman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main() {
	ClapTrap a;
	ClapTrap arnold("Arnold");
	ClapTrap olivia("Olivia");
	ClapTrap danial("Danial");
	ClapTrap tom("Tom");

	std::cout << "-----------------------------" << std::endl;

	arnold.takeDamage(100);
	arnold.takeDamage(1);
	arnold.takeDamage(-100);
	arnold.beRepaired(5);

	std::cout << "-----------------------------" << std::endl;

	olivia.takeDamage(2);
	olivia.beRepaired(5);

	std::cout << "-----------------------------" << std::endl;

	danial.takeDamage(9);
	danial.beRepaired(20);

	std::cout << "-----------------------------" << std::endl;

	danial.beRepaired(5);
	danial.beRepaired(10);

	std::cout << "-----------------------------" << std::endl;

	tom.attack("target");
	tom.attack("target");
	tom.attack("target");
	tom.attack("target");
	tom.attack("target");
	tom.takeDamage(1);
	tom.beRepaired(1);
	tom.attack("target");
	tom.attack("target");
	tom.attack("target");
	tom.attack("target");
	tom.attack("target");
	tom.beRepaired(1);

	std::cout << "-----------------------------" << std::endl;

	return (0);
}






// #include "ClapTrap.hpp"

// int	main() {
// 	ClapTrap arnold("Arnold");

// 	std::cout << "-----------------------------" << std::endl;

// 	arnold.takeDamage(100);
// 	arnold.takeDamage(-1);

// 	return (0);
// }
