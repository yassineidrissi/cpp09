/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaidriss <yaidriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 21:25:16 by yassine           #+#    #+#             */
/*   Updated: 2024/02/14 19:47:36 by yaidriss         ###   ########.fr       */
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
    
    // if(std::getline(ss, date, ',') && ss >> value)
    //     bitcointExchange[date] = value;
    
}
