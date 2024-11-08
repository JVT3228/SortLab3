#ifndef ONELIST_H
#define ONELIST_H

template <typename T>
class OneList {
private:
    struct Element {
        T data;
        Element* next;
        Element(T val) : data(val), next(nullptr) {}
    };

    Element* begin;
    Element* end;
    int count;

public:
    OneList() : begin(nullptr), end(nullptr), count(0) {}
    ~OneList();

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