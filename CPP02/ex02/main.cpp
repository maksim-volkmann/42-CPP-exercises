/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvolkman <mvolkman@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 09:45:32 by mvolkman          #+#    #+#             */
/*   Updated: 2024/09/10 12:07:06 by mvolkman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void ) {
	// Fixed a;
	// Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	// std::cout << a << std::endl;
	// std::cout << ++a << std::endl;
	// std::cout << a << std::endl;
	// std::cout << a++ << std::endl;
	// std::cout << a << std::endl;

	// std::cout << b << std::endl;

	// std::cout << Fixed::max( a, b ) << std::endl;
	// Fixed b;
	// Fixed a = ++b;
	// std::cout << a << std::endl;
	// std::cout << b << std::endl;
	// std::cout << a << std::endl;

	Fixed e;
	Fixed y = e++;
	std::cout << y << std::endl;
	std::cout << e << std::endl;
	Fixed a(1.5f);
	Fixed b(2.5f);
	Fixed c = a + b;
	std::cout << c << std::endl;

	return 0;
}
