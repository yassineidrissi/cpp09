/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaidriss <yaidriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 22:50:01 by yaidriss          #+#    #+#             */
/*   Updated: 2024/03/07 18:46:12 by yaidriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

void parsing(char *av, RPN& r)
{
	int check = 0;
	std::string l = av;
	r.set_ln(r.split(l, ' '));
	for(size_t i =0 ; i < r.get_ln().size() && !check; i++)
	{
		if(r.get_ln()[i].size() == 1 && (r.get_ln()[i][0] == '-' || r.get_ln()[i][0] == '*' || r.get_ln()[i][0] == '+' || r.get_ln()[i][0] == '/'))
		{
			r.set_op((r.get_ln()[i][0]));
			check = r.opert();
		}
		else if (r.get_ln()[i].size() == 1 && std::isdigit(r.get_ln()[i][0]))
			r.set_nm(r.get_ln()[i][0] - '0');
		else
			throw RPNException();
	}
}

int main(int ac, char **av)
{
	RPN r;
	try
	{
		if(ac != 2)
			throw RPNException();
		parsing(av[1], r);
		for (size_t i = 0; i < r.get_nm().size(); i++)
			std::cout << GREEN << r.get_nm()[i] << RESET << std::endl;	
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}	
	return 0;
}