/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvolkman <mvolkman@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 14:43:18 by mvolkman          #+#    #+#             */
/*   Updated: 2024/08/24 14:43:20 by mvolkman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact {
private:
	std::string firstName;
	std::string lastName;
	std::string nickname;
	std::string phoneNumber;
	std::string darkestSecret;

public:
	void createNewContact(std::string fN, std::string ln, std::string nn, std::string pN, std::string dS);
	std::string getFirstName() const;
	std::string getLastName() const;
	std::string getNickname() const;
	void displayFullContactDetails() const;
};

#endif
