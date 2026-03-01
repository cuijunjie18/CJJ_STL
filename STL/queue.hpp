#pragma once
#include <cstddef>
#include <stdexcept>

template<class T>
class queue {
public:
    queue(size_t size = 100005) 
    : m_Size_(size + 1) {
        m_Data_ = new T[m_Size_];
        m_Front_ = m_Data_;
        m_Back_ = m_Data_;
    }

    ~queue() {
        delete[] m_Data_;
    }

    bool empty() const {
        return m_Front_ == m_Back_;
    }

    void push(const T& data) {
        *m_Back_ = data;
        m_Back_++;
        if (m_Back_ == m_Data_ + m_Size_) {
            m_Back_ = m_Data_;
        }
        if (m_Back_ == m_Front_) {
            throw std::overflow_error("Queue is full");
        }
    }

    void pop() {
        if (empty()) {
            throw std::underflow_error("Queue is empty");
        }
        m_Front_++;
        if (m_Front_ == m_Data_ + m_Size_) {
            m_Front_ = m_Data_;
        }
    }

    const T& front() const {
        if (empty()) {
            throw std::underflow_error("Queue is empty");
        }
        return *m_Front_;
    }

    const T& back() const {
        if (empty()) {
            throw std::underflow_error("Queue is empty");
        }
        T* backPtr = m_Back_ - 1;
        if (backPtr < m_Data_) {
            backPtr = m_Data_ + m_Size_ - 1;
        }
        return *backPtr;
    }

    size_t size() const {
        if (m_Back_ >= m_Front_) {
            return m_Back_ - m_Front_;
        } else {
            return m_Size_ - (m_Front_ - m_Back_);
        }
    }

    size_t capacity() const {
        return m_Size_ - 1;
    }

private:
    size_t m_Size_ = 0;
    T* m_Data_ = nullptr;
    T* m_Front_ = nullptr;
    T* m_Back_ = nullptr;
};