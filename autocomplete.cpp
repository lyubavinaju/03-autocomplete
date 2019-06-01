#include "autocomplete.hpp"

autocomplete::autocomplete(std::vector<term> _terms)
        : terms(std::move(_terms)) {
    std::sort(terms.begin(), terms.end(), term::by_prefix_order());
};

std::pair<int, int> autocomplete::find_first_and_last_index(const std::string &prefix) {
    int first = binary_search_deluxe::first_index_of(terms, term(prefix, 0), term::by_prefix_order());
    int last = binary_search_deluxe::last_index_of(terms, term(prefix, 0), term::by_prefix_order(prefix.length()));
    return std::make_pair(first, last);
}

void autocomplete::print() {
    for (const term &T: terms) {
        std::cout << "\n" << T;
    }
}

void autocomplete::print(const std::vector<term> &matches) {
    for (const term &T: matches) {
        std::cout << "\n" << T;
    }
}

std::vector<term> autocomplete::all_matches(const std::string &prefix) {
    auto indexes = find_first_and_last_index(prefix);
    std::vector<term> matches;
    for (int index = indexes.first; index <= indexes.second; ++index) {
        matches.push_back(terms[index]);
    }
    std::sort(matches.begin(), matches.end(), term::by_reverse_weight_order());

    return matches;
}

int autocomplete::number_of_matches(const std::string &prefix) {
    auto indexes = find_first_and_last_index(prefix);
    int first = indexes.first;
    int last = indexes.second;
    return last - first + 1;
}

int main() {
    term T("asbd", 10);
    term T1("aaa", 70);
    term T2("asbd", 10);
    std::cout << T.get_word() << " " << T.get_weight() << std::endl;
    std::cout << (T1 == T2) << " " << (T != T2) << std::endl;
    std::cout << T1.to_string() << std::endl;
    std::cout << T << std::endl;
    std::cout << term::by_reverse_weight_order()(T2, T1) << std::endl;
    std::cout << term::by_prefix_order()(T1, T2);
    std::vector<term> terms;
    terms.emplace_back("***** краб", 40);
    terms.emplace_back("где поесть", 20);
    terms.emplace_back("где логика", 10);
    terms.emplace_back("скачать бесплатно без смс", 50);
    terms.emplace_back("где посылка", 30);
    autocomplete a(terms);
    a.print();
    std::cout << "\n" << a.number_of_matches("где");
    a.print(a.all_matches("где"));
    return 0;
}
