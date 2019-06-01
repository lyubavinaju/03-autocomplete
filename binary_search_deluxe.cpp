
#include "binary_search_deluxe.hpp"

binary_search_deluxe::binary_search_deluxe() {};

int binary_search_deluxe::first_index_of(std::vector<term> terms, const term &key, term_comparator comparator) {
    auto lower_it = std::lower_bound(terms.begin(), terms.end(), key, std::move(comparator));
    int index = std::distance(terms.begin(), lower_it);
    return index;
}

int binary_search_deluxe::last_index_of(std::vector<term> terms, const term &key, term_comparator comparator) {
    auto upper_it = std::upper_bound(terms.begin(), terms.end(), key, std::move(comparator));
    int index = std::distance(terms.begin(), upper_it) - 1;
    return index;
}