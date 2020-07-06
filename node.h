//
// Created by Akbar on 28.06.2020.
//
#pragma once

#include <memory>
#include "date.h"

using namespace std;

enum class LogicalOperation{
    And,
    Or,
};

enum class Comparison{
    Less,
    LessOrEqual,
    Greater,
    GreaterOrEqual,
    Equal,
    NotEqual,
};

class Node {
public:
    virtual bool Evaluate(const Date& date, const string& event) const = 0;
};

class EmptyNode: public Node {
    bool Evaluate(const Date& date, const string& event) const override;
};

class DateComparisonNode: public Node{
public:
    DateComparisonNode(Comparison cmp, Date date);
    bool Evaluate(const Date& date, const string& event) const override;
private:
    const Date _date;
    const Comparison _cmp;
};

class EventComparisonNode: public Node{
public:
    EventComparisonNode(Comparison cmp, string event);
    bool Evaluate(const Date& date, const string& event) const override;
private:
    const string _event;
    const Comparison _cmp;
};

class LogicalOperationNode: public Node{
public:
    LogicalOperationNode(LogicalOperation op, shared_ptr<Node> left, shared_ptr<Node> right):_op(op),_left(left),_right(right){}
    bool Evaluate(const Date& date, const string& event) const override;
private:
    const LogicalOperation _op;
    shared_ptr<const Node> _left, _right;
};