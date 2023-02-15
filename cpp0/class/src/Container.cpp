#include "../include/Container.h"
#include <../include/BoxAddingException.h>

Container::Container(int length, int width, int height, double max_weight) :
        _length(length), _width(width), _height(height), _max_weight(max_weight) {}

void Container::add_box_by_index(int index, Box box) {
    if (this->get_sum_weight() + box.get_weight() <= this->_max_weight) {
        _boxes.insert(_boxes.cbegin() + index, box);
    } else {
        throw BoxAddingException("overweight");
    }
}

void Container::delete_box(int index) {
    if (index <= _boxes.size() - 1 && index >= 0) {
        _boxes.erase(_boxes.cbegin() + index);
    }
}

double Container::get_sum_weight() {
    double sum = 0;
    for (Box box: _boxes) {
        sum += box.get_weight();
    }
    return sum;
}

int Container::get_sum_value() {
    int sum = 0;
    for (Box box: _boxes) {
        sum += box.get_value();
    }
    return sum;
}

Box Container::get_box(int index) {
    if (index <= _boxes.size() - 1 && index >= 0) {
        return _boxes.at(index);
    }
}

int Container::add_box(Box box) {
    if (this->get_sum_weight() + box.get_weight() <= this->_max_weight) {
        _boxes.push_back(box);
        return static_cast<int>(_boxes.size() - 1);
    } else {
        throw BoxAddingException("overweight");
    }
}