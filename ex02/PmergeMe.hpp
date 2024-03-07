/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaidriss <yaidriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 13:29:46 by yaidriss          #+#    #+#             */
/*   Updated: 2024/03/07 19:57:36 by yaidriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <map>
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
		int size;
		std::vector<std::string> ln;
		std::vector<int> v;
		std::list<int>   l;
	public:
		pm();
		~pm();
		pm(pm const &p);
		pm &operator=(pm const &p);
		void parcing();
        std::vector<std::string> get_ln();
		void set_ln(std::vector<std::string> ln);
		std::vector<int> get_v();
		void set_v(std::vector<int> v);
		std::list<int> get_l();
		void set_l(std::list<int> l);
};

//********* Colors *****************//
#define RED "\033[31m"
#define YELLOW "\033[33m"
#define GREEN "\033[32m"
#define RESET "\033[0m"

//************* print Functions ***********//



//************ Functions ******************//