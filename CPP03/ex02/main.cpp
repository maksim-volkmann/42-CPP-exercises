/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvolkman <mvolkman@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 09:54:30 by mvolkman          #+#    #+#             */
/*   Updated: 2024/09/07 11:53:37 by mvolkman         ###   ########.fr       */
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

	return 0;
}
