/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvolkman <mvolkman@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 14:22:53 by mvolkman          #+#    #+#             */
/*   Updated: 2024/08/22 09:59:38 by mvolkman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
// #include <string>
#include "PhoneBook.hpp"

int	main()
{
	std::string input;
	PhoneBook phoneBook;
	int index = 0;

	while(true){
		std::cout << "PHONEBOOK commands: ADD, SEARCH, EXIT: ";
		// std::getline(std::cin, input); //TODO: what is cin exactly?
		if (!std::getline(std::cin, input)) {
			std::cout << "Exiting the program!" << std::endl;
		}
		if(input == "ADD") {
			phoneBook.addContact(index);
			index = (index + 1 ) % 8;
		}
		else if(input == "SEARCH") {
			phoneBook.displayContacts();
		}
		else if(input == "EXIT") {
			std::cout << "Exiting the program!" << std::endl;
			break;
		}
		else
			std::cout << "Invalid command, try again!" << std::endl;
	}


	return(0);
}
