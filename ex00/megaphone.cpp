/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvolkman <mvolkman@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 14:49:12 by mvolkman          #+#    #+#             */
/*   Updated: 2024/08/15 18:38:57 by mvolkman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

int	main(int ac, char **av)
{
	if(ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		std::cout << "Just testing +1 arguments" << std::endl;
	}
	
	return (0);
}


#include <iostream>  // This header file allows us to use std::cout and other input/output functionality
#include <cctype>    // This header file provides functions for character handling, such as std::toupper

int main(int argc, char *argv[]) {
    if (argc == 1) {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    } else {
        for (int i = 1; i < argc; i++) {
            std::string str = argv[i];  // Convert C-style string to C++ string for easier manipulation
            for (size_t j = 0; j < str.size(); j++) {
                std::cout << static_cast<char>(std::toupper(str[j]));  // Convert each character to uppercase
            }
        }
        std::cout << std::endl;
    }
    return 0;  // Return 0 to indicate successful execution
}
