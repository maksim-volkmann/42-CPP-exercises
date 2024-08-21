/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvolkman <mvolkman@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 21:26:34 by mvolkman          #+#    #+#             */
/*   Updated: 2024/08/21 21:27:23 by mvolkman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "PhoneBook.hpp"

void PhoneBook::addContact(int index) {
	std::string firstName, lastName, nickname, phoneNumber, darkestSecret;

	do {
		std::cout << "Enter contact first name: ";
		std::getline(std::cin, firstName);
		if (firstName.empty()) {
			std::cout << "First name cannot be empty. Try again!" << std::endl;
		}
	} while (firstName.empty());

	do {
		std::cout << "Enter contact last name: ";
		std::getline(std::cin, lastName);
		if (lastName.empty()) {
			std::cout << "Last name cannot be empty. Try again!" << std::endl;
		}
	} while (lastName.empty());

	do {
		std::cout << "Enter contact nickname: ";
		std::getline(std::cin, nickname);
		if (nickname.empty()) {
			std::cout << "Nickname cannot be empty. Try again!" << std::endl;
		}
	} while (nickname.empty());

	do {
		std::cout << "Enter contact phone number: ";
		std::getline(std::cin, phoneNumber);
		if (phoneNumber.empty()) {
			std::cout << "Phone number cannot be empty. Try again!" << std::endl;
		}
	} while (phoneNumber.empty());

	do {
		std::cout << "Enter contact darkest secret: ";
		std::getline(std::cin, darkestSecret);
		if (darkestSecret.empty()) {
			std::cout << "Darkest secret cannot be empty. Try again!" << std::endl;
		}
	} while (darkestSecret.empty());

	contactList[index].createNewContact(firstName, lastName, nickname, phoneNumber, darkestSecret);

	std::cout << "Contact successfully added to the phonebook!" << std::endl;
}

void PhoneBook::displayFirstContactsName() const {
	std::cout << "First contact name: " << contactList[0].getFirstName() << std::endl;
}
