#pragma once
#include <iostream>
#include "Node.h"
#include "List.h"

// Solution file. Lab 3's LinkedList plus addBack, getFront, isEmpty, size.
// tail_ is back so addBack is O(1). size_ is new so size() is O(1).

template <typename T>
class LinkedList : public List<T> {
public:
    LinkedList() : head_(nullptr), tail_(nullptr), size_(0) {}

    void addFront(T* value) override {
        Node<T>* fresh = new Node<T>(value);
        fresh->next = head_;
        head_ = fresh;
        if (tail_ == nullptr) {
            tail_ = fresh;          // first node is both head and tail
        }
        ++size_;
    }

    void addBack(T* value) override {
        Node<T>* fresh = new Node<T>(value);
        if (tail_ == nullptr) {
            head_ = fresh;          // first node is both head and tail
            tail_ = fresh;
        } else {
            tail_->next = fresh;
            tail_ = fresh;
        }
        ++size_;
    }

    void deleteFront() override {
        if (head_ == nullptr) {
            std::cout << "LinkedList is empty." << std::endl;
            return;
        }
        Node<T>* doomed = head_;
        head_ = head_->next;
        if (head_ == nullptr) {
            tail_ = nullptr;        // list is empty again
        }
        delete doomed->data;
        delete doomed;
        --size_;
    }

    T* getFront() const override {
        if (head_ == nullptr) {
            return nullptr;
        }
        return head_->data;
    }

    bool isEmpty() const override {
        return head_ == nullptr;
    }

    int size() const override {
        return size_;
    }

    bool search(T* value) const override {
        Node<T>* current = head_;
        while (current != nullptr) {
            if (*current->data == *value) {
                return true;
            }
            current = current->next;
        }
        return false;
    }

    void print() const override {
        Node<T>* current = head_;
        while (current != nullptr) {
            std::cout << *current->data << ",";
            current = current->next;
        }
        std::cout << std::endl;
    }

    ~LinkedList() override {
        while (head_ != nullptr) {
            Node<T>* doomed = head_;
            head_ = head_->next;
            delete doomed->data;
            delete doomed;
        }
    }

    void addAnywhere(int position, T* value) override {
        if (position < 0 || position > size_) {
            std::cout << "addAnywhere LinkedList Position out of bounds." << std::endl;
            return;
        }
        Node<T>* new_node = new Node<T>(value);
        Node<T>* current = head_;
        for (int i = 0; i < size_; ++i) {
            if (i+1 == position) {  //curent is node before target
                Node<T>* temp = current->next;
                current->next = new_node;
                new_node->next = temp;
                size_++;
                return;
            }
            else {
                current = current->next;
            }
        }
    }

    void deleteAnywhere(int position) override {
        if (position < 0 || position >= size_) {
            std::cout << "deleteAnywhere LinkedList Position out of bounds." << std::endl;
            return;
        }
        Node<T>* current = head_;

        for (int i = 0; i < position-1; ++i) {
            current = current->next;
        }
        //current is now the node before our target
        Node<T>* doomed = current->next;
        current->next = current->next->next;
        delete doomed->data;
        delete doomed;
    }

    void reverse() override {
        if (head_ == nullptr) {
            std::cout << "LinkedList is empty." << std::endl;
            return;
        }
        Node<T>* previous_node = nullptr;
        Node<T>* current_node = head_;
        Node<T>* next_node = head_->next;

        if (current_node == nullptr) {
            std::cout << "LinkedList is empty. Cant Reverse" << std::endl;
            return;
        }
        if (next_node == nullptr) {
            std::cout << "LinkedList has only 1 element. Cant Reverse" << std::endl;
            return;
        }
        tail_ = head_;
        while (next_node != nullptr) {
            next_node = current_node->next;
            current_node->next = previous_node;
            previous_node = current_node;
            current_node = next_node;
        }
        head_ = previous_node;
        return;
    }

    void concat(List<T>* other) override {
        LinkedList<T>* other_linked_list = dynamic_cast<LinkedList<T>*>(other);
        if (other_linked_list != nullptr) {
            if (other_linked_list->isEmpty()) {
                std::cout << "LinkedList to concat is empty." << std::endl;
                return;
            }
            if (head_ == nullptr) {
                head_ = other_linked_list->head_;
                tail_ = other_linked_list->tail_;
            }
            else {
                tail_->next = other_linked_list->head_;
                tail_ = other_linked_list->tail_;
                size_ += other_linked_list->size_;
            }
            other_linked_list->head_ = nullptr;
            other_linked_list->tail_ = nullptr;
            other_linked_list->size_ = 0;
        }
        else {
            std::cout << "LinkedList not found. Cant Concat" << std::endl;
            return;
        }
    }

private:
    Node<T>* head_;
    Node<T>* tail_;
    int size_;
};
