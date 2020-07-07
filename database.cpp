//
// Created by Akbar on 28.06.2020.
//



#include "database.h"
#include <algorithm>

using namespace std;

void Database::Add(const Date& date, const string& event) {
    if(storage[date].insert(event).second){
        //last_storage[date].erase(find_if(last_storage[date].begin(),last_storage[date].end(),[event](const string& event1){return event1==event;}));
        last_storage[date].push_back(event);
    }

}

void Database::Print(ostream& stream) const {
    for (const auto& item : last_storage) {
        for (const string& event : item.second) {
            stream << item.first << " " << event << endl;
        }
    }
}

int Database::RemoveIf(const function<bool(const Date&, const string&)>& func) {

    int removed_count=0;

    /*for(auto& item: last_storage){
        auto vector_begin=item.second.begin();
        auto vector_end=item.second.end();

        auto it=remove_if(vector_begin, vector_end, [func, item](const string& event){return func(item.first,event);});

        removed_count=removed_count+(vector_end-it);

        for(auto iit=it;iit!=vector_end;iit++){
            storage[item.first].erase(*iit);
        }
        item.second.erase(it, vector_end);
    }

    auto i=storage.begin();
    while((i=find_if(i,storage.end(),[](auto it){return it.second.empty();}))!=storage.end()){
        storage.erase(i++);
    }

    auto ii=last_storage.begin();
    while((ii=find_if(ii,last_storage.end(),[](auto it){return it.second.empty();}))!=last_storage.end()){
        last_storage.erase(ii++);
    }*/
    auto copy=last_storage;
    for(auto datevent: copy){
        auto& events=datevent.second;
        auto del=stable_partition(events.begin(),events.end(),[func,datevent](const string& event){ return !func(datevent.first, event);});
        removed_count=removed_count+(events.end()-del);
        events.erase(del,events.end());
        if(events.empty()){
            last_storage.erase(datevent.first);
            storage.erase(datevent.first);
        }else{
            last_storage[datevent.first]=events;
            storage[datevent.first]=set<string>(events.begin(),events.end());
        }
    }

    return removed_count;
}

vector<string> Database::FindIf(const function<bool (const Date &, const string &)>& func) const {
    vector<string> vec;
    for(const auto& item: last_storage){
        Date current_date=item.first;
        auto set_begin=item.second.begin();
        auto set_end=item.second.end();

        auto it=find_if(set_begin, set_end, [func,current_date](const string& event){return func(current_date,event);});
        while(it!=set_end){
            stringstream ss;
            ss<<current_date<<" "<<*it;
            vec.push_back(ss.str());
            it++;
            it=find_if(it, set_end, [func,current_date](const string& event){return func(current_date,event);});
        }
    }
    return vec;
}

string Database::Last(const Date &date) const {
    auto it=last_storage.upper_bound(date);
    ostringstream os;
    if(it==last_storage.begin()){
        os << "No entries";
        throw invalid_argument(os.str());
    }else{
        //if(it==last_storage.end()){cout<<"WOW"<<endl;}
        it--;
        os << (*it).first << " " <<(*it).second.back();
        return os.str();
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

