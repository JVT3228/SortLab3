#ifndef DOUBLELIST_H
#define DOUBLELIST_H

template <typename T>
class DoubleList {
private:
    struct Element {
        T data;
        Element* next;
        Element* prev;
        Element(T val) : data(val), next(nullptr), prev(nullptr) {}
    }; 

    Element* begin;
    Element* end;
    int count;

public:
    DoubleList() : begin(nullptr), end(nullptr), count(0) {}
    ~DoubleList();

    void push_front(T value);
    void push_back(T value);
    void insert(int index, T value);
    void pop_front();
    void pop_back();
    void remove(T value);
    int size() const;
    T& front() const;
    T& back() const;
    bool empty() const;
};

#endif