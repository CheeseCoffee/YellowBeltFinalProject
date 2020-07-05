//
// Created by Akbar on 28.06.2020.
//

#include "node.h"

bool

bool LogicalOperationNode::Evaluate(const Date& date, const string& event) const {
    if(_op==LogicalOperation::And){
        return _left->Evaluate(date, event) and _right->Evaluate(date, event);
    } else if (_op==LogicalOperation::Or){
        return _left->Evaluate(date, event) or _right->Evaluate(date, event);
    }
}