#include <vector>

#include "./Box.h"

class Container{
private:
    std::vector<Box> _boxes;
    int _length;
    int _width;
    int _height;
    double _max_weight;
public:
    Container(int, int, int, double);

    void add_box(int, Box);

    void delete_box(int);

    double get_sum_weight();

    int get_sum_value();

    Box get_box(int);

    void add_box(int);
};