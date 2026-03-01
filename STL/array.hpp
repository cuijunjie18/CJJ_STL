#pragma once
#include <cstddef>

namespace cstd {

template<class T, size_t S>
class array {
private:
    class array_iterator {
    private:
        T* ptr;
    public:
        array_iterator(T *p = nullptr) : ptr(p) {}
        T& operator*() const {
            return *ptr;
        }
        array_iterator& operator++() {
            ptr++;
            return *this;
        }
        T* operator->() const {
            return ptr;
        }
        bool operator==(const array_iterator& other) const {
            return ptr == other.ptr;
        }
        bool operator!=(const array_iterator& other) const {
            return ptr != other.ptr;
        }
    };
public:
    array() = default;
    ~array() = default;
public:
    typedef array_iterator iterator; //类型别名
    constexpr size_t Size() const {
        return S;
    }

    T& operator[](size_t index) {
        return m_Data_[index];
    }
    const T& operator[](size_t index) const {
        return m_Data_[index];
    }

    T* Data() {
        return m_Data_;
    }
    const T* Data() const {
        return m_Data_;
    }

    iterator begin() {
        return iterator(m_Data_);
    }

    iterator end() {
        return iterator(m_Data_ + S);
    }

private:
    T m_Data_[S];
};

}