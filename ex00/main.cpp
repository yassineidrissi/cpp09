/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaidriss <yaidriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 21:24:43 by yassine           #+#    #+#             */
/*   Updated: 2024/02/21 22:53:13 by yaidriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
    std::map<std::string, double> bitcointExchange;
    if (ac == 2)
    {
        std::ifstream data(av[1]);
        if(!data.is_open())
        {
            std::cout << "Could not open file " << std::endl;
            return 1;
        }
        std::string line = ;
        while(doubleline)
        {
            doubeline =    
            bitcoinExcange(bitcointExchange, line);
            //std::cout << line << std::endl;
            
        }
        data.close();
    }
    else
        std::cout << "Invalid arguments : Add data file in parametre" << std::endl;
}
    // std::map<std::string, double> bitcointExchange;
    // bitcointExchange["2023-01-01"] = 50000.0;
    // bitcointExchange["2023-01-02"] = 55000.0;

    // std::string test = "2023-01-03";
    // // if (bitcointExchange.find(test) != bitcointExchange.end())
    // //     std::cout << test << " exist " << std::endl;
    // // else
    // //     std::cout << test << " not exist " << std::endl;
    // double value = 5500;
    // for(std::map<std::string, double>::iterator it = bitcointExchange.begin(); it != bitcointExchange.end(); ++it)
    // {
    //     // if(it->second == value)
    //         // break;
    //     if (it->second == value)
    //     {
    //         std::cout << value << " exist " << std::endl;
    //         return 0;
    //     }
    // }
    // std::cout << value << " not exit " << std::endl;