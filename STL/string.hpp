#pragma once

#include <cstddef>
#include <cstring>
namespace cstl {

class string {
private:
    class string_iterator {
    public:
        string_iterator(char* ptr) : ptr_(ptr) {}

        char& operator*() const {
            return *ptr_;
        }

        string_iterator& operator++() {
            ++ptr_;
            return *this;
        }

        bool operator!=(const string_iterator& other) const {
            return ptr_ != other.ptr_;
        }

    private:
        char* ptr_;
    };
public:
    typedef string_iterator iterator;
    string() {
        data_ = new char[1];
        data_[0] = '\0';
    }
    string(const char* str) {
        data_ = new char[strlen(str) + 1];
        strcpy(data_, str);
    }

    ~string() {
        delete[] data_;
    }

    const string& operator=(const char* str) {
        strcpy(data_, str);
        return *this;
    }
    const string& operator=(const string& other) {
        if (this != &other) {
            strcpy(data_, other.data_);
        }
        return *this;
    }

    const char* c_str() const {
        return data_;
    }

    const char& operator[](size_t index) const {
        return data_[index];
    }
    char& operator[](size_t index) {
        return data_[index];
    }

    friend bool operator==(const string& lhs, const string& rhs) {
        return strcmp(lhs.data_, rhs.data_) == 0;
    }

    size_t size() const {
        return strlen(data_);
    }

    iterator begin() {
        return iterator(data_);
    }

    iterator end() {
        return iterator(data_ + size());
    }
private:
    char* data_;
};

}