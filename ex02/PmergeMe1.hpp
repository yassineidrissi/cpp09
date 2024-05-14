/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe1.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaidriss <yaidriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 13:29:46 by yaidriss          #+#    #+#             */
/*   Updated: 2024/05/14 20:13:30 by yaidriss         ###   ########.fr       */
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

class pm
{
	private:
		int size;
		std::vector<std::string> ln;
		std::vector<int> v;
		std::vector<std::vector<int> > vs;
		std::list<int> l;
		std::vector<std::vector<int> > vs_main;
		std::vector<std::vector<int> > vs_pend;
		std::vector<int> vs_odd;
		std::chrono::microseconds Vtime;
		std::chrono::microseconds Ltime;
	public:
		int limit;
		//***** Orthodox Methodes *********//
		pm();
		~pm();
		pm(pm const &p);
		pm &operator=(pm const &p);
		
		//******** seters and getters ****//
        std::vector<std::string>& get_ln();
		void set_ln(std::string l);
		std::vector<int>& get_v();
		void set_v(int v);
		std::list<int>& get_l();
		void set_l(int l);
		std::vector<std::vector<int> >& get_vs();
		std::vector<std::vector<int> >& get_vs_main();
		std::vector<std::vector<int> >& get_vs_pend();
		
		//******** Functions *************//	
		void fill(void);
		void split(void);
		void parcing(char **av);
		void fill_double_v(void);
		void fill_vs_main();
		void fill_vs_pend();
		void fill_vs_odd();
		void fill_final();
		void generate_vs();;
		void vstov();
		void odd_insert();
		
		//******* Print Functions ********//
		void print_l(void);
		void print_ln(void);
		void print_v(void);
		void printBefor(void);
		void printAfter(void);
		void printTime(void);
		void print_vs(void);
		void print_vs_main();
		void print_vs_pend();
		void print_vs_odd();

		//******* Sort Functions ********//
		void sort(void);
		void sort_v(void);
		void sort_l(void);
		void merge(int l);
		void baniry_sort();
		void split_mp();
		void handl_vs();
		void pair_vs();
		void sort_vs();
		std::vector<int>& get_vs_odd();
		
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

//********* Colors *****************//
#define RED "\033[31m"
#define YELLOW "\033[33m"
#define GREEN "\033[32m"
#define BLUE "\033[33m"
#define RESET "\033[0m"
#define GREE "\033[33m"

//************* print Functions ***********//
