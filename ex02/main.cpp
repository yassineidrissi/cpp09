/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaidriss <yaidriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 13:34:36 by yaidriss          #+#    #+#             */
/*   Updated: 2024/05/18 01:44:08 by yaidriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int ac, char **av)

{
	pm p;
	try
	{
		pm p;
		if (ac < 2)
			throw pm::pmException() ; 
		else
		{
			p.parcing(av);
			p.printBefor();
			p.sort();
			p.printAfter();
			p.printTime();
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}	
}