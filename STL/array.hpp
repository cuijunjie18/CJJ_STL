#pragma once
#include <cstddef>

namespace cstd {

template<class T, size_t S>
class array {
public:
    array() = default;
    ~array() = default;
public:
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

private:
    T m_Data_[S];
};

}