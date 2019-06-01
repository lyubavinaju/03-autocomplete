
#include "term.cpp"

class binary_search_deluxe {
private:
    binary_search_deluxe();

public:
    typedef std::function<bool(term
                               const &, term const &)>
            term_comparator;

    static int first_index_of(std::vector<term> terms, const term &key, term_comparator comparator);

    static int last_index_of(std::vector<term> terms, const term &key, term_comparator comparator);
};