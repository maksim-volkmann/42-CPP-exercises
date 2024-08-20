/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvolkman <mvolkman@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 14:22:53 by mvolkman          #+#    #+#             */
/*   Updated: 2024/08/20 17:27:40 by mvolkman         ###   ########.fr       */
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
};

class PhoneBook
{

private:
	Contact contactList[8];

};

int	main()
{
	std::string input;
	PhoneBook phoneBook;
	int contactIndex = 0;
	
	while(true)
	{
		std::cout << "PHONEBOOK commands: ADD, NEW, EXIT: ";
		std::getline(std::cin, input); //TODO: what is cin exacly?

		if(input == "ADD")
			std::cout << "ADD command is correct" << std::endl;
		else if(input == "SEARCH")
			std::cout << "SEARCH command is correct" << std::endl;
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