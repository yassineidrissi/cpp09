/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaidriss <yaidriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 13:29:52 by yaidriss          #+#    #+#             */
/*   Updated: 2024/03/16 01:17:51 by yaidriss         ###   ########.fr       */
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

std::vector<std::vector<int> >& pm::get_vs_main()
{
	return this->vs_main;
}

std::vector<std::vector<int> >& pm::get_vs_pend()
{
	return this->vs_pend;
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
	// std::vector<std::vector<int> > vs = this->get_vs();
	for(size_t i = 0; i < get_v().size(); ++i)
	{
		std::vector<int> v;
		v.push_back(get_v()[i]);
		this->get_vs().push_back(v);
	}
	// std::cout << "get_vs size :" << this->get_vs().size() << std::endl;
}

void pm::fill(void)
{
	for (size_t i = 0; i < this->get_ln().size(); i++)
	{
		this->set_v(std::stoi(this->get_ln()[i]));	
		this->set_l(std::stoi(this->get_ln()[i]));
		// this->fill_double_v();
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
	this->fill_double_v();
	this->limit = 0;
	// print_vs();
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
	this->print_vs();
}

void pm::printTime(void)
{
	std::cout << YELLOW << 	"Time to proccess a range of    " << this->size << " elements with std::vector : " << this->Vtime.count() << " us" << RESET << std::endl;
	std::cout << GREEN << "Time to proccess a range of " << this->size << " elements with std::List : " << this->Ltime.count() << " us" << RESET << std::endl;
}

//*************** Sort Functions **************//

template <typename T>
void pop_front(std::vector<T>& vec, int i) {
    if (!vec.empty()  && i >= 0 && i < vec.size()) {
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

void pm::merge(int l)
{
// 	unsigned long i = (unsigned long)l;
// 	if(i < this->get_vs().size() && !this->get_vs()[l].empty()) {
//     std::cout << "merge: " << this->get_vs()[l][0] << std::endl;
// } else {
//     std::cout << "Invalid index or empty vector." << std::endl;
// }
	std::cout << "end of vector :"<< l << " "  << get_vs()[l][this->get_vs()[l].size() -1] << std::endl;
	std::cout << "end of vector :"<< l + 1 << " " << get_vs()[l + 1][this->get_vs()[l + 1].size() -1] << std::endl;
	if(this->get_vs()[l][this->get_vs()[l].size() - 1] < this->get_vs()[l + 1][this->get_vs()[l + 1].size() - 1])
	{
		// std::cout << "merge: " << this->get_vs()[l][this->get_vs()[l].size() - 1] << " " << this->get_vs()[l + 1].size() << std::endl;
		unsigned long indexFrom = l + 1; // Assuming you want to merge from this index...
    	unsigned long indexTo = l; // ...into this index.

	    // Check if indices are valid
 	   if(indexFrom < this->get_vs().size() && indexTo < this->get_vs().size() && indexFrom != indexTo) {
		//hello how do you think about this project all this need to do...
  	      // Append all values from this->get_vs()[indexFrom] to this->get_vs()[indexTo]
   	     this->get_vs()[indexTo].insert(this->get_vs()[indexTo].end(), this->get_vs()[indexFrom].begin(), this->get_vs()[indexFrom].end());
	        // Optional: Remove the source element if no longer needed
 	       this->get_vs().erase(this->get_vs().begin() + indexFrom);
  	  } else {
   	     std::cout << "Invalid indices provided." << std::endl;
      }
	}
	else
	{
		// std::cout << "merge 1: " << this->get_vs()[l].size() << " " << this->get_vs()[l + 1].size() << std::endl;
		unsigned long indexFrom = l; // Assuming you want to merge from this index...
    	unsigned long indexTo = l + 1; // ...into this index.

	    // Check if indices are valid
 	   if(indexFrom < this->get_vs().size() && indexTo < this->get_vs().size() && indexFrom != indexTo) {
  	      // Append all values from this->get_vs()[indexFrom] to this->get_vs()[indexTo]
   	     this->get_vs()[indexTo].insert(this->get_vs()[indexTo].end(), this->get_vs()[indexFrom].begin(), this->get_vs()[indexFrom].end());

	        // Optional: Remove the source element if no longer needed
 	       this->get_vs().erase(this->get_vs().begin() + indexFrom);
  	  } else {
   	     std::cout << "Invalid indices provided." << std::endl;
      }
	}
	std::cout << "l merge :" <<l << std::endl;
	print_vs();	
}

void pm::print_vs(void)
{
	// std::cout << "size is " << this->get_vs().size() << std::endl;
	for(unsigned long i = 0; i < this->get_vs().size(); ++i) {
		std::cout << "indice " << i << std::endl;
		for(unsigned long j = 0; j < this->get_vs()[i].size(); ++j) {
			std::cout << this->get_vs()[i][j] << " ";
		}
		std::cout << std::endl;
	}

}

void pm::fill_vs_main()
{
	for(unsigned long i = 0; i < this->get_vs().size(); ++i)
		this->get_vs_main().push_back(this->get_vs()[i]);
}

void pm::sort_v(void)
{
		// std::cout << "im here" << std::endl;
	int j = 0;
	for (; this->get_vs().size() > 3; j++)
		for (int i = 0; i < (this->size/2); ++i)
			merge(i);
	
	this->limit = j;
	
	fill_vs_main();
    // for(int i = 0; is < this->limit; --this->limit)
	// {
	// 	if()
	// }
	// if(!this->limit)
	// else
	// 	this->limit--;
		// print_vs();
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
	this->sort_v();
	end = std::chrono::high_resolution_clock::now();
	this->Vtime = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
	
    start = std::chrono::high_resolution_clock::now();
	// this->sort_l();
	end = std::chrono::high_resolution_clock::now();
	this->Ltime = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
}