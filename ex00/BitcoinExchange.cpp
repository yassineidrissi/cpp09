/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaidriss <yaidriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 21:25:16 by yassine           #+#    #+#             */
/*   Updated: 2024/02/24 04:23:14 by yaidriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

std::time_t convertToData(std::string str)
{
    std::tm = tm = {};
    std::isstringstream ss(str);
    ss >> std::get_time(&tm. "%Y-%m-%d");
    return std::mkdtime(&tm);
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

std::map<std::string, double> fillData(std::map<std::string, double> bit, std::ifstream& data)
{
        std::string line;
        // Skip the first line
        std::getline(data, line);
        while(std::getline(data, line))
        {
            std::vector<std::string> splitLine = split(line, ',');
            std::cout << line << std::endl;
            // std::cout << splitLine[1] << std::endl;
            if (splitLine.size() == 2) 
            {
                std::string key = splitLine[0];
                try {
                    double value = std::stod(splitLine[1]);
                    bit[key] = value;
                    std::cout << key << std::endl;
                    std::cout << value << std::endl;
                    std::this_thread::sleep_for(std::chrono::seconds(1)); // Add this line
                } catch (std::invalid_argument const &e) {
                    std::cout << "Invalid argument: " << splitLine[1] << " is not a number.\n";
                } catch (std::out_of_range const &e) {
                    std::cout << "Out of range: " << splitLine[1] << " is too big.\n";
                }
            }
        }
        data.close();
        return bit;
}
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