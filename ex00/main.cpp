/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaidriss <yaidriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 21:24:43 by yassine           #+#    #+#             */
/*   Updated: 2024/06/08 19:09:40 by yaidriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
    
    if (ac == 2)
    {
        bit bit;
        bit.input.open(av[1]);
        bit.data.open("./data.csv");
        bit.minData = INT_MAX;
        bit.maxData = 0;
        if(!bit.input.is_open() || !bit.data.is_open()) 
            return (printErr("Error: could not open file.",1));
        fillData(bit);
        fillInput(bit);
    }
    else
        return (printErr("Error: could not open file.",1));
    return 0;
}

