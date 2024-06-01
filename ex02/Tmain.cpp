#include "PmergeMe.hpp"
#include <iostream>
#include <cstdlib>

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <numbers>" << std::endl;
        return 1;
    }

    pm pmerge;
    for (int i = 1; i < argc; ++i) {
        pmerge.add_to_ls(std::stoi(argv[i]));
    }

    std::cout << "Before sort_l, ls size: " << pmerge.get_ls().size() << std::endl;
    pmerge.sort_l();
    std::cout << "After sort_l, ls size: " << pmerge.get_ls().size() << std::endl;

    const Lst& sorted_ls = pmerge.get_ls();
    for (Lst::const_iterator it = sorted_ls.begin(); it != sorted_ls.end(); ++it) {
        const MiniLst& lst = *it;
        for (MiniLst::const_iterator elem_it = lst.begin(); elem_it != lst.end(); ++elem_it) {
            std::cout << *elem_it << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
