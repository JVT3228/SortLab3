#include <iostream>
#include <string>
#include "OneList.cpp"
#include "DoubleList.cpp"
#include "Windows.h"

template <typename ListType>
void stringToList(const std::string& str, ListType& list) {
    for (char ch : str) {
        list.push_back(ch);
    }
}

template <typename ListType>
std::string listToString(const ListType& list) {
    std::string result;
    for (auto it = list.beginIter(); it != list.endIter(); ++it) {
        result += *it;
    }
    return result;
}

template <typename ListType>
void processListString(ListType& list) {
    int count_e = 0;
    int group_count = 0;
    typename ListType::Iterator group_start = list.endIter();

    for (auto it = list.beginIter(); it != list.endIter(); ++it) {
        if (*it == 'е') {
            count_e++;
            if (count_e == 1) group_start = it;
        }
        else {
            if (count_e == 5) {
                group_count++;
            }
            count_e = 0;
        }
    }
    if (count_e == 5) group_count++;

    if (group_count > 1) {
        count_e = 0;
        group_start = list.endIter();

        for (auto it = list.beginIter(); it != list.endIter(); ++it) {
            if (*it == 'е') {
                count_e++;
                if (count_e == 1) group_start = it;
            }
            else {
                if (count_e == 5 && group_start != list.endIter()) {
                    *group_start = 'E';
                    auto temp = group_start;
                    for (int i = 1; i < 5; ++i) {
                        ++temp;
                        *temp = ' ';
                    }
                }
                count_e = 0;
            }
        }

        if (count_e == 5 && group_start != list.endIter()) {
            *group_start = 'E';
            auto temp = group_start;
            for (int i = 1; i < 5; ++i) {
                ++temp;
                *temp = ' ';
            }
        }

        list.push_back('?');
    }
}

int main() {

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int listChoice;
    std::string input;

    std::cout << "Выберите тип списка:\n1. Односвязный список\n2. Двухсвязный список\nВыберите: ";
    std::cin >> listChoice;
    std::cin.ignore();

    std::cout << "Введите строку для обработки: ";
    std::getline(std::cin, input);

    if (listChoice == 1) {
        OneList<char> list;
        stringToList(input, list);
        processListString(list);
        std::cout << "Результат: " << listToString(list) << std::endl;
    }
    else if (listChoice == 2) {
        DoubleList<char> list;
        stringToList(input, list);
        processListString(list);
        std::cout << "Результат: " << listToString(list) << std::endl;
    }
    else {
        std::cout << "Неверный выбор!" << std::endl;
    }

    return 0;
}