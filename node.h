//
// Created by Akbar on 28.06.2020.
//


class Node {
    virtual int Evaluate() const = 0;
};

class EmptyNode: public Node {

};

class DateComparisonNode: public Node{

};

class EventComparisonNode: public Node{

};