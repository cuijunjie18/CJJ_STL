#pragma once

#include <cstddef>
namespace cstd {

template<class T>
struct node {
    T data;
    node* next;
    node* prev;
    node(const T& d) : data(d), next(nullptr), prev(nullptr) {}
};

template<class T>
class list {
private:
    class list_iterator {
    private:
        node<T>* ptr;
    public:
        list_iterator(node<T> *p = nullptr) : ptr(p) {}
        T& operator*() const {
            return ptr->data;
        }
        list_iterator& operator++() {
            ptr = ptr->next;
            return *this;
        }
        bool operator==(const list_iterator &t) const {
            return t.ptr == this->ptr;
        }
        bool operator!=(const list_iterator &t) const {
            return t.ptr != this->ptr;
        }
    };

public:
    typedef list_iterator iterator; //类型别名  

    list()
    : head_(nullptr), tail_(nullptr) {}

    list(const list& other) {
        head_ = nullptr;
        tail_ = nullptr;
        node<T>* current = other.head_;
        while (current) {
            push_back(current->data);
            current = current->next;
        }
    }

    list& operator=(const list& other) {
        if (this != &other) {
            while (head_) {
                pop_front();
            }
            node<T>* current = other.head_;
            while (current) {
                push_back(current->data);
                current = current->next;
            }
        }
        return *this;
    }

    ~list() {
        while (head_) {
            pop_front();
        }
    }

    void push_back(const T& data) {
        node<T>* new_node = new node<T>(data);
        if (!head_) {
            head_ = new_node;
            tail_ = new_node;
        } else {
            tail_->next = new_node;
            new_node->prev = tail_;
            tail_ = new_node;
        }
    }

    void push_front(const T& data) {
        node<T>* new_node = new node<T>(data);
        if (!head_) {
            head_ = new_node;
            tail_ = new_node;
        } else {
            new_node->next = head_;
            head_->prev = new_node;
            head_ = new_node;
        }
    }

    void pop_back() {
        if (!tail_) return;
        node<T>* to_delete = tail_;
        tail_ = tail_->prev;
        if (tail_) tail_->next = nullptr;
        else head_ = nullptr;
        delete to_delete;
    }

    void pop_front() {
        if (!head_) return;
        node<T>* to_delete = head_;
        head_ = head_->next;
        if (head_) head_->prev = nullptr;
        else tail_ = nullptr;
        delete to_delete;
    }

    size_t size() const {
        size_t count = 0;
        node<T>* current = head_;
        while (current) {
            count++;
            current = current->next;
        }
        return count;
    }

    T& front() {
        return head_->data;
    }

    T& back() {
        return tail_->data;
    }

    iterator begin() {
        return iterator(head_);
    }

    iterator end() {
        return iterator(nullptr);
    }

private:
    node<T>* head_;
    node<T>* tail_;
};

}