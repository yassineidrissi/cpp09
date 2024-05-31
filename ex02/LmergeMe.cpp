/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaidriss <yaidriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 23:36:45 by yaidriss          #+#    #+#             */
/*   Updated: 2024/05/31 19:50:12 by yaidriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

void pm::pair_l(void)
{
	Lst tmp;
	for (Lst::iterator it = this->ls.begin(); it != this->ls.end(); std::advance(it, 2))
	{
		if (std::next(it) != this->ls.end())
		{
			MiniLst temp;
			if(*it > *std::next(it))
			{
 				MiniLst temp = *it;
                *it = *std::next(it);
                *std::next(it) = temp;
			}
			MiniLst flst;
			for (MiniLst::iterator it1 = it->begin(); it1 != it->end(); it1++)
				flst.push_back(*it1);
			for (MiniLst::iterator it2 = std::next(it)->begin(); it2 != std::next(it)->end(); ++it2)
				flst.push_back(*it2);
			tmp.push_back(flst);
			flst.clear();
		}
		else
		 this->l_odd.push_back(*it);
	}
	this->ls = tmp;
	tmp.clear();
}


void pm::chaine_l(Lst& d, Lst& main, Lst& pend, int reset)
{
	//unpaire
	Lst newl;
	size_t size = l[0].size()/2;
	for (size_t i = 0; i < d.size(); ++i)
	{
		MiniLst l1, l2;
		for(size_t j = 0; j < size; ++j)
		{
			l1.push_back(l[i][j]);
			l2.push_back(l[i][j + size]);
		}
		newl.push_back(l1);
		newl.push_back(l2);
	}
	d = newl;
	newl.clear();
	// createChains 
	int index = 0;
	Lst::iterator it = d.begin();
	while (it != d.end())
	{
		if (index % 2 == 0)
			main.push_back(*it);
		else
			pend.push_back(*it);
		++index;
		++it;
	}
	Lst::iterator re = reset.begin();
	while (re != reset.end())
	{
		pend.push_back(*re);
		++re;
	}
	//insertPaid
	for(Lst::iterator it = pend.begin(); it != pend.end(); std::next(it))
	{
		Lst::iterator it1 = std::lower_bound(main.begin(), main.end(), *it, Compare);
		main.insert(it1, *it);
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
	chaine_l(d, main, pend, reset);
	d = main;
	main.clear();
}