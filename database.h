//
// Created by Akbar on 28.06.2020.
//

#pragma once

#include <set>
#include <map>
#include <functional>
#include "date.h"

using namespace std;

class Database {
public:
    void Add(const Date& date, const string& event);
    void Print(ostream& stream) const;
    int RemoveIf(function<bool(const Date&, const string&)>func);
    vector<string> FindIf(function<bool(const Date&, const string&)>func) const;
    string Last(const Date& date) const;

private:
    map<Date, set<string>> storage;
    map<Date, vector<string>> last_storage;
};