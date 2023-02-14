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

int Container::add_box(Box box) {
    if (this->get_sum_weight() + box.get_weight() <= this->_max_weight) {
        _boxes.push_back(box);
        return static_cast<int>(_boxes.size() - 1);
    } else {
        throw BoxAddingException("overweight");
    }
}