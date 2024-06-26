/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaidriss <yaidriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 13:29:52 by yaidriss          #+#    #+#             */
/*   Updated: 2024/05/16 22:56:12by yaidriss         ###   ########.fr       */
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

Vec& pm::get_vs_odd()
{
	return this->vs_odd;
}

Lst& pm::get_ls()
{
	return this->ls;
}

void pm::set_size(int size)
{
	this->size = size;
}

//************** Functions *****************//
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
}

void pm::fill_double_l(void)
{
	this->get_ls().clear();
	for(std::list<int>::iterator it = this->get_l().begin(); it != this->get_l().end(); it++)
	{
		std::list<int> l;
		l.push_back(*it);
		this->get_ls().push_back(l);
	}
}

void pm::fill(void)
{
	for (size_t i = 0; i < this->get_ln().size(); i++)
	{
		this->v.push_back(std::stoi(this->get_ln()[i]));	
		this->l.push_back(std::stoi(this->get_ln()[i]));
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
	this->fill_double_l();

}

//************* Print Functions ***************//
// void pm::print_l(void)
// {
// 	for (std::list<int>::iterator it = this->get_l().begin(); it != this->get_l().end(); it++)
// 		std::cout << GREEN << *it << RESET << std::endl;
// }

// void pm::print_v(void)
// {
// 	for (size_t i = 0; i < this->get_v().size(); i++)
// 		std::cout << GREEN << this->get_v()[i] << " ";
// 	std::cout << RESET << std::endl;
// }

void pm::print_ln(void)
{
	for (size_t i = 0; i < this->get_ln().size(); i++)
		std::cout << YELLOW << this->get_ln()[i] << " ";
	std::cout << RESET << std::endl;
}

void pm::printBefor(void)
{
	std::cout << YELLOW << "Before (Vector): ";
	this->print_ln();
	std::cout << YELLOW << "Before   (List): ";
	this->print_ln();
}

void pm::printAfter(void)
{
	std::cout << GREEN << "After  (Vector): ";
	printVector(this->vs);
	std::cout << GREEN << "After    (List): ";
	printList(this->ls);
	std::cout << RESET << std::endl;
}

void pm::printTime(void)
{
	std::cout << YELLOW << 	"Time to proccess a range of " << this->size << " elements with std::vector : " << this->Vtime.count() << " us" << RESET << std::endl;
	std::cout << GREEN << "Time to proccess a range of " << this->size << " elements with std::List : " << this->Ltime.count() << " us" << RESET << std::endl;
}

//*************** Sort Functions **************//

// template <typename T>
// void pop_front(std::vector<T>& vec, int i) {
//     if (!vec.empty()  && i >= 0 && i < vec.size()) {
//         vec.erase(vec.begin());
//     }
// }

// void pm::merge(int l)
// {
// 	std::cout << "end of vector :"<< l << " "  << get_vs()[l][this->get_vs()[l].size() -1] << std::endl;
// 	if(this->get_vs()[l][this->get_vs()[l].size() - 1] < this->get_vs()[l + 1][this->get_vs()[l + 1].size() - 1])
// 	{
// 		unsigned long indexFrom = l + 1; // Assuming you want to merge from this index...
//     	unsigned long indexTo = l; // ...into this index.
//  	   if(indexFrom < this->get_vs().size() && indexTo < this->get_vs().size() && indexFrom != indexTo) {
//    	     this->get_vs()[indexTo].insert(this->get_vs()[indexTo].end(), this->get_vs()[indexFrom].begin(), this->get_vs()[indexFrom].end());
//  	       this->get_vs().erase(this->get_vs().begin() + indexFrom);
//   	  } else {
//    	     std::cout << "Invalid indices provided." << std::endl;
//       }
// 	}
// 	else
// 	{
// 		unsigned long indexFrom = l; // Assuming you want to merge from this index...
//     	unsigned long indexTo = l + 1; // ...into this index.

//  	   if(indexFrom < this->get_vs().size() && indexTo < this->get_vs().size() && indexFrom != indexTo) {
//    	     this->get_vs()[indexTo].insert(this->get_vs()[indexTo].end(), this->get_vs()[indexFrom].begin(), this->get_vs()[indexFrom].end());

//  	       this->get_vs().erase(this->get_vs().begin() + indexFrom);
//   	  } else {
//    	     std::cout << "Invalid indices provided." << std::endl;
//       }
// 	}
// 	std::cout << "l merge :" << l << std::endl;
// }

// void pm::print_vs(void)
// {
// 	std::cout << "size is " << this->get_vs().size() << std::endl;
// 	for(unsigned long i = 0; i < this->get_vs().size(); ++i) {
// 		std::cout << "indice " << i << std::endl;
// 		for(unsigned long j = 0; j < this->get_vs()[i].size(); ++j) {
// 			std::cout << this->get_vs()[i][j] << " ";
// 		}
// 		std::cout << std::endl;
// 	}
// }

// void pm::print_vs_main()
// {
// 	std::cout << GREE;
// 	for(unsigned long i = 0; i < this->get_vs_main().size(); ++i) {
// 		std::cout << "indice " << i << std::endl;
// 		for(unsigned long j = 0; j < this->get_vs_main()[i].size(); ++j) {
// 			std::cout << this->get_vs_main()[i][j] << " ";
// 		}
// 		std::cout << RESET << std::endl;
// 	}

// }

// void pm::print_vs_pend()
// {
// 	std::cout << YELLOW;
// 	for(unsigned long i = 0; i < this->get_vs_pend().size(); ++i) {
// 		std::cout << "indice " << i << std::endl;
// 		for(unsigned long j = 0; j < this->get_vs_pend()[i].size(); ++j) {
// 			std::cout << this->get_vs_pend()[i][j] << " ";
// 		}
// 		std::cout << RESET << std::endl;
// 	}
// }

void pm::fill_vs_pend()
{
	this->get_vs_pend().clear();
	for(unsigned long i = 2; i < this->get_vs().size() - 1 ; i+=2)           
		this->get_vs_pend().push_back(this->get_vs()[i]);
}

// void pm::split_mp()
// {
// 	std::cout << GREEN << "im in split" << RESET << std::endl;
// 	this->get_vs_main().clear();
// 	this->get_vs_main().push_back(this->get_vs()[0]);
// 	std::cout << BLUE << "get_vs  " << 0 << " " << this->get_vs()[0][this->get_vs()[0].size() - 1] << RESET << std::endl;
// 	this->get_vs_main().push_back(this->get_vs()[1]);
// 	std::cout << BLUE << "get_vs  " << 1 << " " << this->get_vs()[1][this->get_vs()[1].size() - 1] << RESET << std::endl;
// 	for(unsigned long i = 2; i < this->get_vs().size(); ++i)
// 	{
// 		if(i % 2 == 1)
// 			this->get_vs_main().push_back(this->get_vs()[i]);
// 		else
// 			this->get_vs_pend().push_back(this->get_vs()[i]);
// 		std::cout << BLUE << "get_vs  " << i << " " << this->get_vs()[i][this->get_vs()[i].size() - 1] << RESET << std::endl;
// 	}
// 	this->get_vs() = this->get_vs_main();
// 	this->get_vs().push_back(this->get_vs_pend()[0]);
// }

// void pm::generate_vs()
// {
// 	for(unsigned long i = 0; i < this->get_vs().size(); ++i)
// 		for(unsigned long j = 0; j < this->get_vs()[i].size(); ++j)
// 			get_v().push_back(this->get_vs()[i][j]);
// }

// void pm::handl_vs()
// {
// 	std::cout << GREEN << "******************** handl_vs " << this->limit << " " << RESET << std::endl;

//     for (int j = 0; j < this->limit - 1; j++)
//         for (int i = 0; i < (this->size/2); ++i)
//             merge(i);
//     this->limit--;
// }

// void pm::vstov()
// {
// 	std::vector<int>& tmp = this->get_v();
// 	tmp.clear();
// 	for(unsigned long i = 0; i < this->get_vs().size(); ++i)
// 		for(unsigned long j = 0; j < this->get_vs()[i].size(); ++j)
// 			tmp.push_back(this->get_vs()[i][j]);
// 	this->get_vs().clear();
// }

// void pm::baniry_sort()
// {
// 	std::vector<std::vector<int> >& m = this->get_vs_main();
// 	std::vector<std::vector<int> >& p = this->get_vs_pend();
// 	std::vector<std::vector<int> >& tmp = this->get_vs();
// 	tmp.clear();
// 	for(unsigned long i = 0; i < p.size(); ++i)
// 	{
// 		for(unsigned long j = 0; j < m.size(); ++j)
// 		{
// 			if(m[j][m[j].size() -1] > p[i][p[i].size() -1])
// 			{
// 				m.insert(m.begin() + j, p[i]);
// 				j++;
// 			}
			
// 		}
// 	}
// 	p.clear();
// 	tmp = m;
// }

void pm::printVector(const Vec &sequence) {
    for (Vec::const_iterator vec_it = sequence.begin(); vec_it != sequence.end(); ++vec_it) {
        for (MiniVec::const_iterator num_it = vec_it->begin(); num_it != vec_it->end(); ++num_it) {
            std::cout << *num_it << " ";
        }
    }
	std::cout << RESET << std::endl;
}

void pm::printList(const Lst &sequence) {
	for (Lst::const_iterator vec_it = sequence.begin(); vec_it != sequence.end(); ++vec_it) {
		for (MiniLst::const_iterator num_it = vec_it->begin(); num_it != vec_it->end(); ++num_it) {
			std::cout << *num_it << " ";
		}
	}
	std::cout << RESET << std::endl;
}

// void pm::Chaine_vs() {
// 	int i = 0;

// 	//! need to check this
//     for (Vec::iterator it = this->vs.begin(); it != this->vs.end(); ++it) {
// 		if(i % 2)
// 		{
// 			this->vs_main.push_back(*it);
//         } else {
// 			this->vs_pend.push_back(*it);
//         }
// 		i++;
//     }
// 	this->vs_odd.clear();
// }

// void pm::unpair_vs() {

// 	Vec& digits = this->vs;

// 	Vec newOne;

//     size_t size = digits[0].size() / 2;

//     for (size_t i = 0; i < digits.size(); ++i)
//     {
//         std::vector<int> vec1, vec2;
//         for (size_t j = 0; j < size; ++j)
//         {
//             vec1.push_back(digits[i][j]);
//             vec2.push_back(digits[i][j + size]);
//         }
//         newOne.push_back(vec1);
//         newOne.push_back(vec2);
//     }
//     digits = newOne;
//     newOne.clear();
// }

void pm::pair_vs() {
    Vec tmp;
    for (Vec::iterator it = this->vs.begin(); it != vs.end(); it += 2) {
        if (it + 1 != this->vs.end()) {
			MiniVec temp;
            if (*it > *(it + 1)) {
                temp = *it;
                *it = *(it + 1);
                *(it + 1) = temp;
            }
            MiniVec fvec;
            for (MiniVec::iterator it1 = it->begin(); it1 != it->end(); it1++)
                fvec.push_back(*it1);
            for (MiniVec::iterator it2 = (it + 1)->begin(); it2 != (it + 1)->end(); it2++)
                fvec.push_back(*it2);
            tmp.push_back(fvec);
            fvec.clear();
        } else {
            this->vs_odd.push_back(*it);
        }
    }
    this->vs = tmp;
    tmp.clear();
}

// bool pm::Compare(const std::vector<int> &a, const std::vector<int> &b)
// {
//     return a.back() <= b.back();
// }

// void pm::InsertPaid() {
// 	Vec& main = this->vs_main;
// 	Vec& Paind = this->vs_pend;

//     for ( Vec::const_iterator it = Paind.begin(); it != Paind.end(); ++it)
//     {
//         // Find the insertion point using lower_bound
//         Vec::iterator insertionPoint = std::lower_bound(main.begin(), main.end(), *it, Compare);

//         // Insert the vector at the insertion point
//         main.insert(insertionPoint, *it);
//     }
// }

void pairVector(Vec &digits, Vec &rest) {
    Vec tmp;
    for (Vec::iterator it = digits.begin(); it != digits.end(); it += 2) 
    {
        if (it + 1 != digits.end()) 
        { 
            if ((*it) > *(it + 1)) {
                std::vector<int> tmpVec = *it;
                *it = *(it + 1);
                *(it + 1) = tmpVec;
            }
            std::vector<int> oneVec;
            for (std::vector<int>::iterator one = it->begin(); one != it->end(); one++) {
                oneVec.push_back(*one);
            }
            for (std::vector<int>::iterator two = (it + 1)->begin(); two != (it + 1)->end(); two++) {
                oneVec.push_back(*two);
            }
            tmp.push_back(oneVec);
            oneVec.clear();
        } 
        else 
            rest.push_back(*it);
    } 
    digits = tmp;
    tmp.clear();
}

void unpairVector(Vec& digits)
{
    Vec newOne;

    size_t size = digits[0].size() / 2;

    for (size_t i = 0; i < digits.size(); ++i)
    {
        std::vector<int> vec1, vec2;
        for (size_t j = 0; j < size; ++j)
        {
            vec1.push_back(digits[i][j]);
            vec2.push_back(digits[i][j + size]);
        }
        newOne.push_back(vec1);
        newOne.push_back(vec2);
    }
    digits = newOne;
    newOne.clear();
}

    
void createChains(Vec &digits, Vec &main, Vec &pend, Vec &remain)
{
	pm a;
	
	std::cout << RESET;
    int index = 0;
    Vec::iterator it = digits.begin();
    while (it != digits.end())
    {
        if (index % 2 != 0)
            main.push_back(*it);
        else
            pend.push_back(*it);
        index++;
        it++;
    }
    
    Vec::iterator re = remain.begin();
    while(re != remain.end())
    {
        pend.push_back(*re);
        re++;
    }
}

bool Compare(const std::vector<int> &a, const std::vector<int> &b)
{
    return a.back() <= b.back();
}

void InsertPaindInMain(Vec &main, Vec &Paind)
{

    for (Vec::const_iterator it = Paind.begin(); it != Paind.end(); ++it)
    {
        // Find the insertion point using lower_bound
        Vec::iterator insertionPoint = std::lower_bound(main.begin(), main.end(), *it, Compare);

        // Insert the vector at the insertion point
        main.insert(insertionPoint, *it);
    }
}
static int i = 1;
void pm::sort_v(void)
{
	Vec& digits = this->vs;
    Vec pend;
    Vec mainChain;
    Vec rest;

    if (digits.size() == 1)
        return ;
    if (digits.size() % 2 != 0)
    {
        rest.push_back(digits.back());
        digits.pop_back();
    }
    pair_vs();
    std::cout << "After pair " << i++   << std::endl;
    printVector(digits);
    sort_v();
    std::cout << "After pair " << --i   << std::endl;
    printVector(digits);
    unpairVector(digits);
    std::cout << "After unpair digits " << i << std::endl;
    printVector(digits);
    createChains(digits, mainChain, pend, rest);
    std::cout << "After createChains main " << i << std::endl;
    printVector(mainChain);
    InsertPaindInMain(mainChain, pend);
    std::cout << "After InsertPaindInMain main " << i << std::endl;
    printVector(mainChain);
    // InsertPaid();
    digits = mainChain;
    mainChain.clear();
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
	this->sort_l();
	end = std::chrono::high_resolution_clock::now();
	this->Ltime = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
}