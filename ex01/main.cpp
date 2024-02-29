/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaidriss <yaidriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 22:50:01 by yaidriss          #+#    #+#             */
/*   Updated: 2024/02/29 01:06:09 by yaidriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int parsing(char *av)
{
	std::vector<std::string> c = split(av, " ");
	if (check_v(c))
		return 0;
	else
		return 1;
}

int main(int ac, char **av)
{
	
	if(ac == 2)
		if(parsing(av[0]))
			
	else
		std::cerr << RED << "Wrong parameters" << RESET << std::endl;
	return 0;
}