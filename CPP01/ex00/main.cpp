/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvolkman <mvolkman@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 10:47:26 by mvolkman          #+#    #+#             */
/*   Updated: 2024/08/26 16:20:54 by mvolkman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main() {
	Zombie* heapZombie = newZombie("Arnold");
	heapZombie->announce();
	delete heapZombie;

	randomChump("Karoline");

	return (0);
}
