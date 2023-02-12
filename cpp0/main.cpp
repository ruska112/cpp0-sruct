#include <iostream>

#include "Box.cpp"

int main() {
    printf("Hello, World!\n");

    Box my_box0 = create_box(30, 30, 30, 10.0, 10000);
    Box my_box1 = create_box(20, 20, 20, 20.0, 20000);
    Box my_box2 = create_box(10, 10, 10, 30.0, 30000);

    Box boxes[] = {my_box0, my_box1, my_box2};

    int sum = get_sum_value(boxes, 3);

    printf("%d\n", sum);

    printf("%d\n", is_less_than(my_box0, 40));

    printf("%d\n", get_max_weight(boxes, 3, 8000));

    printf("%d\n", is_fit(boxes, 3));

    printf("%d\n", my_box0 == my_box1);

    std::cout << my_box0 << std::endl; 

    return 0;
}