/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvolkman <mvolkman@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 10:47:26 by mvolkman          #+#    #+#             */
/*   Updated: 2024/08/26 17:28:46 by mvolkman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main() {
	int N = 3;
	std::string name = "Horde Zombie";

	Zombie* hordeArr = zombieHorde(N, name);

	for(int i = 0; i < N; i++) {
		hordeArr[i].announce();
	}

	delete[] hordeArr;

	return (0);
}
