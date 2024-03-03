/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaidriss <yaidriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 22:52:43 by yaidriss          #+#    #+#             */
/*   Updated: 2024/03/02 19:40:15 by yaidriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

std::vector<std::string> split(const std::string &s, char delimiter) 
{
    std::vector<std::string> tokens;
    std::string token;
    std::istringstream tokenStream(s);
    while (std::getline(tokenStream, token, delimiter)) 
        tokens.push_back(token);
    return tokens;
}

int calculNumber(RPN& r)
{
    
}

int check_v(RPN& r)
{
    for (std::vector<std::string>::iterator it = r.c.begin(); it != r.c.end(); ++it)
        if (it->size() != 1 || (!std::isdigit((*it)[0]) && (*it)[0] != '-' && (*it)[0] != '*' && (*it)[0] != '+' && (*it)[0] != '/'))
            return calculNumber(r);
    return 1;
}