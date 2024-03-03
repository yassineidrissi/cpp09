/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaidriss <yaidriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 22:50:01 by yaidriss          #+#    #+#             */
/*   Updated: 2024/03/03 11:46:56 by yaidriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int parsing(char *av, RPN& r)
{
	r.ln = split(av, ' ');
	for(size_t i =0 ; i < r.ln.size(); i++)
	{
		if(r.ln[i].size() == 1 && (r.ln[i][0] == '-' || r.ln[i][0] == '*' || r.ln[i][0] == '+' || r.ln[i][0] == '/'))
			r.op.push_back(r.ln[i][0]);
		else if (r.ln[i].size() == 1 && std::isdigit(r.ln[i][0]))
			r.nm.push_back(r.ln[i][0] - '0');
		else
			return(printErreur(2));
	}
	if(r.op.size() < 1 || r.op.size() != r.nm.size() - 1)
		return(printErreur(2));
	return 0;
}

int main(int ac, char **av)
{
	RPN r;
	if(ac == 2)
		if(parsing(av[1], r))
			return 1;
	operation(r);
	// std::cerr << RED << "Error" << RESET << std::endl;
	return 0;
}