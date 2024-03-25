/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaidriss <yaidriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 13:29:52 by yaidriss          #+#    #+#             */
/*   Updated: 2024/03/25 21:43:46 by yaidriss         ###   ########.fr       */
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

std::vector<int>& pm::get_vs_odd()
{
	return this->vs_odd;
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
	this->get_vs().clear();
	for(size_t i = 0; i < get_v().size(); ++i)
	{
		std::vector<int> v;
		v.push_back(get_v()[i]);
		this->get_vs().push_back(v);
	}
	std::cout << "get_vs size :" << this->get_vs().size() << std::endl;
}

void pm::fill(void)
{
	for (size_t i = 0; i < this->get_ln().size(); i++)
	{
		this->set_v(std::stoi(this->get_ln()[i]));	
		this->set_l(std::stoi(this->get_ln()[i]));
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
	this->limit = j - 1;
	this->fill();
	this->fill_double_v();

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

void pm::merge(int l)
{
	std::cout << "end of vector :"<< l << " "  << get_vs()[l][this->get_vs()[l].size() -1] << std::endl;
	if(this->get_vs()[l][this->get_vs()[l].size() - 1] < this->get_vs()[l + 1][this->get_vs()[l + 1].size() - 1])
	{
		unsigned long indexFrom = l + 1; // Assuming you want to merge from this index...
    	unsigned long indexTo = l; // ...into this index.
 	   if(indexFrom < this->get_vs().size() && indexTo < this->get_vs().size() && indexFrom != indexTo) {
   	     this->get_vs()[indexTo].insert(this->get_vs()[indexTo].end(), this->get_vs()[indexFrom].begin(), this->get_vs()[indexFrom].end());
 	       this->get_vs().erase(this->get_vs().begin() + indexFrom);
  	  } else {
   	     std::cout << "Invalid indices provided." << std::endl;
      }
	}
	else
	{
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
	std::cout << "l merge :" << l << std::endl;
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
	// if(this->get_vs_pend().size())
	// 	for(unsigned long i = 0; i < this->get_vs_pend()[0].size(); ++i)
	// 		std::cout << RED << "pend :" << this->get_vs_pend()[0][i] << " " << RESET << std::endl;

}

void pm::print_vs_main()
{
	std::cout << GREE;
	for(unsigned long i = 0; i < this->get_vs_main().size(); ++i) {
		std::cout << "indice " << i << std::endl;
		for(unsigned long j = 0; j < this->get_vs_main()[i].size(); ++j) {
			std::cout << this->get_vs_main()[i][j] << " ";
		}
		std::cout << RESET << std::endl;
	}

}

void pm::print_vs_pend()
{
	std::cout << YELLOW;
	for(unsigned long i = 0; i < this->get_vs_pend().size(); ++i) {
		std::cout << "indice " << i << std::endl;
		for(unsigned long j = 0; j < this->get_vs_pend()[i].size(); ++j) {
			std::cout << this->get_vs_pend()[i][j] << " ";
		}
		std::cout << RESET << std::endl;
	}
}

void pm::print_vs_odd()
{
    std::cout << RED;
    std::cout << "indice 0 " << std::endl;
	std::vector<int> vs_odd = this->get_vs_odd();
    if (!vs_odd.empty()) {
        for(unsigned long i = 0; i < vs_odd.size(); ++i)
        {
            // if (i < vs_odd.size() && !vs_odd[i].empty()) {
                int nb = vs_odd[i];
                std::cout << nb << std::endl;
            // }
        }
    }
    std::cout << RESET << std::endl;
}

void pm::fill_vs_main()
{
	this->get_vs_main().clear();
	this->get_vs_main().push_back(this->get_vs()[0]);
	this->get_vs_main().push_back(this->get_vs()[1]);
	for(unsigned long i = 3; i < this->get_vs().size(); i+=2)
		this->get_vs_main().push_back(this->get_vs()[i]);
}

void pm::fill_vs_pend()
{
	this->get_vs_pend().clear();
	for(unsigned long i = 2; i < this->get_vs().size() - 1 ; i+=2)           
		this->get_vs_pend().push_back(this->get_vs()[i]);
}


void pm::fill_vs_odd()
{
	// std::vector<int> vmain = this->get_v();
	// std::vector<std::vector<int> vodd = this->get_vs_odd();
	// for(unsigned int i = 0; i < get_vs_odd().size();++i)
		get_vs_main().push_back(get_vs_odd());
}

void pm::split_mp()
{
	std::cout << GREEN << "im in split" << RESET << std::endl;
	this->get_vs_main().clear();
	this->get_vs_main().push_back(this->get_vs()[0]);
	std::cout << BLUE << "get_vs  " << 0 << " " << this->get_vs()[0][this->get_vs()[0].size() - 1] << RESET << std::endl;
	this->get_vs_main().push_back(this->get_vs()[1]);
	std::cout << BLUE << "get_vs  " << 1 << " " << this->get_vs()[1][this->get_vs()[1].size() - 1] << RESET << std::endl;
	for(unsigned long i = 2; i < this->get_vs().size(); ++i)
	{
		if(i % 2 == 1)
			this->get_vs_main().push_back(this->get_vs()[i]);
		else
			this->get_vs_pend().push_back(this->get_vs()[i]);
		std::cout << BLUE << "get_vs  " << i << " " << this->get_vs()[i][this->get_vs()[i].size() - 1] << RESET << std::endl;
	}
	this->get_vs() = this->get_vs_main();
	this->get_vs().push_back(this->get_vs_pend()[0]);
}

void pm::generate_vs()
{
	// std::vector<std::vector<int> >tmp;
	for(unsigned long i = 0; i < this->get_vs().size(); ++i)
		for(unsigned long j = 0; j < this->get_vs()[i].size(); ++j)
		{
			get_v().push_back(this->get_vs()[i][j]);
			// std::cout << GREEN << "tmp " << i + j << " " << tmp[i + j][0] << RESET << std::endl;
		}
	// this->get_vs() = tmp;
}

void pm::handl_vs()
{
	std::cout << GREEN << "******************** handl_vs " << this->limit << " " << RESET << std::endl;

    for (int j = 0; j < this->limit - 1; j++)
        for (int i = 0; i < (this->size/2); ++i)
            merge(i);
    this->limit--;
    // if(this->get_vs().size() == 3)
        // this->get_vs_pend().push_back(this->get_vs()[2]);
}
void pm::vstov()
{
	std::vector<int>& tmp = this->get_v();
	tmp.clear();
	for(unsigned long i = 0; i < this->get_vs().size(); ++i)
		for(unsigned long j = 0; j < this->get_vs()[i].size(); ++j)
			tmp.push_back(this->get_vs()[i][j]);
	this->get_vs().clear();
}

void pm::baniry_sort()
{
	std::vector<std::vector<int> >& m = this->get_vs_main();
	std::vector<std::vector<int> >& p = this->get_vs_pend();
	std::vector<std::vector<int> >& tmp = this->get_vs();
	tmp.clear();
	for(unsigned long i = 0; i < p.size(); ++i)
	{
		for(unsigned long j = 0; j < m.size(); ++j)
		{
			if(m[j][m[j].size() -1] > p[i][p[i].size() -1])
			{
				m.insert(m.begin() + j, p[i]);
				// p[i].clear(); //! need to check
				j++;
			}
			
		}
	}
	p.clear();
	tmp = m;
	//! i will neeed this after 
}

void pm::handl_vs_first()
{
	int j = 0;
	 for (;this->get_vs().size() > 3 ; j++)
        for (int i = 0; i < (this->size/2); ++i)
            merge(i);
    this->limit = j;
	// std::cout << RED << "size id size : " << this->get_vs().size() << std::endl;
    if(this->get_vs().size() == 3)
    {
		std::vector<int> v = this->get_vs()[2];
		// std::vector<int> vodd = this->get_vs_odd();
		for(unsigned int i = 0; i < v.size(); ++i)
		{
			// if(vodd.empty())
			// 	vodd.push_back(std::vector<int>());
			this->get_vs_odd().push_back(v[i]);
			std::cout << RED << "this odd : " << v[i] << RESET << std::endl;
		}
		this->get_vs()[2].clear();
    //     this->get_vs().erase(this->get_vs().begin() + 2);
    }	
}

void pm::odd_insert()
{
    std::vector<int>& odd = this->get_vs_odd();
    std::vector<std::vector<int> >& pend = this->get_vs_pend();

    if (!odd.empty()) {
		for(unsigned int i = 0; i < odd.size(); ++i)
		{
			for(unsigned int j = 0; j < pend.size(); ++j)
			{
				if(odd[i] < pend[j][0])
				{
					std::vector<int> v;
					v.push_back(odd[i]);
					pend.insert(pend.begin() + j, v);
					break  ;
				}
				else if(j == pend.size() - 1)
				{
					std::vector<int> v;
					v.push_back(odd[i]);
					pend.push_back(v);
					break  ;
				}
			}
		}			
    }
}



void pm::sort_v(void)
{
	std::cout << "Sort_v : This->limit is " << this->limit << std::endl;
	handl_vs_first();
	vstov();
	std::cout << "First sort " << std::endl;
	// std::cout << get_vs_odd().size() << std::endl;
	for(unsigned long i = 0; this->limit - 1 > 0; ++i)
	{
		std::this_thread::sleep_for(std::chrono::seconds(10));
		std::cout << RED << "i is " << i << " limit is " << this->limit << RESET << std::endl;
		fill_double_v();
		handl_vs();
		fill_vs_main();
		fill_vs_pend();
		baniry_sort();
		vstov();
		// usleep(1000);00
	}
	// print_v();
    // vstov();
	// fill_double_v();
	// handl_vs();
	// std::cout << GREEN << ">>>>>****************************************************************" << RESET << std::endl;
	// print_vs();
	// fill_vs_main();
	// fstd::cout << YELLOW << "main print" << RESET << std::endl;
	// print_vs_main();
	// fill_vs_pend();
	// std::cout << YELLOW << "pend print" << RESET << std::endl;
	// print_vs_pend();
	// baniry_sort();
	// std::cout << RED << "baniry_sort " << std::endl;
	// print_vs_main();
	// print_vs_pend();
	// // vmaintovs();
	// print_v();
	// std::cout << RED << "PRINT V" <<  RESET << std::endl;
	// print_vs();
	// vstov();
	// std::cout << RED << "PRINT V 2" <<  RESET << std::endl;
	// print_v();
	// print_vs();
	// // std::cout << GREEN 
	// std::cout << RED << "finish loop " << RESET << std::endl;
	fill_vs_odd();
	// std::cout << RED << "PRINT V" <<  RESET << std::endl;
	// print_v();	
	// fill_double_v();
	// std::cout << GREEN << "AFTRE FILL loop " << RESET << std::endl;
	// print_vs();
	// fill_vs_main();
	// print_vs_main();
	// std::cout << RED << "this is pend" << RESET << std::endl;
	// fill_vs_pend();
	// print_vs_pend();
	// fill_vs_main();
	// fill_vs_pend();
	odd_insert();
	// std::cout << this->vs_odd[0] << std::endl;
	std::cout << RED << "******************************************" << RESET << std::endl;
	print_vs_main();
	print_vs_pend();
	// fill_final();
	baniry_sort();
	// print_vs_main();	
	// print_v();
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