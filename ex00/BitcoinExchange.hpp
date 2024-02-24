/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaidriss <yaidriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 21:25:25 by yassine           #+#    #+#             */
/*   Updated: 2024/02/24 08:09:05 by yaidriss         ###   ########.fr       */
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
#include <ifstream>

std::map<std::time_t, double> fillData(std::map<std::time_t, double> bit, std::ifstream& data);
std::vector<std::string> split(const std::string &s, char delimiter);
std::map<std::time_t, double> fillInput(std::map<std::time_t, double> bitInput, std::ifstream& input);