/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yassine <yassine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 21:25:25 by yassine           #+#    #+#             */
/*   Updated: 2024/04/23 00:24:45 by yassine          ###   ########.fr       */
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

#define RED "\033[31m"
#define YELLOW "\033[33m"
#define GREEN "\033[32m"
#define RESET "\033[0m"

// typedef struct bit_t {
// 	std::map<std::time_t, double> bitData;
// 	std::map<std::time_t, double> bitInput;
// 	std::ifstream input;
// 	std::ifstream data;
// 	time_t maxData;
// 	time_t minData;
// 	time_t closecttime;
// 	double value;
// }bit;

class bit
{
	public:
		std::map<std::time_t, double>bitData;
		std::map<std::time_t, double> bitInput;
		std::ifstream input;
		std::ifstream data;
		time_t maxData;
		time_t minData;
		time_t closecttime;
		double value;
};

//************* print Functions ***********//
int printErr(std::string str,int op);
void printTime(time_t &tm);

void fillData(bit &b);
void fillInput(bit &b);
void printTime(time_t &tm);
// void fillInput(std::map<std::time_t, double> &bitInput, std::ifstream& input, std::ifstream& data);
std::map<int, std::string> split(const std::string &s, char delimiter);