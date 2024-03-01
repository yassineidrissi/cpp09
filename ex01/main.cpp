/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaidriss <yaidriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 22:50:01 by yaidriss          #+#    #+#             */
/*   Updated: 2024/03/01 22:50:25 by yaidriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int parsing(char *av, RPN& r)
{
	r.c = split(av, ' ');
	if (check_v(r.c))
		return 0;
	else
		return 1;
}

int main(int ac, char **av)
{
	RPN r;
	if(ac == 2)
		if(parsing(av[1], r))
			return 1;
	else
		std::cerr << RED << "Wrong parameters" << RESET << std::endl;
	return 0;
}
