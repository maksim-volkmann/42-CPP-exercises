/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvolkman <mvolkman@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 09:54:30 by mvolkman          #+#    #+#             */
/*   Updated: 2024/09/10 22:30:30 by mvolkman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main() {
    // Testing basic functionality
    ClapTrap arnold("Arnold");
    ScavTrap olivia("Olivia");
    FragTrap danial("Danial");

    // Test high fives special ability
    danial.highFivesGuys();

    std::cout << "-----------------------------" << std::endl;

    // Testing attack functionality
    olivia.attack("target");
    danial.attack("target");
    
    std::cout << "-----------------------------" << std::endl;

    // Testing takeDamage and beRepaired functionality
    olivia.takeDamage(3);
    danial.takeDamage(30);
    
    std::cout << "-----------------------------" << std::endl;

    olivia.beRepaired(2);
    danial.beRepaired(40);

    std::cout << "-----------------------------" << std::endl;

    // Testing copy constructor
    FragTrap danialCopy(danial);
    danialCopy.attack("target");

    std::cout << "-----------------------------" << std::endl;

    // Testing assignment operator
    FragTrap oliviaFrag("OliviaFrag");
    oliviaFrag = danial;
    oliviaFrag.attack("third target dummy");

    std::cout << "-----------------------------" << std::endl;

    return 0;
}