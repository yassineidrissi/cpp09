/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaidriss <yaidriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 21:25:25 by yassine           #+#    #+#             */
/*   Updated: 2024/02/27 19:35:51 by yaidriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include <thread>
#include <ctime>
#include <fstream>
#include <cmath>

#define RED "\033[31m"
#define YELLOW "\033[33m"
#define GREEN "\033[32m"
#define RESET "\033[0m"

typedef struct bit_t {
	std::map<std::time_t, double> bitData;
	std::map<std::time_t, double> bitInput;
	std::ifstream input;
	std::ifstream data;
	time_t maxData;
	time_t minData;
	time_t closecttime;
	double value;
}bit;

int printErr(std::string str,int op);
void fillData(bit &b);
void fillInput(bit &b);
void printTime(time_t &tm);
// void fillInput(std::map<std::time_t, double> &bitInput, std::ifstream& input, std::ifstream& data);
std::vector<std::string> split(const std::string &s, char delimiter);