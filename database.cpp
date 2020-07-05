//
// Created by Akbar on 28.06.2020.
//

#include "database.h"

using namespace std;

void Database::Add(const Date& date, const string& event) {
    storage[date].insert(event);
}

void Database::Print(ostream& stream) const {
    for (const auto& item : storage) {
        for (const string& event : item.second) {
            stream << item.first << " " << event << endl;
        }
    }
}

int Database::RemoveIf(function<bool(const Date&, const string&)> func) {
    for(const auto& item: storage){
        for(const string& event: item.second){
            cout<<func(item.first, event)<<endl;
        }
    }
}

//bool DeleteEvent(const Date& date, const string& event) {
//    if (storage.count(date) > 0 && storage[date].count(event) > 0) {
//        storage[date].erase(event);
//        return true;
//    }
//    return false;
//}

//int DeleteDate(const Date& date) {
//    if (storage.count(date) == 0) {
//        return 0;
//    } else {
//        const int event_count = storage[date].size();
//        storage.erase(date);
//        return event_count;
//    }
//}

//set<string> Find(const Date& date) const {
//    if (storage.count(date) > 0) {
//        return storage.at(date);
//    } else {
//        return {};
//    }
//}

