/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvolkman <mvolkman@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 14:45:53 by mvolkman          #+#    #+#             */
/*   Updated: 2024/08/24 18:47:41 by mvolkman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook {
private:
	Contact contactList[8];
	std::string formatText(const std::string& text) const;

public:
	void addContact(int index);
	void displayContacts() const;
};

#endif
    //  bomzas
    //   urodas |
// |     INDEX|FIRST NAME| LAST NAME|  NICKNAME|
