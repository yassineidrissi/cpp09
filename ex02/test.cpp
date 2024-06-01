#include "PmergeMe.hpp"
#include <algorithm>  // For std::lower_bound
#include <iterator>   // For std::next

static bool Compare_l(const MiniLst& a, const MiniLst& b) {
    return a.size() < b.size();
}

void pm::pair_l(void) {
    Lst tmp;
    for (Lst::iterator it = this->ls.begin(); it != this->ls.end(); std::advance(it, 2)) {
        if (std::next(it) != this->ls.end()) {
            if (*it > *std::next(it)) {
                std::swap(*it, *std::next(it));
            }
            MiniLst flst;
            flst.insert(flst.end(), it->begin(), it->end());
            flst.insert(flst.end(), std::next(it)->begin(), std::next(it)->end());
            tmp.push_back(flst);
        } else {
            this->l_odd.push_back(*it);
        }
    }
    this->ls = tmp;
}

void pm::chaine_l(Lst& d, Lst& main, Lst& pend, Lst& rest) {
    Lst newOne;

    size_t size = d.front().size() / 2;
    for (Lst::iterator digitList = d.begin(); digitList != d.end(); ++digitList) {
        MiniLst list1, list2;
        MiniLst::iterator it = digitList->begin();
        for (size_t j = 0; j < size; ++j) {
            list1.push_back(*it);
            ++it;
        }
        for (size_t j = 0; j < size; ++j) {
            list2.push_back(*it);
            ++it;
        }
        newOne.push_back(list1);
        newOne.push_back(list2);
    }
    d = newOne;

    int index = 0;
    for (Lst::iterator it = d.begin(); it != d.end(); ++it, ++index) {
        if (index % 2 == 0) {
            main.push_back(*it);
        } else {
            pend.push_back(*it);
        }
    }

    for (Lst::iterator re = rest.begin(); re != rest.end(); ++re) {
        pend.push_back(*re);
    }

    for (Lst::iterator it = pend.begin(); it != pend.end(); ++it) {
        Lst::iterator it1 = std::lower_bound(main.begin(), main.end(), *it, Compare_l);
        main.insert(it1, *it);
    }
}

void pm::sort_l(void) {
    Lst& d = this->ls;
    Lst pend;
    Lst main;
    Lst rest;

    if (d.size() == 1) return;

    if (d.size() % 2 != 0) {
        rest.push_back(d.back());
        d.pop_back();
    }

    pair_l();
    if (this->ls.size() == 1) return; // Ensure we stop recursion when there's only one pair left
    sort_l();
    chaine_l(d, main, pend, rest);
    this->ls = main;
}
