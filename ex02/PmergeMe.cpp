/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yassine <yassine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 13:29:52 by yaidriss          #+#    #+#             */
/*   Updated: 2024/03/14 01:37:12 by yassine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

//********* Orthodox Methodes ************//
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

//************ Seters and Geters ************//
std::vector<std::string>& pm::get_ln()
{
	return this->ln;
}

void pm::set_ln(std::string l)
{
	this->ln.push_back(l);
}

std::vector<int>& pm::get_v()
{
	return this->v;
}

void pm::set_v(int v)
{
	this->v.push_back(v);
}

std::list<int>& pm::get_l()
{
	return this->l;
}

void pm::set_l(int l)
{
	this->l.push_back(l);
}

//************** Functions *****************//
void pm::split()
{
	std::vector<std::string> lines;
	std::string ln;
	std::istringstream tokenStream(this->get_ln()[0]);
	while (std::getline(tokenStream, ln, ' ')) 
		lines.push_back(ln);
	
}

std::vector<std::vector<int> >& pm::get_vs()
{
	return this->vs;
}

void pm::fill_double_v(void)
{
	std::vector<std::vector<int> > vs = this->get_vs();
	for(size_t i = 0; i < get_v().size(); ++i)
	{
		std::vector<int> v;
		v.push_back(get_v()[i]);
		vs.push_back(v);
	}
}

void pm::fill(void)
{
	for (size_t i = 0; i < this->get_ln().size(); i++)
	{
		this->set_v(std::stoi(this->get_ln()[i]));	
		this->set_l(std::stoi(this->get_ln()[i]));
		this->fill_double_v();
	}
}

void  pm::parcing(char **av)
{
	int j = 0;
    for(int i = 1; av[i]; ++i)
    {
		std::string line(av[i]);
		std::istringstream iss(line);
		std::string token;
		while(std::getline(iss, token, ' '))
		{
			this->set_ln(token);
			j++;
		}
		if (j > 3000)
			throw pm::pmException();
    }
	this->size = j;
	this->fill();

	// 	for (size_t i = 0; i < this->get_v().size(); i++)
	// 		std::cout << RED << this->get_v()[i] << RESET << std::endl;
	// this->print_l();
}

//************* Print Functions ***************//
void pm::print_l(void)
{
	for (std::list<int>::iterator it = this->get_l().begin(); it != this->get_l().end(); it++)
		std::cout << GREEN << *it << RESET << std::endl;
}

void pm::print_v(void)
{
	for (size_t i = 0; i < this->get_v().size(); i++)
		std::cout << GREEN << this->get_v()[i] << " ";
	std::cout << RESET << std::endl;
}

void pm::print_ln(void)
{
	for (size_t i = 0; i < this->get_ln().size(); i++)
		std::cout << YELLOW << this->get_ln()[i] << " ";
	std::cout << RESET << std::endl;
}


void pm::printBefor(void)
{
	std::cout << YELLOW << "Before :  ";
	this->print_ln();
}

void pm::printAfter(void)
{
	std::cout << GREEN << "After  :  ";
	this->print_v();
}

void pm::printTime(void)
{
	std::cout << YELLOW << 	"Time to proccess a range of    " << this->size << " elements with std::vector : " << this->Vtime.count() << " us" << RESET << std::endl;
	std::cout << GREEN << "Time to proccess a range of " << this->size << " elements with std::List : " << this->Ltime.count() << " us" << RESET << std::endl;
}

//*************** Sort Functions **************//


template <typename T>
void pop_front(std::vector<T>& vec) {
    if (!vec.empty()) {
        vec.erase(vec.begin());
    }
}

// void pm::merge(int l,int m,int b)
// {
// 	int n1 = m - l + 1;
// 	int n2 = b - m;
// 	int L[n1], R[n2];
// 	for (int i = 0; i < n1; i++)
// 		L[i] = this->get_v()[l + i];
// 	for (int j = 0; j < n2; j++)
// 		R[j] = this->get_v()[m + 1 + j];
// 	int i = 0;
// 	int j = 0;
// 	int k = l;
// 	while (i < n1 && j < n2)
// 	{
// 		if (L[i] <= R[j])
// 		{
// 			this->get_v()[k] = L[i]; //33 482
// 			i++;
// 		}
// 		else
// 		{
// 			this->get_v()[k] = R[j];//320 498
// 			j++;
// 		}
// 		k++;
// 	}
// 	while (i < n1)
// 	{
// 		this->get_v()[k] = L[i];
// 		i++;
// 		k++;
// 	}
// 	while (j < n2)
// 	{
// 		this->get_v()[k] = R[j];
// 		j++;
// 		k++;
// 	}
// }

// void pm::sort_v(int l, int b)
// {
// 	if (b - l + 1 < 2)
// 	{
// 		for(int j = l;j < b; ++j)
// 		{
// 			if(this->get_v()[j] > this->get_v()[j + 1])
// 			{
// 				int temp = this->get_v()[j];
// 				this->get_v()[j] = this->get_v()[j + 1];
// 				this->get_v()[j + 1] = temp;
// 			}
// 		}
// 	}
// 	else
// 	{
// 		int m = (l + b) / 2;
// 		this->sort_v(l, m);
// 		this->sort_v(m + 1, b);
// 		this->merge(l, m , b);
// 	}
// }

void sort_v(int l, int b)
{
	//add the code of the sort_v functions here 
}

void pm::sort_l(void)
{
	this->get_l().sort();
	this->print_l();
}



void pm::sort(void)
{
	std::chrono::high_resolution_clock::time_point start;
	std::chrono::high_resolution_clock::time_point end;
	
	start = std::chrono::high_resolution_clock::now();
	this->sort_v(0, this->size - 1);
	end = std::chrono::high_resolution_clock::now();
	this->Vtime = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
	
    start = std::chrono::high_resolution_clock::now();
	// this->sort_l();
	end = std::chrono::high_resolution_clock::now();
	this->Ltime = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
}