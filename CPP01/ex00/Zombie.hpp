/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvolkman <mvolkman@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 10:00:24 by mvolkman          #+#    #+#             */
/*   Updated: 2024/09/03 09:44:08 by mvolkman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

class Zombie {
private:
	std::string name;

public:
	Zombie(std::string zombieName);
	void announce(void);
	~Zombie();
};

Zombie* newZombie(std::string name);
void randomChump(std::string name);

#endif
