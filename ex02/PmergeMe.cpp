/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaidriss <yaidriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 13:29:52 by yaidriss          #+#    #+#             */
/*   Updated: 2024/03/08 18:46:53 by yaidriss         ###   ########.fr       */
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

void pm::set_v(int v)
{
	this->v.push_back(v);
}

std::list<int> pm::get_l()
{
	return this->l;
}

void pm::set_l(int l)
{
	this->l.push_back(l);
}

void pm::split()
{
	std::vector<std::string> lines;
	std::string ln;
	std::istringstream tokenStream(this->get_ln()[0]);
	while (std::getline(tokenStream, ln, ' ')) 
		lines.push_back(ln);
	
}

// void handl(char **av)
// {
// 	std::string line;
// 	for(int i = 1; av[i]; ++i)
// 		while(std::getline(std::ifstream(av[i]), line))
// 			p.ln.push_back(line);
// 	for (size_t i = 0; i < p.ln.size(); i++)
// 	{
// 		std::vector<int> m = split(RPN.ln[i], ' ');
// 		pair temp;
// 		// temp.f = std::stoi(m[0]);
// 		// temp.s = std::stoi(m[1]);
// 		RPN.v.push_back(temp);
// 	}
// 	for (size_t i = 0; i < p.v.size(); i++)
// 		std::cout << RPN.v[i].f << " " << RPN.v[i].s << std::endl;
// }

void  pm::parcing(char **av)
{
    for(int i = 1; av[i]; ++i)
    {
		std::string line(av[i]);
		std::istringstream iss(line);
		std::string token;
		while(std::getline(iss, token, ' '))
			this->set_ln(token);
			// std::cout << YELLOW << token << RESET << std::endl;
    }
	// std::cout << this->get_ln()[0].size() << std::endl;
	for (size_t i = 0; i < this->get_ln().size(); i++)
	{
		this->set_v(std::stoi(this->get_ln()[i]));
		// this->set_l(std::stoi(this->get_v()[i]));
		std::cout << RED << get_ln()[i] << RESET << std::endl;
		std::cout << GREEN << get_v()[i] << RESET << std::endl;
	}
	// for (size_t i = 0; i < p.v.size(); i++)
	// 	std::cout << RPN.v[i].f << " " << RPN.v[i].s << std::endl;

}