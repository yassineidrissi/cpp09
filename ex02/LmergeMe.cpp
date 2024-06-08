/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaidriss <yaidriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 23:36:45 by yaidriss          #+#    #+#             */
/*   Updated: 2024/06/08 17:28:49 by yaidriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"


static bool Compare_l(const MiniLst& a, const MiniLst& b)
{
    return a.back() <= b.back();
}

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
 				temp = *it;
                *it = *std::next(it);
                *std::next(it) = temp;
			}
			MiniLst flst;
			for (MiniLst::iterator it1 = it->begin(); it1 != it->end(); it1++)
				flst.push_back(*it1);
			for (MiniLst::iterator it2 = std::next(it)->begin(); it2 != std::next(it)->end(); it2++)
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

void pm::chaine_l(Lst& d, Lst& main, Lst& pend_l, Lst& rest)
{
	//!unpaire
	Lst newOne;
    size_t size = d.front().size() / 2;

    for (Lst::iterator digitList = d.begin(); digitList != d.end(); ++digitList)
    {
        MiniLst list1, list2;
        MiniLst::iterator it = digitList->begin();
        for (size_t j = 0; j < size; ++j)
        {
            list1.push_back(*it);
            ++it;
        }
        for (size_t j = size; j < 2*size; ++j)
        {
            list2.push_back(*it);
            ++it;
        }
        newOne.push_back(list1);
        newOne.push_back(list2);
    }
	d.clear();
    d = newOne;
    newOne.clear();

	//!chain
	int index = 0;
    Lst::iterator it = d.begin();
    while (it != d.end())
    {
        if (index % 2 != 0)
            main.push_back(*it);
        else
            pend_l.push_back(*it);
        index++;
        it++;
    }
    
    Lst::iterator re = rest.begin();
    while(re != rest.end())
    {
        pend_l.push_back(*re);
        re++;
    }
	//!insertPaid
	for(Lst::iterator it = pend_l.begin(); it != pend_l.end(); ++it)
	{
		Lst::iterator it1 = std::lower_bound(main.begin(), main.end(), *it, Compare_l);
		main.insert(it1, *it);
	}
	this->ls = d;
}

void pm::sort_l(void)
{
	Lst& d = this->ls;
	Lst& main = this->l_main;
	Lst pend_l;
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
	chaine_l(d, main, pend_l, rest);
	d = main;
	main.clear();
}