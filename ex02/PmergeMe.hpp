/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaidriss <yaidriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 13:29:46 by yaidriss          #+#    #+#             */
/*   Updated: 2024/03/08 18:39:23 by yaidriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <list>
#include <string>
#include <fstream>
#include <sstream>
#include <ctime>
#include <cmath>
#include <vector>
#include <string>

class pm
{
	private:
		// int size;
		std::vector<std::string> ln;
		std::vector<int> v;
		std::list<int> l;
	public:
		//***** Orthodox Methodes *********//
		pm();
		~pm();
		pm(pm const &p);
		pm &operator=(pm const &p);
		//******** seters and getters ****//
        std::vector<std::string> get_ln();
		void set_ln(std::string l);
		std::vector<int> get_v();
		void set_v(int v);
		std::list<int> get_l();
		void set_l(int l);
		//******** Functions *************//	
		void split(void);
		void parcing(char **av);
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
#define RESET "\033[0m"

//************* print Functions ***********//
