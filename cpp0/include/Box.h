#include <iostream>
struct Box
{
    int length;
    int width;
    int height;

    double weight;

    int value;
};

bool operator==(Box box1, Box box2) {
    return box1.length == box2.length && box1.width == box2.width && box1.height == box2.height && box1.weight == box2.weight && box1.value == box2.value;
}

std::ostream& operator<<(std::ostream& os, Box box) {
    os << "Length: " << box.length << ", Width: " << box.width << ", Height: " << box.height << ", Weight: " << box.weight << " Value: " << box.value << ".";
    return os;
}

Box create_box(int, int, int, double, int);

int get_sum_value(Box[], int);

bool is_less_than(Box, int);

int get_max_weight(Box[], int, int);

bool is_fit(Box[], int);