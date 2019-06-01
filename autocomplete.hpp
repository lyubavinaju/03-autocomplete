
#include "binary_search_deluxe.cpp"


class autocomplete {
private:
    std::vector<term> terms;

    std::pair<int, int> find_first_and_last_index(const std::string &prefix);

public:
    autocomplete(std::vector<term> _terms);

    void print();

    void print(const std::vector<term> &matches);

    std::vector<term> all_matches(const std::string &prefix);

    int number_of_matches(const std::string &prefix);
};