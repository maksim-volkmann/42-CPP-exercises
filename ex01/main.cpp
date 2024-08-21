/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvolkman <mvolkman@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 14:22:53 by mvolkman          #+#    #+#             */
/*   Updated: 2024/08/21 00:01:20 by mvolkman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

class Contact 
{

private:
	std::string firstName;
	std::string lastName;
	std::string nickname;
	std::string phoneNumber;
	std::string darkestSecret;

public:
	void createNewContact(std::string fN, std::string ln, std::string nn, std::string pN, std::string dS)
	{
		firstName = fN;
		lastName = ln;
		nickname = nn;
		phoneNumber = pN;
		darkestSecret = dS;
	}

	void displayName()
};

class PhoneBook
{

private:
	Contact contactList[8];

public:
	void addContact(int index)
	{
		std::string firstName, lastName, nickname, phoneNumber, darkestSecret;

	do
	{
		std::cout << "Enter contact first name: ";
		std::getline(std::cin, firstName);
		if(firstName.empty())
		{
			std::cout << "First name cannot be empty. Try again!" << std::endl;
		}
	} while (firstName.empty());

	do
	{
		std::cout << "Enter contact last name: ";
		std::getline(std::cin, lastName);
		if(lastName.empty())
		{
			std::cout << "Last name cannot be empty. Try again!" << std::endl;
		}
	} while (lastName.empty());

	do
	{
		std::cout << "Enter contact nickname: ";
		std::getline(std::cin, nickname);
		if(nickname.empty())
		{
			std::cout << "Nickname cannot be empty. Try again!" << std::endl;
		}
	} while (nickname.empty());

	do
	{
		std::cout << "Enter contact phone number: ";
		std::getline(std::cin, phoneNumber);
		if(phoneNumber.empty())
		{
			std::cout << "Phone number cannot be empty. Try again!" << std::endl;
		}
	} while (phoneNumber.empty());

	do
	{
		std::cout << "Enter contact darkest secret: ";
		std::getline(std::cin, darkestSecret);
		if(darkestSecret.empty())
		{
			std::cout << "Darkest secret cannot be empty. Try again!" << std::endl;
		}
	} while (darkestSecret.empty());

	contactList[index].createNewContact(firstName, lastName, nickname, phoneNumber, darkestSecret);

	std::cout << "Contact succesfully added to the phonebook!" << std::endl;

	}

	void displayContacts()
	{
		for(int i = 0; i < contactList.length; i++)
		{
			// std::cout << "Contact: " << contactList[i] << std::endl;
		}
	}

};

int	main()
{
	std::string input;
	PhoneBook phoneBook;
	int index = 0;
	
	while(true)
	{
		std::cout << "PHONEBOOK commands: ADD, NEW, EXIT: ";
		// std::getline(std::cin, input); //TODO: what is cin exactly?
		if (!std::getline(std::cin, input)) // safeguard
		{
			std::cout << "Exiting the program!" << std::endl;
		}
		if(input == "ADD")
		{
			phoneBook.addContact(index);
			index = (index + 1 ) % 8;
		}
		else if(input == "SEARCH")
		{
			std::cout << "SEARCH command is correct" << std::endl;

		}

		else if(input == "EXIT")
		{
			std::cout << "Exiting the program!" << std::endl;
			break;
		}
		else
			std::cout << "Invalid command, try again!" << std::endl;
	}


	return(0);
}