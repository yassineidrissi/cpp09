/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaidriss <yaidriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 21:25:25 by yassine           #+#    #+#             */
/*   Updated: 2024/03/02 19:33:27 by yaidriss         ###   ########.fr       */
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
	std::vector<std::string> c;
	double num;
}RPN;

//********* Colors *****************//
#define RED "\033[31m"
#define YELLOW "\033[33m"
#define GREEN "\033[32m"
#define RESET "\033[0m"

//************* print Functions ***********//



//************ Functions ******************//
std::vector<std::string> split(const std::string &s, char delimiter);
int check_v(std::vector<std::string>& c);
