/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaidriss <yaidriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 21:25:16 by yassine           #+#    #+#             */
/*   Updated: 2024/02/21 22:50:59 by yaidriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <sstream>

void bitcoinExchange(std::map<std::string, double>& bitcointExchange, std::string& line)
{
    std::istringstream ss(line);
    std::string date;
    __unused double value;
   (void) bitcointExchange;
  std::cout << bitcointExchange.
    // if(std::getline(ss, date, ',') && ss >> value)
    //     bitcointExchange[date] = value;
}

std::vector<std::string> split(const std::string &s, char delimiter) {
    std::vector<std::string> tokens;
    std::string token;
    std::istringstream tokenStream(s);
    while (std::getline(tokenStream, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}