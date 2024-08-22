/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvolkman <mvolkman@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 21:26:34 by mvolkman          #+#    #+#             */
/*   Updated: 2024/08/21 23:49:01 by mvolkman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "PhoneBook.hpp"
#include <iomanip>

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

void PhoneBook::displayContacts() const {
	std::cout << "Index | First Name | Last Name  | Nickname  " << std::endl;
	std::cout << "--------------------------------------------" << std::endl;

	for (int i = 0; i < 8; i++) {
		if (!contactList[i].getFirstName().empty()) {  // Check if a contact exists
			std::cout << std::setw(5) << i + 1 << " | "
						<< std::setw(10) << contactList[i].getFirstName() << " | "
						<< std::setw(10) << contactList[i].getLastName() << " | "
						<< std::setw(10) << contactList[i].getNickname() << std::endl;
		}
	}
	int index;
	std::cout << "Enter the index of the contact to view details: ";

	while (!(std::cin >> index) || index < 1 || index > 8 || contactList[index - 1].getFirstName().empty()) {
		if (std::cin.fail()) {  // Handle non-integer input
			std::cin.clear();   // Clear the error flag on cin
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Discard bad input
		}
		std::cout << "Invalid index. Please try again: ";
	}
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Discard remaining input
	contactList[index - 1].displayFullContactDetails();  // Display the full contact details
}