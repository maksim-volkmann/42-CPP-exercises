/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvolkman <mvolkman@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 16:39:44 by mvolkman          #+#    #+#             */
/*   Updated: 2024/08/26 17:30:08 by mvolkman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name ) {
	Zombie* hordeArr = new Zombie[N];

	for(int i = 0; i < N; i++) {
		hordeArr[i].setZombieName(name);
	}

	return hordeArr;
}
