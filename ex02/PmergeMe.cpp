/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaidriss <yaidriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 13:29:52 by yaidriss          #+#    #+#             */
/*   Updated: 2024/03/05 00:01:26 by yaidriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

std::vector<std::string> split(const std::string &s, char delimiter) 
{
	std::vector<std::string> lines;
	std::string ln;
	std::istringstream tokenStream(s);
	while (std::getline(tokenStream, ln, delimiter)) 
		lines.push_back(ln);
	return lines;
}