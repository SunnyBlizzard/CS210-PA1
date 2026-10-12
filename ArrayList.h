#pragma once
#include <iostream>
#include "List.h"

// Solution file. Lab 3's ArrayList plus addBack, getFront, isEmpty, size.

template <typename T>
class ArrayList : public List<T> {
public:
    ArrayList() : size_(0) {}

    void addFront(T* value) override {
        if (size_ >= CAPACITY) {
            std::cout << "ArrayList is full." << std::endl;
            return;
        }
        for (int i = size_; i > 0; --i) {
            data_[i] = data_[i - 1];
        }
        data_[0] = value;
        ++size_;
    }

    void addBack(T* value) override {
        if (size_ >= CAPACITY) {
            std::cout << "ArrayList is full." << std::endl;
            return;
        }
        data_[size_] = value;       // no shifting needed at the back
        ++size_;
    }

    void deleteFront() override {
        if (size_ == 0) {
            std::cout << "ArrayList is empty." << std::endl;
            return;
        }
        delete data_[0];
        for (int i = 0; i < size_ - 1; ++i) {
            data_[i] = data_[i + 1];
        }
        --size_;
    }

    T* getFront() const override {
        if (size_ == 0) {
            return nullptr;
        }
        return data_[0];
    }

    bool isEmpty() const override {
        return size_ == 0;
    }

    int size() const override {
        return size_;
    }

    bool search(T* value) const override {
        for (int i = 0; i < size_; ++i) {
            if (*data_[i] == *value) {
                return true;
            }
        }
        return false;
    }

    void print() const override {
        for (int i = 0; i < size_; ++i) {
            std::cout << *data_[i] << ",";
        }
        std::cout << std::endl;
    }

    ~ArrayList() override {
        for (int i = 0; i < size_; ++i) {
            delete data_[i];
        }
    }

        void addAnywhere(int position, T* value) override {
        if (position == 0) {
            addFront(value);
        }
        else if (position == size_) {
            addBack(value);
        }
        else if (position > size_ || position < 0) {
            std::cout << "Invalid addAnywhere Array Index." << std::endl;
            return;
        }
        else {
            for (int i = size_; i > position; --i) {
                data_[i] = data_[i - 1];
            }
            data_[position] = value;
            size_++;
        }
    }

    void deleteAnywhere(int position) override {
        if (position == 0) {
            deleteFront();
        }
        else if (position >= size_ || position < 0) {
            std::cout << "Invalid  deleteAnywhere Array Index." << std::endl;
            return;
        }
        else {
            T* doomed = data_[position];
            delete doomed;
            for (int i = position; i < size_ - 1; ++i) {
                data_[i] = data_[i + 1];
            }
            --size_;
        }
    }

    void reverse() override {
        T* temp;
        int j = size_ - 1;
        int i = 0;
        while (i < j) {
            temp = data_[i];
            data_[i] = data_[j];
            data_[j] = temp;
            j--;
            i++;
        }
    }

    void concat(List<T>* other) override {
        ArrayList<T>* other_array_list = dynamic_cast<ArrayList<T>*>(other);
        if (other_array_list != nullptr) {
            if (other_array_list->isEmpty()) {
                std::cout << "ArrayList to concat is empty." << std::endl;
                return;
            }
            if (size_ + other_array_list->size_ > CAPACITY) {
                std::cout << "ArrayList cannot concat due to CAPACITY." << std::endl;
                return;
            }
            for (int i = 0; i < other_array_list->size_; ++i) {
                data_[size_] = other_array_list->data_[i];
                other_array_list->data_[i] = nullptr;
                size_++;
            }
            other_array_list->size_ = 0;
        }
        else {
            std::cout << "ArrayList not found. Cant Concat" << std::endl;
            return;
        }
    }


private:
    static const int CAPACITY = 20;
    T* data_[CAPACITY];
    int size_;
};
