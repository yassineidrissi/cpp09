/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yassine <yassine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 21:24:43 by yassine           #+#    #+#             */
/*   Updated: 2024/01/30 15:39:23 by yassine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main()
{
    std::map<std::string, double> bitcointExchange;
    bitcointExchange["2023-01-01"] = 50000.0;
    bitcointExchange["2023-01-02"] = 55000.0;

    std::string test = "2023-01-03";
    // if (bitcointExchange.find(test) != bitcointExchange.end())
    //     std::cout << test << " exist " << std::endl;
    // else
    //     std::cout << test << " not exist " << std::endl;
    double value = 5500;
    for(std::map<std::string, double>::iterator it = bitcointExchange.begin(); it != bitcointExchange.end(); ++it)
    {
        // if(it->second == value)
            // break;
        if (it->second == value)
        {
            std::cout << value << " exist " << std::endl;
            return 0;
        }
    }
    std::cout << value << " not exit " << std::endl;
}