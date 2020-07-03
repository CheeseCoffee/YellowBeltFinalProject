//
// Created by Akbar on 28.06.2020.
//

#pragma once

#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

class Date {
public:
    // конструктор выбрасывает исключение, если его аргументы некорректны
    Date(int new_year, int new_month, int new_day);

    int GetYear() const;
    int GetMonth() const;
    int GetDay() const;

private:
    int year;
    int month;
    int day;
};

Date ParseDate(istream& date_stream);

bool operator<(const Date& lhs, const Date& rhs);

ostream& operator<<(ostream& stream, const Date& date);