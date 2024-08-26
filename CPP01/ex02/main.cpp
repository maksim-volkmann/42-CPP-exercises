/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvolkman <mvolkman@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 17:35:27 by mvolkman          #+#    #+#             */
/*   Updated: 2024/08/26 18:24:15 by mvolkman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main() {
	std::string brainString = "HI THIS IS BRAIN";
	std::string* stringPTR = &brainString;
	std::string& stringREF = brainString;

	std::cout << "The memory address of brainString:     " << &brainString << std::endl;
	std::cout << "The memory address held by stringPTR:  " << stringPTR << std::endl;
	std::cout << "The memory address held by stringREF:  " << &stringREF << std::endl;

	std::cout << "The value of the brainString variable: " << brainString << std::endl;
	std::cout << "The value pointed to by stringPTR:     " << *stringPTR << std::endl;
	std::cout << "The value pointed to by stringREF:     " << stringREF << std::endl;

	return (0);
}
