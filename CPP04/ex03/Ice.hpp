/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvolkman <mvolkman@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 13:19:20 by mvolkman          #+#    #+#             */
/*   Updated: 2024/09/18 21:25:54 by mvolkman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Ice : public AMateria {
public:
	Ice();
	Ice(Ice const & other);
	Ice & operator=(Ice const & other);
	virtual ~Ice();

	virtual AMateria* clone() const; // Return a new Ice object
	virtual void use(ICharacter& target); // Use the Ice Materia on a character
};

#endif
