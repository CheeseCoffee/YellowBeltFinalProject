//
// Created by Akbar on 28.06.2020.
//

#include "node.h"

DateComparisonNode::DateComparisonNode(Comparison cmp, Date date): _date(date), _cmp(cmp){

}

EventComparisonNode::EventComparisonNode(Comparison cmp, string event): _event(event), _cmp(cmp){

}

bool EmptyNode::Evaluate(const Date &date, const string &event) const {
    return true;
}

bool DateComparisonNode::Evaluate(const Date &date, const string &event) const {
    if(_cmp==Comparison::Equal){
        return !(date<_date or _date<date);
    }
    if(_cmp==Comparison::NotEqual){
        return (date<_date or _date<date);
    }
    if(_cmp==Comparison::Greater){
        return _date<date;
    }
    if(_cmp==Comparison::GreaterOrEqual){
        return _date<date or !(date<_date or _date<date);
    }
    if(_cmp==Comparison::Less){
        return date<_date;
    }
    if(_cmp==Comparison::LessOrEqual){
        return date<_date or !(date<_date or _date<date);
    }
}

bool EventComparisonNode::Evaluate(const Date &date, const string &event) const {
    if(_cmp==Comparison::Equal){
        return event==_event;
    }
    if(_cmp==Comparison::NotEqual){
        return event!=_event;
    }
    if(_cmp==Comparison::Greater){
        return event>_event;
    }
    if(_cmp==Comparison::GreaterOrEqual){
        return event>=_event;
    }
    if(_cmp==Comparison::Less){
        return event<_event;
    }
    if(_cmp==Comparison::LessOrEqual){
        return event<=_event;
    }
}

bool LogicalOperationNode::Evaluate(const Date& date, const string& event) const {
    if(_op==LogicalOperation::And){
        return _left->Evaluate(date, event) and _right->Evaluate(date, event);
    } else if (_op==LogicalOperation::Or){
        return _left->Evaluate(date, event) or _right->Evaluate(date, event);
    }
}