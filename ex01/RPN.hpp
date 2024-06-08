/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaidriss <yaidriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 21:25:25 by yassine           #+#    #+#             */
/*   Updated: 2024/06/08 21:38:40 by yaidriss         ###   ########.fr       */
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
	private:
		std::string name;
		std::deque<int> nm;
		std::deque<int> op;
		std::deque<std::string> ln;
	public:
		RPN();
		~RPN();
		RPN(const RPN &r);
		RPN &operator=(const RPN &r);
		std::deque<std::string> split(std::string &s, char delimiter) ;
		int check_v(std::vector<std::string>& c);
		int opert();
		std::string get_ln_str(int n);
		std::deque<std::string> get_ln();
		void set_ln(std::deque<std::string> ln);
		std::deque<int> get_op();
		void set_op(int op);
		std::deque<int> get_nm();
		void set_nm(int nm);
	    // int split(std::string &s, char delimiter);
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
