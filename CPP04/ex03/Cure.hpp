/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvolkman <mvolkman@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 14:02:20 by mvolkman          #+#    #+#             */
/*   Updated: 2024/09/18 21:27:38 by mvolkman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Cure : public AMateria {
public:
	Cure();
	Cure(Cure const & other);
	Cure & operator=(Cure const & other);
	virtual ~Cure();

	virtual AMateria* clone() const; // Return a new Cure object
	virtual void use(ICharacter& target); // Use the Cure Materia on a character
};

#endif
