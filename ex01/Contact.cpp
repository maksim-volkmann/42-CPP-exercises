#include "Contact.hpp"

void Contact::createNewContact(std::string fN, std::string ln, std::string nn, std::string pN, std::string dS)
{
	firstName = fN;
	lastName = ln;
	nickname = nn;
	phoneNumber = pN;
	darkestSecret = dS;
}

std::string Contact::getFirstName() const
{
	return firstName;
}

