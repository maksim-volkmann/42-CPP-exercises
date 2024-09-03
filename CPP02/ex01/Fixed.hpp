/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvolkman <mvolkman@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 09:40:00 by mvolkman          #+#    #+#             */
/*   Updated: 2024/09/03 12:23:13 by mvolkman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed{
private:
	int _fixedNumber;
	static const int fractionalBits = 8;

public:
	Fixed();
	Fixed(const Fixed& other);
	Fixed& operator=(const Fixed& other);
	Fixed(const int integer);
	~Fixed();

	int getRawBits(void) const;
	void setRawBits(int const raw);
};
//figure it out
std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif
