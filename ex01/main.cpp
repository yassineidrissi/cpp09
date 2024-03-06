/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaidriss <yaidriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 22:50:01 by yaidriss          #+#    #+#             */
/*   Updated: 2024/03/06 12:40:17 by yaidriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int parsing(char *av, RPN& r)
{
	int check = 0;
	std::string l = av;
	r.ln = r.split(l, ' ');
	for(size_t i =0 ; i < r.ln.size() && !check; i++)
	{
		if(r.ln[i].size() == 1 && (r.ln[i][0] == '-' || r.ln[i][0] == '*' || r.ln[i][0] == '+' || r.ln[i][0] == '/'))
		{
			r.op.push_back(r.ln[i][0]);
			check = r.opert(r);
		}
		else if (r.ln[i].size() == 1 && std::isdigit(r.ln[i][0]))
			r.nm.push_back(r.ln[i][0] - '0');
		else
			throw RPNException();
			
	}
	return check;
}

int main(int ac, char **av)
{
	RPN r;
	try
	{
		if(ac == 2)
			if(parsing(av[1], r))
				return 1;
		for (size_t i = 0; i < r.nm.size(); i++)
			std::cout << GREEN << r.nm[i] << RESET << std::endl;	
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}
	
	return 0;
}