#include "pch.h"
#include "DoubleList.h"
#include <stdexcept>

template <typename T>
DoubleList<T>::~DoubleList() {
    while (begin) {
        pop_front();
    }
}

template <typename T>
void DoubleList<T>::push_front(T value) {
    Element* newElem = new Element(value);
    newElem->next = begin;
    if (begin) begin->prev = newElem;
    begin = newElem;
    if (!end) end = begin;
    count++;
}

template <typename T>
void DoubleList<T>::push_back(T value) {
    Element* newElem = new Element(value);
    newElem->prev = end;
    if (end) end->next = newElem;
    end = newElem;
    if (!begin) begin = end;
    count++;
}

template <typename T>
void DoubleList<T>::insert(int index, T value) {
    if (index < 0 || index > count) throw std::out_of_range("Invalid index");

    if (index == 0) {
        push_front(value);
    }
    else if (index == count) {
        push_back(value);
    }
    else {
        Element* temp = begin;
        for (int i = 0; i < index - 1; ++i) {
            temp = temp->next;
        }
        Element* newElem = new Element(value);
        newElem->next = temp->next;
        newElem->prev = temp;
        temp->next->prev = newElem;
        temp->next = newElem;
        count++;
    }
}

template <typename T>
void DoubleList<T>::pop_front() {
    if (!begin) throw std::runtime_error("List is empty");
    Element* temp = begin;
    begin = begin->next;
    if (begin) begin->prev = nullptr;
    else end = nullptr;
    delete temp;
    count--;
}

template <typename T>
void DoubleList<T>::pop_back() {
    if (!end) throw std::runtime_error("List is empty");
    Element* temp = end;
    end = end->prev;
    if (end) end->next = nullptr;
    else begin = nullptr;
    delete temp;
    count--;
}

template <typename T>
void DoubleList<T>::remove(T value) {
    Element* temp = begin;
    while (temp) {
        if (temp->data == value) {
            Element* toDelete = temp;

            temp = temp->next;

            if (toDelete->prev) {
                toDelete->prev->next = toDelete->next;
            }
            else {
                begin = toDelete->next;
            }

            if (toDelete->next) {
                toDelete->next->prev = toDelete->prev;
            }
            else {
                end = toDelete->prev;
            }

            delete toDelete;
            count--;
        }
        else {
            temp = temp->next;
        }
    }
}

template <typename T>
int DoubleList<T>::size() const {
    return count;
}

template <typename T>
T& DoubleList<T>::front() const {
    if (!begin) throw std::runtime_error("List is empty");
    return begin->data;
}

template <typename T>
T& DoubleList<T>::back() const {
    if (!end) throw std::runtime_error("List is empty");
    return end->data;
}

template <typename T>
bool DoubleList<T>::empty() const {
    return count == 0;
}

template class DoubleList<int>;
template class DoubleList<double>;
