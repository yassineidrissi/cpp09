/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaidriss <yaidriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 23:36:45 by yaidriss          #+#    #+#             */
/*   Updated: 2024/05/30 23:08:33 by yaidriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

void pm::pair_l(void)
{
	Lst tmp;
	for (Lst::iterator it = this->ls.begin(); it != this->ls.end(); it++)
	{
		if(Lst + 1 != this->ls.end())
		{
			tmp.push_back(*it + *(it + 1));
			it++;
		}
		else
			tmp.push_back(*it);
	}
}

void pm::sort_l(void)
{
	Lst& d = this->ls;
	Lst pend;
	Lst main;
	Lst rest;


	if (d.size() == 1)
		return;
	if (d.size() % 2 != 0)
	{
		rest.push_back(d.back());
		d.pop_back();
	}
	pair_l();
	sort_l();
	chain(d, main, pend, reset);
	d = main;
	main.clear();
}