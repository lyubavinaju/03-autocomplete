
#include <string>
#include <iostream>
#include <sstream>
#include <vector>


class term {
private:
    std::string word;
    int weight;
    struct reverse_weight_order_functor;
    struct prefix_order_functor;


public:
    term();

    term(std::string _word, int _weight);

    term &operator=(const term &other);

    term(term &&copy);

    term(const term &copy);

    friend bool operator==(const term &t1, const term &t2);

    friend bool operator!=(const term &t1, const term &t2);

    friend std::ostream &operator<<(std::ostream &out, const term &t);

    std::string to_string() const;

    static reverse_weight_order_functor by_reverse_weight_order();

    static prefix_order_functor by_prefix_order(int prefix_length);

    int get_weight();

    std::string get_word();
};