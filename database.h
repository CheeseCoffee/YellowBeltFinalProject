//
// Created by Akbar on 28.06.2020.
//

#pragma once

#include <set>
#include <map>
#include "date.h"

using namespace std;

class Database {
public:
    void Add(const Date& date, const string& event);
    void Print(ostream& stream) const;

private:
    map<Date, set<string>> storage;
};