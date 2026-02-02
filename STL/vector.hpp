#pragma once
#include <cstddef>
#include <cstring>
#include <memory>
#include <cstdlib>

namespace cstd {
 
template<class T>
class vector {
private:
    class vector_iterator {
    private:
        T* ptr_;
    public:
        vector_iterator(T* ptr = nullptr) : ptr_(ptr) {}
        T& operator*() {
            return *ptr_;
        }
        vector_iterator& operator++() {
            ptr_++;
            return *this;
        }
        vector_iterator operator++(int) {
            vector_iterator temp = *this;
            ptr_++;
            return temp;
        }
        T* operator->() {
            return ptr_;
        }
        bool operator==(const vector_iterator& other) const {
            return ptr_ == other.ptr_;
        }
        bool operator!=(const vector_iterator& other) const {
            return ptr_ != other.ptr_;
        }
        vector_iterator operator+(size_t offset) const {
            return vector_iterator(ptr_ + offset);
        }
        vector_iterator operator+=(size_t offset) {
            ptr_ += offset;
            return *this;
        }
        vector_iterator operator-(size_t offset) const {
            return vector_iterator(ptr_ - offset);
        }
        vector_iterator operator-=(size_t offset) {
            ptr_ -= offset;
            return *this;
        }
        // friend size_t operator-(const vector_iterator& lhs, const vector_iterator& rhs) {
        //     return lhs.ptr_ - rhs.ptr_;
        // }
    };
public:
    typedef vector_iterator iterator;
    vector() {
        begin_ = new T[default_size];
        tail_ = begin_;
        end_ = begin_ + default_size;
        size_ = default_size;
    }

    vector(size_t size) {
        begin_ = new T[size];
        tail_ = begin_;
        end_ = begin_ + size;
        size_ = size;
    }

    vector(const vector& other) {
        size_ = other.capacity();
        begin_ = new T[size_];
        for (int i = 0; i < size_; i++) {
            begin_[i] = other.begin_[i];
        }
        tail_ = begin_ + other.size();
        end_ = begin_ + size_;
    }

    ~vector() {
        delete [] begin_;
    }

    const size_t size() const {
        return tail_ - begin_;
    }

    const size_t capacity() const {
        return size_;
    }

    void push_back(const T& data) {
        *tail_ = data;
        tail_++;
        if (tail_ == end_) {
            realloc();
        }
    }

    void pop_back() {
        if (tail_ != begin_) {
            tail_--;
        }
    }

    void realloc() {
        size_t raw_size = size_;
        size_ <<= 1;
        T* new_begin_ = new T[size_];
        for (size_t i = 0; i < raw_size; i++) {
            new_begin_[i] = begin_[i];
        }
        delete [] begin_;
        begin_ = new_begin_;
        tail_ = begin_ + raw_size;
        end_ = begin_ + size_;
    }

    void resize() {
        
    }

    iterator begin() {
        return iterator(begin_);
    }

    iterator end() {
        return iterator(tail_);
    }

    T& operator[](size_t index) {
        return begin_[index];
    }
    const T& operator[](size_t index) const {
        return begin_[index];
    }


public:
    const size_t default_size = 16;
private:
    size_t size_;
    T* begin_;
    T* tail_;
    T* end_;
};

}