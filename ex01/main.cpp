/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaidriss <yaidriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 22:50:01 by yaidriss          #+#    #+#             */
/*   Updated: 2024/03/04 22:34:27 by yaidriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int parsing(char *av, RPN& r)
{
	int check = 0;
	r.ln = split(av, ' ');
	for(size_t i =0 ; i < r.ln.size() && !check; i++)
	{
		if(r.ln[i].size() == 1 && (r.ln[i][0] == '-' || r.ln[i][0] == '*' || r.ln[i][0] == '+' || r.ln[i][0] == '/'))
		{
			r.op.push_back(r.ln[i][0]);
			check = operation(r);
		}
		else if (r.ln[i].size() == 1 && std::isdigit(r.ln[i][0]))
			r.nm.push_back(r.ln[i][0] - '0');
		else
			return(printErreur(2));
	}
	return check;
}

int main(int ac, char **av)
{
	RPN r;
	if(ac == 2)
		if(parsing(av[1], r))
			return 1;
	std::cout << GREEN << r.nm[0] << RESET << std::endl;
	return 0;
}