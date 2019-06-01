
#include "term.hpp"

term::term()
        : word(), weight(0) {}

term::term(std::string _word, int _weight) :
        word(std::move(_word)), weight(_weight) {
}

term &term::operator=(const term &other) {
    // проверка на самоприсваивание
    if (this == &other)
        return *this;

// выполняем копирование значений
    word = other.word;
    weight = other.weight;

// возвращаем текущий объект
    return *this;
}

term::term(term &&copy)
        : word(copy.word), weight(copy.weight) {}

term::term(const term &copy)
        : word(copy.word), weight(copy.weight) {}


int term::get_weight() {
    return this->weight;
}

std::string term::get_word() {
    return this->word;
}

std::string term::to_string() const {
    std::stringstream ss;
    ss << weight << " " << word;
    return ss.str();
};

struct term::reverse_weight_order_functor {
    bool operator()(term const &t1, term const &t2) {
        return t1.weight > t2.weight;
    }
};

struct term::prefix_order_functor {
    int prefix_length;

    prefix_order_functor(int _prefix_length = -1)
            : prefix_length(_prefix_length) {}

    // возвращает <
    bool operator()(term const &t1, term const &t2) {
        int len1 = t1.word.length();
        int len2 = t2.word.length();

        int len = std::min(len1, len2);
        if (prefix_length != -1) {
            len = std::min(len, prefix_length);
        }

        for (int index = 0; index < len; ++index) {
            if (t1.word[index] < t2.word[index]) return true;
            if (t1.word[index] > t2.word[index]) return false;
        }

        if (prefix_length == -1) return len1 < len2;

        return false;
    }
};

term::reverse_weight_order_functor term::by_reverse_weight_order() {
    return {};
}

term::prefix_order_functor term::by_prefix_order(int prefix_length = -1) {
    return {prefix_length};
}

bool operator==(const term &t1, const term &t2) {
    return (t1.word == t2.word &&
            t1.weight == t2.weight);
}

bool operator!=(const term &t1, const term &t2) {
    return !(t1 == t2);
}

std::ostream &operator<<(std::ostream &out, const term &t) {

    out << t.to_string();
    return out;
}



