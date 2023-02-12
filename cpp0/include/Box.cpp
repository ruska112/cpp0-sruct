#include "./Box.h"

Box create_box(int length, int width, int height, double weight, int value) {
    Box box;
    box.length = length;
    box.width = width;
    box.height = height;
    box.weight = weight;
    box.value = value;
    return box;
}

int get_sum_value(Box boxes[], int size) {
    int sum = 0;
    for(int i = 0; i < size; i++) {
        sum += boxes[i].value;
    }
    return sum;
}

bool is_less_than(Box box, int val) {
    return (box.length + box.width + box.height <= val);
}

int get_max_weight(Box boxes[], int size, int maxV) {
    int V = 0;
    int max = -1;
    for(int i = 0; i < size; i++) {
        V = boxes[i].length * boxes[i].width * boxes[i].height;
        if (V <= maxV) {
            if (max < boxes[i].weight) {
                max = boxes[i].weight;
            }
        }
    }
    return max;
}

bool is_fit(Box boxes[], int size) {
    bool flag = true;

    struct BoxV
    {
        Box box;
        int V;
    };

    BoxV boxes_V[size];

    for (int i = 0; i < size; i++)
    {
        boxes_V[i].box = boxes[i];
        boxes_V[i].V = boxes[i].length * boxes[i].width * boxes[i].height;
    }
    

    for (int i = 0; i < size-1; i++) {
        for (int j = 0; j < size-1-i; j++)
        {
            int _v = boxes_V[j].V;
            if (_v > boxes_V[j+1].V)
            {
                BoxV _boxV = boxes_V[j];
                boxes_V[j] = boxes_V[j+1];
                boxes_V[j+1] = _boxV; 
            }
        }
    }
    
    for (int i = 0; i < size-1; i++)
    {
        Box box1 = boxes_V[i].box;
        Box box2 = boxes_V[i+1].box;

        if (box1.length > box2.length || box1.width > box2.width || box1.height > box2.height)
        {
            flag = false;
        }
        
    }

    return flag;
}