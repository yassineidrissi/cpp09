/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yassine <yassine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 21:25:16 by yassine           #+#    #+#             */
/*   Updated: 2024/01/31 16:51:52 by yassine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <sstream>

void bitcoinexchange(std::map<std::string, double>& bitcointExchange, std::string& line)
{
    std::istringstream ss(line);
    std::string date;
    double value;
    
    // if(std::getline(ss, date, ',') && ss >> value)
    //     bitcointExchange[date] = value;
    
}
