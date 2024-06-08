/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaidriss <yaidriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 13:29:46 by yaidriss          #+#    #+#             */
/*   Updated: 2024/06/08 17:57:54 by yaidriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <chrono>
#include <list>
#include <string>
#include <fstream>
#include <sstream>
#include <ctime>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm> // Include this at the top of your file
#include <thread>
#include <unistd.h>

//********* Colors *****************//
#define RED "\033[31m"
#define YELLOW "\033[33m"
#define GREEN "\033[32m"
#define BLUE "\033[33m"
#define RESET "\033[0m"
#define GREE "\033[33m"

typedef std::vector<std::vector<int> > Vec;
typedef std::vector<int> MiniVec;
typedef std::list<std::list<int> > Lst;
typedef std::list<int> MiniLst;
typedef Vec vecVec;
class pm
{
	private:
		int size;
		std::vector<std::string> ln;
		std::vector<int> v;
		std::vector<std::vector<int> > vs;
		std::list<int> l;
		Lst ls;
		Lst l_odd;
		Lst l_main;
		std::vector<std::vector<int> > vs_main;
		std::vector<std::vector<int> > vs_pend;
		Vec vs_odd;
		std::chrono::microseconds Vtime;
		std::chrono::microseconds Ltime;

	public:
		static bool Compare(const std::vector<int>& a, const std::vector<int>& b);
		void Chaine_vs(void);
		void chaine_l(Lst& d, Lst& main, Lst& pend, Lst& rest);
		void InsertPaid(void);
		//***** Orthodox Methodes *********//
		pm();
		~pm();
		pm(pm const &p);
		pm &operator=(pm const &p);
		
		//******** seters and getters ****//
        std::vector<std::string>& get_ln();
		void set_ln(std::string l);
		void set_size(int size);
		std::vector<int>& get_v();
		Lst& get_ls();
		void set_v(int v);
		std::list<int>& get_l();
		void set_l(int l);
		Vec& get_vs_odd();
		std::vector<std::vector<int> >& get_vs();
		std::vector<std::vector<int> >& get_vs_main();
		std::vector<std::vector<int> >& get_vs_pend();
		
		//******** Functions *************//	
		void fill(void);
		void parcing(char **av);
		void fill_double_v(void);
		void fill_double_l(void);
		void fill_vs_pend();
		void vstov();
		

		//******* Print Functions ********//
		void print_ln(void);
		void print_v(void);
		void printBefor(void);
		void printAfter(void);
		void printTime(void);
		void print_vs(void);

		//******* Sort Functions ********//
		void sort(void);
		void sort_v(void);
		void sort_l(void);
		void pair_l(void);
		void chain(Lst& d, Lst& main, Lst& pend, Lst& rest);
		void pair_vs(void);
		void unpair_vs(void);
		void sort_vs(Vec& digits);
		void printVector(const Vec&);	
		void printList(const Lst &sequence);
		///******* Exeception ************//
		class pmException : public std::exception
		{
				public:
				virtual const char* what() const throw()
				{
					return "Error";
				}
		};
};


//************* print Functions ***********//
