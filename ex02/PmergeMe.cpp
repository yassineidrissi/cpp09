/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yassine <yassine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 13:29:52 by yaidriss          #+#    #+#             */
/*   Updated: 2024/03/08 01:09:20 by yassine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

pm::pm()
{
}

pm::~pm()
{
}

pm::pm(pm const &p)
{
	*this = p;
}

pm &pm::operator=(pm const &p)
{
	this->ln = p.ln;
	this->v = p.v;
	this->l = p.l;
	return *this;
}

std::vector<std::string> pm::get_ln()
{
	return this->ln;
}

void pm::set_ln(std::string l)
{
	this->ln.push_back(l);
}

std::vector<int> pm::get_v()
{
	return this->v;
}

void pm::set_v(std::vector<int> v)
{
	this->v = v;
}

std::list<int> pm::get_l()
{
	return this->l;
}

void pm::set_l(std::list<int> l)
{
	this->l.push_back(l.size());
}

void split(char delimiter, bool lvsl)
{
	std::vector<std::string> lines;
	std::string ln;
	std::istringstream tokenStream(s);
	while (std::getline(tokenStream, ln, delimiter)) 
		lines.push_back(ln);
}

void handl(char **av)
{
	std::string line;
	for(int i = 1; av[i]; ++i)
		while(std::getline(std::ifstream(av[i]), line))
			p.ln.push_back(line);
	for (size_t i = 0; i < p.ln.size(); i++)
	{
		std::vector<int> m = split(RPN.ln[i], ' ');
		pair temp;
		// temp.f = std::stoi(m[0]);
		// temp.s = std::stoi(m[1]);
		RPN.v.push_back(temp);
	}
	for (size_t i = 0; i < p.v.size(); i++)
		std::cout << RPN.v[i].f << " " << RPN.v[i].s << std::endl;
}

void parcing(char **av)
{
		std::string line;
	for(int i = 1; av[i]; ++i)
		while(std::getline(std::ifstream(av[i]), line))
			p.set_ln(line);
	for (size_t i = 0; i < p.get_ln().size(); i++)
	{
		set_v(std::stoi(get_ln()[i]));
		set_l(std::stoi(get_v()[i]));
		std::cout << get_ln()[i] << std::endl;
		std::cout << get_v()[i] << std::endl;
	}
	// for (size_t i = 0; i < p.v.size(); i++)
	// 	std::cout << RPN.v[i].f << " " << RPN.v[i].s << std::endl;

}