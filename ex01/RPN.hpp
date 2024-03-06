/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaidriss <yaidriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 21:25:25 by yassine           #+#    #+#             */
/*   Updated: 2024/03/06 12:41:03 by yaidriss         ###   ########.fr       */
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

class RPN
{
//! check if we need to add variables to private part
	public:
		std::string name;
		std::deque<int> nm;
		std::deque<int> op;
		std::deque<std::string> ln;
		RPN();
		~RPN();
		RPN(const RPN &r);
		RPN &operator=(const RPN &r);
		std::deque<std::string> split(std::string &s, char delimiter) ;
		int check_v(std::vector<std::string>& c);
		int opert(RPN& r);
};

class RPNException : public std::exception
{
	public:
		virtual const char* what() const throw()
		{
			return "Error";
		}
};

//********* Colors *****************//
#define RED "\033[31m"
#define YELLOW "\033[33m"
#define GREEN "\033[32m"
#define RESET "\033[0m"
