/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvolkman <mvolkman@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 11:09:22 by mvolkman          #+#    #+#             */
/*   Updated: 2024/09/06 12:49:22 by mvolkman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPPTRAP_HPP
#define CLAPPTRAP_HPP

#include <iostream>

class ClapTrap {
protected:
	std::string _name;
	int _hitPoints;
	int _energyPoints;
	int _attackDamage;

public:
	ClapTrap(const std::string& name);
	ClapTrap(const ClapTrap& other);
	ClapTrap& operator=(const ClapTrap& other);
	~ClapTrap();

	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

};

#endif
