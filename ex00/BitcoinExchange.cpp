/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaidriss <yaidriss@student.42.fr>          +#+  +:+       +#+        */
/*                                               +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 21:25:16 by yassine           #+#    #+#             */
/*   Updated: 2024/02/24 08:10:35 by yaidriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int printErr(std::string st,int op)
{
    const char *str = st.c_str();
    if (op == 1)
        std::cerr << RED << str << RESET << std::endl;
    else if (op == 2)
        std::cerr << RED << "Error: bad input => " << RESET << str << std::endl;
    else if(op == 3)
        std::cerr << RED << "Error: not a positive number." << RESET << std::endl;
    else
        std::cerr << RED << "Error: too large a number." << RESET << std::endl;
    return 1;
}

void printTime(time_t &tm)
{
    std::tm* tm_ptr = std::localtime(&tm);
    std::stringstream ss;
    ss << std::put_time(tm_ptr, "%Y-%m-%d");
    std::cout << ss.str();
}

std::time_t stot(std::string str)
{
    std::tm tm;
    memset(&tm, 0, sizeof(std::tm)); // Initialize all fields to zero
    std::istringstream ss(str);
    ss >> std::get_time(&tm,  "%Y-%m-%d");
    return std::mktime(&tm);
}

std::vector<std::string> split(const std::string &s, char delimiter) 
{
    std::vector<std::string> tokens;
    std::string token;
    std::istringstream tokenStream(s);
    while (std::getline(tokenStream, token, delimiter)) 
        tokens.push_back(token);
    return tokens;
}

void fillData(bit &b)
{
        std::string line;
        std::getline(b.data, line); // Skip the first line
        while(std::getline(b.data, line))
        {
            std::vector<std::string> splitLine = split(line, ',');
            std::time_t key = stot(splitLine[0]);
            try {
                double value = std::stod(splitLine[1]);
                b.bitData[key] = value;
                if(key > b.maxData)
                    b.maxData = key;
                if(key < b.minData)
                    b.minData = key;
                b.bitData[key] = value; // insert new data into b.data
            }//! im not sure if we need to catch here 
            catch (std::invalid_argument const &e) 
            {
                std::cout << "Invalid argument: " << splitLine[1] << " is not a number.\n";
            } 
            catch (std::out_of_range const &e) 
            {
                std::cout << "Out of range: " << splitLine[1] << " is too big.\n";
            }
        }
        b.data.close();
}

std::time_t findClosestTime(bit& b, std::time_t inputTime) {
    std::time_t closestTime = 0; // Initialize to an invalid value
    for (std::map<std::time_t, double>::const_iterator it = b.bitData.begin(); it != b.bitData.end(); ++it) 
    {
        if (it->first > inputTime)
            break;
        closestTime = it->first;
    }
    return closestTime;
}

void printTwoparam(bit& b,time_t t, double value)
{
    printTime(t);
    (void) b;
    std::cout << GREEN << " => " << RESET << value << GREEN << " = " << RESET;
    b.closecttime = findClosestTime(b, t); 
    std::cout << YELLOW << value*b.bitData[b.closecttime] << RESET;
    std::cout << RESET << std::endl;
}

int checkLine(std::string l)
{
    if (l.size() != 11 || l[4] != '-' ||  l[7] != '-' || l[10] != ' ')
        return 0;
    for(int i = 0; i < 10; i++)
        if (i != 4 && i != 7 && !isnumber(l[i]))
            return(0);
    return (1);
}

void fillInput(bit &b)
{
    std::string line;
    std::getline(b.input, line);//skip first line
    if(std::strcmp(line.c_str(), "date | value") != 0)
        std::cerr << RED <<"bad Header" << RESET << std::endl;
    while(std::getline(b.input, line))
    {
        std::vector<std::string> splitLine  = split(line, '|');
        std::time_t key = stot(splitLine[0]);
        if(atof(splitLine[1].c_str()) < 0)
            printErr(splitLine[1], 3);
        else if (atof(splitLine[1].c_str()) > INT_MAX)
            printErr(splitLine[1], 4);
        else if (splitLine.size() == 2 && checkLine(splitLine[0]) && key < b.maxData && key > b.minData)
            printTwoparam(b, key, atof(splitLine[1].c_str()));
        else
            printErr(splitLine[0], 2);
    }
}
