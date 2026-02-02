#pragma once
#include "vector.hpp"
#include <cstddef>

namespace cstd {

template<class T>
class stack {
public:
    stack() : s_() {}
    ~stack() {}

    void push(const T& data) {
        s_.push_back(data);
    }

    void pop() {
        s_.pop_back();
    }

    T& top() {
        return *(s_.end() - 1);
    }

    bool empty() {
        return s_.size() == 0;
    }

    size_t size() {
        return s_.size();
    }

private:
    vector<T> s_;
};

}