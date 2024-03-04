/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaidriss <yaidriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 21:25:25 by yassine           #+#    #+#             */
/*   Updated: 2024/03/04 22:20:31 by yaidriss         ###   ########.fr       */
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

typedef struct RPN_t
{
	std::string name;
	std::deque<int> nm;
	std::deque<int> op;
	std::deque<std::string> ln;
}RPN;

//********* Colors *****************//
#define RED "\033[31m"
#define YELLOW "\033[33m"
#define GREEN "\033[32m"
#define RESET "\033[0m"

//************* print Functions ***********//



//************ Functions ******************//
std::deque<std::string> split(const std::string &s, char delimiter) ;
int check_v(std::vector<std::string>& c);
int printErreur(int i);
int operation(RPN_t& r);