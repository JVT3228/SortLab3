#include "pch.h"
#include "OneList.h"
#include <stdexcept>

template <typename T>
OneList<T>::~OneList() {
    while (begin) {
        pop_front();
    }
}

template <typename T>
void OneList<T>::push_front(T value) {
    Element* newElem = new Element(value);
    newElem->next = begin;
    begin = newElem;
    if (!end) end = begin;
    count++;
}

template <typename T>
void OneList<T>::push_back(T value) {
    Element* newElem = new Element(value);
    if (!begin) {
        begin = end = newElem;
    }
    else {
        end->next = newElem;
        end = newElem;
    }
    count++;
}

template <typename T>
void OneList<T>::insert(int index, T value) {
    if (index < 0 || index > count) throw std::out_of_range("Invalid index");

    if (index == 0) {
        push_front(value);
    }
    else if (index == count) {
        push_back(value);
    }
    else {
        Element* newElem = new Element(value);
        Element* temp = begin;
        for (int i = 0; i < index - 1; ++i) {
            temp = temp->next;
        }
        newElem->next = temp->next;
        temp->next = newElem;
        count++;
    }
}

template <typename T>
void OneList<T>::pop_front() {
    if (!begin) throw std::runtime_error("List is empty");
    Element* temp = begin;
    begin = begin->next;
    delete temp;
    if (!begin) end = nullptr;
    count--;
}

template <typename T>
void OneList<T>::pop_back() {
    if (!begin) throw std::runtime_error("List is empty");
    if (begin == end) {
        delete begin;
        begin = end = nullptr;
    }
    else {
        Element* temp = begin;
        while (temp->next != end) {
            temp = temp->next;
        }
        delete end;
        end = temp;
        end->next = nullptr;
    }
    count--;
}

template <typename T>
void OneList<T>::remove(T value) {
    while (begin && begin->data == value) {
        pop_front();
    }
    Element* temp = begin;
    while (temp && temp->next) {
        if (temp->next->data == value) {
            Element* toDelete = temp->next;
            temp->next = temp->next->next;
            delete toDelete;
            count--;
        }
        else {
            temp = temp->next;
        }
    }
}

template <typename T>
int OneList<T>::size() const {
    return count;
}

template <typename T>
T& OneList<T>::front() const {
    if (!begin) throw std::runtime_error("List is empty");
    return begin->data;
}

template <typename T>
T& OneList<T>::back() const {
    if (!end) throw std::runtime_error("List is empty");
    return end->data;
}

template <typename T>
bool OneList<T>::empty() const {
    return count == 0;
}

template class OneList<int>;
template class OneList<double>;