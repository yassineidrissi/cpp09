/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaidriss <yaidriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 13:29:52 by yaidriss          #+#    #+#             */
/*   Updated: 2024/03/07 20:07:57 by yaidriss         ###   ########.fr       */
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
}

std::vector<std::string> pm::get_ln()
{
	return this->ln;
}

void pm::set_ln(std::vector<std::string> ln)
{
	this->ln = ln;
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
	this->l = l;
}

std::vector<std::string> split(const std::string &s, char delimiter) 
{
	std::vector<std::string> lines;
	std::string ln;
	std::istringstream tokenStream(s);
	while (std::getline(tokenStream, ln, delimiter)) 
		lines.push_back(ln);
	return lines;
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
			p.ln.push_back(line);
	for (size_t i = 0; i < p.ln.size(); i++)
	{
		std::vector<int> m = split(RPN.ln[i], ' ');
		pair temp;
		temp.f = std::stoi(m[0]);
		temp.s = std::stoi(m[1]);
		RPN.v.push_back(temp);
	}
	for (size_t i = 0; i < p.v.size(); i++)
		std::cout << RPN.v[i].f << " " << RPN.v[i].s << std::endl;

}