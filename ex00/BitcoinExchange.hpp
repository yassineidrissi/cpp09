/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaidriss <yaidriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 21:25:25 by yassine           #+#    #+#             */
/*   Updated: 2024/02/25 09:22:41 by yaidriss         ###   ########.fr       */
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

#define RED "\033[31m"
#define YELLOW "\033[33m"
#define GREEN "\033[32m"
#define RESET "\033[0m"

typedef struct bit_t {
	std::map<std::time_t, double> bigData;
	std::map<std::time_t, double> bitInput;
	std::ifstream input;
	std::ifstream data;
	double maxData;
	double minData;
}bit;

int printErr(std::string str,int op);
void fillData(std::map<std::time_t, double>& bit, std::ifstream& data);
void fillInput(std::map<std::time_t, double> &bitInput, std::ifstream& input, std::ifstream& data);
std::vector<std::string> split(const std::string &s, char delimiter);