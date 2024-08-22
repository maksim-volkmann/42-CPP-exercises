/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvolkman <mvolkman@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 14:49:12 by mvolkman          #+#    #+#             */
/*   Updated: 2024/08/16 15:59:59 by mvolkman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

int	main(int ac, char **av)
{
	if(ac == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	}
	else
	{
		std::string output;

		for(int i = 1; i < ac; i++)
			output += av[i];

		for(int i = 0; i < output.length(); i++)
			output[i] = std::toupper(output[i]);

		std::cout << output << std::endl;
	}

	return (0);
}
