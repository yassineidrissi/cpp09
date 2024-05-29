/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Tmain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaidriss <yaidriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 11:26:09 by yaidriss          #+#    #+#             */
/*   Updated: 2024/05/26 11:31:50 by yaidriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <list>
#include <iostream>
#include <algorithm>

template <typename Container>
class PmergeMe {
public:
    void addElement(const typename Container::value_type& element);
    void sort();
    void display() const;
private:
    Container elements;
    void mergeInsertSort(Container& container);
    void pairElements(Container& container, Container& paired, Container& unpaired);
    void mergePairs(Container& container, Container& paired);
    void insertUnpaired(Container& container, Container& unpaired);
};

#endif // PMERGEME_HPP

