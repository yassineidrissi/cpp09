/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaidriss <yaidriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 22:52:43 by yaidriss          #+#    #+#             */
/*   Updated: 2024/03/06 10:38:46 by yaidriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN()
{

};

RPN::~RPN()
{

};

RPN::RPN(const RPN &r)
{
    *this = r;
};

RPN &RPN::operator=(const RPN &r)
{
    this->name = r.name;
    this->nm = r.nm;
    this->op = r.op;
    this->ln = r.ln;
    return *this;
};



std::deque<std::string> RPN::split(std::string &s, char delimiter) 
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

// int RPN::operation()

int RPN::opert(RPN& r)
{
    if(r.nm.size() < 2)
    {
        printErreur(1);
        return 1;
    }

    int nm1 = 0;
    if (r.op[0] == '+')
        nm1 = r.nm[r.nm.size() -2] + r.nm[r.nm.size() -1];
    else if (r.op[0] == '-')
        nm1 = r.nm[r.nm.size() -2] - r.nm[r.nm.size() -1];
    else if (r.op[0] == '*')
        nm1 = r.nm[r.nm.size() -2] * r.nm[r.nm.size() -1];
    else if (r.op[0] == '/')
        nm1 = r.nm[r.nm.size() -2] / r.nm[r.nm.size() -1];
    r.op.pop_back();
    r.nm.pop_back();
    r.nm.pop_back();
    r.nm.push_back(nm1);
    return 0;
}