#pragma once
#include <cstddef>
#include <cstring>
#include <memory>
#include <cstdlib>

namespace cstd {
 
template<class T>
class vector {
public:
    vector() {
        begin_ = (T*) malloc(sizeof(T) * default_size);
        tail_ = begin_;
        end_ = begin_ + default_size;
        size_ = default_size;
    }

    vector(size_t size) {
        begin_ = (T*) malloc(sizeof(T) * size);
        tail_ = begin_;
        end_ = begin_ + size;
        size_ = size;
    }

    ~vector() {
        free(begin_);
    }

    size_t size() {
        return tail_ - begin_;
    }

    size_t get_alloc_size() {
        return size_;
    }

    void push_back(const T& data) {
        *tail_ = data;
        tail_++;
        if (tail_ == end_) resize();
    }

    void resize() {
        size_t raw_size = size_;
        size_ <<= 1;
        T* new_begin_ = (T*) malloc(sizeof(T) * size_);
        memcpy(new_begin_, begin_, raw_size * sizeof(T));
        free(begin_);
        begin_ = new_begin_;
        tail_ = begin_ + raw_size;
        end_ = begin_ + size_;
    }

    T& operator[](size_t index) {
        return begin_[index];
    }


public:
    const size_t default_size = 10000;
private:
    size_t size_;
    T* begin_;
    T* tail_;
    T* end_;
};

}