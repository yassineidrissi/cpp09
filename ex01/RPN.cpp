/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaidriss <yaidriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 22:52:43 by yaidriss          #+#    #+#             */
/*   Updated: 2024/03/07 18:44:05 by yaidriss         ###   ########.fr       */
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

std::deque<std::string> RPN::get_ln()
{
    return this->ln;
};

void RPN::set_ln(std::deque<std::string> ln)
{
    this->ln = ln;
};

std::deque<int> RPN::get_op()
{
	return this->op;
};

void RPN::set_op(int op)
{
	this->op.push_back(op);
};

std::deque<int> RPN::get_nm()
{
	return this->nm;
};

void RPN::set_nm(int nm)
{
	this->nm.push_back(nm);
}

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

int RPN::opert(void)
{
    if(this->get_nm().size() < 2)
        // throw RPNException();
	std::cout << "opert : " << this->get_nm()[0] << std::endl;
    int nm1 = 0;
    if (this->op[0] == '+')
        nm1 = this->nm[this->nm.size() -2] + this->nm[this->nm.size() -1];
    else if (this->op[0] == '-')
        nm1 = this->nm[this->nm.size() -2] - this->nm[this->nm.size() -1];
    else if (this->op[0] == '*')
        nm1 = this->nm[this->nm.size() -2] * this->nm[this->nm.size() -1];
    else if (this->op[0] == '/')
        nm1 = this->nm[this->nm.size() -2] / this->nm[this->nm.size() -1];
    this->op.pop_back();
    this->nm.pop_back();
    this->nm.pop_back();
    this->nm.push_back(nm1);
    return 0;
}