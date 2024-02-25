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
        std::cerr << RED << "Error: bad input => " << str << RESET << std::endl;
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
    std::cout << "Time: " << ss.str() << std::endl;
}

std::time_t convertToData(std::string str)
{
    std::tm tm;
    memset(&tm, 0, sizeof(std::tm)); // Initialize all fields to zero
    std::istringstream ss(str);
    ss >> std::get_time(&tm, "%Y-%m-%d");
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
        // time_t tm;
        // Skip the first line
        std::getline(b.data, line); // Skip the first line
        while(std::getline(b.data, line))
        {
            std::vector<std::string> splitLine = split(line, ',');
            // std::cout << line << std::endl;
            // std::cout << splitLine[1] << std::endl;
            // if (splitLine.size() == 2) 
            // {
                // tm = convertToData(splitLine[1]);
                std::time_t key = convertToData(splitLine[0]);
                try {
                    double value = std::stod(splitLine[1]);
                    b.bit[key] = value;
                    // std::cout << key << std::endl;
                    // std::cout << value << std::endl;
                    // std::this_thread::sleep_for(std::chrono::seconds(1)); // Add this line
                }//! im not sure if we need to catch here 
                catch (std::invalid_argument const &e) 
                {
                    std::cout << "Invalid argument: " << splitLine[1] << " is not a number.\n";
                } 
                catch (std::out_of_range const &e) 
                {
                    std::cout << "Out of range: " << splitLine[1] << " is too big.\n";
                }
            // }
        }
        data.close();
        // return bit;
}

void printTwoparam(std::vector<std::string> &splitLine)
{
        // double num = spl
        if (std::atof(splitLine[1].c_str()) >= 0)
        {
           std::cout << splitLine[0] << " " << splitLine[1] << std::endl;
        }
        else if(splitLine.size() == 2 && std::atof(splitLine[1].c_str()) < 0)
            std::cerr << RED <<"Error : not a postif number" << RESET << std::endl;
}

// std::map<std::time_t, double>
// void fillInput(std::map<std::time_t, double> &bitInput, std::ifstream& input, std::ifstream& data)
// {
//     std::string line;
//     (void) bitInput;
//     (void) data;
//     std::getline(input, line);//skip first line
//     while(std::getline(input, line))
//     {
        
//         std::vector<std::string> splitLine  = split(line, '|');
//         if (splitLine.size() == 2)
//             printTwoparam(splitLine);
//         else
//             std::cerr << "Error : not input =>  " << splitLine[0].c_str() << std::endl; 
//         // else if(splitLine.size() == 1)
//         //     std::cerr << "Error : bad input => " << splitLine[0].c_str() << std::endl;
//     }
//     // return bitInput;
// }

//     std::istringstream ss(line);
//     std::string date;
//     __unused double value;
//    (void) bitcointExchange;
//     // if(std::getline(ss, date, ',') && ss >> value)
//     //     bitcointExchange[date] = value;
// std::vector<std::string> *split(const std::string &s, char delimiter) {
//     std::vector<std::string> tokens;
//     std::string token;
//     std::istringstream tokenStream(s);
//     while (std::getline(tokenStream, token, delimiter)) {
//         tokens.push_back(token);
//     }
//     return &tokens;
// }