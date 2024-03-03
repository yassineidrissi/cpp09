/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaidriss <yaidriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 22:52:43 by yaidriss          #+#    #+#             */
/*   Updated: 2024/03/03 11:48:15 by yaidriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

std::deque<std::string> split(const std::string &s, char delimiter) 
{
    std::deque<std::string> lines;
    std::string ln;
    std::istringstream tokenStream(s);
    while (std::getline(tokenStream, ln, delimiter)) 
        lines.push_back(ln);
    return lines;
}

int printErreur(int i)
{
    if (i == 1)
        std::cerr << RED << "Error" << RESET << std::endl;
    else if (i == 2)
        std::cerr << RED << "Error" << RESET << std::endl;
    return 1;

}

void operation(RPN_t& r)
{
    double n = static_cast<double>(r.nm[0]);
    for (size_t i = 0; i < r.op.size(); i++)
    {
        if(r.op[i] == '+')
            n += static_cast<double>(r.nm[i + 1]);
        else if(r.op[i] == '-')
            n -= static_cast<double>(r.nm[i + 1]);
        else if(r.op[i] == '*')
            n *= static_cast<double>(r.nm[i + 1]);
        else if(r.op[i] == '/')
            n /= static_cast<double>(r.nm[i + 1]);
    }
    std::cout << n << std::endl;
}
// int calculNumber(RPN& r)
// {
    
// }

// int check_v(RPN& r)
// {
//     for (std::deque<int>::iterator it = r.c.begin(); it != r.c.end(); ++it)
//         if (it->size() != 1 || (!std::isdigit((*it)[0]) && (*it)[0] != '-' && (*it)[0] != '*' && (*it)[0] != '+' && (*it)[0] != '/'))
//             return calculNumber(r);
//     return 1;
// }