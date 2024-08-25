/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvolkman <mvolkman@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 14:45:20 by mvolkman          #+#    #+#             */
/*   Updated: 2024/08/25 22:50:01 by mvolkman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
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

	std::cout << "Contact successfully saved in the phonebook!" << std::endl;
}

std::string PhoneBook::formatText(const std::string& text) const { // Mark as const
	if(text.length() > 10)
		return text.substr(0, 9) + '.';
	else
		return text;
}

void PhoneBook::displayContacts() const {
	std::cout << std::endl;
	std::cout << "-------------------------------------------" << std::endl;
	std::cout << std::setw(10) << "INDEX" << "|";
	std::cout << std::setw(10) << "FIRST NAME" << "|";
	std::cout << std::setw(10) << "LAST NAME" << "|";
	std::cout << std::setw(10) << "NICKNAME" << std::endl;
	std::cout << "-------------------------------------------" << std::endl;

	for(int i = 0; i < 8; i++) {
		if(!(contactList[i].getFirstName().empty())) {
			std::cout << std::setw(10) << i + 1 << "|";
			std::cout << std::setw(10) << formatText(contactList[i].getFirstName()) << "|";
			std::cout << std::setw(10) << formatText(contactList[i].getLastName()) << "|";
			std::cout << std::setw(10) << formatText(contactList[i].getNickname()) << std::endl;
		}
	}
	std::cout << "-------------------------------------------" << std::endl;
	std::cout << std::endl;

	int index;
	std::cout << "Enter the index of the contact to display details (1-8): ";
	std::cin >> index;

	// Simple loop to check if the index is valid
	if (index >= 1 && index <= 8 && !contactList[index - 1].getFirstName().empty()) {
		contactList[index - 1].displayFullContactDetails();
	} else {
		std::cout << "Invalid index. Please enter a valid number between 1 and 8." << std::endl;
	}

	// std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	while (std::cin.get() != '\n');
}
