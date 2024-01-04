#include "header.h"

#ifndef LAYER_HPP
#define LAYER_HPP
struct Layer
{
private:
    const int size;
    Matrix weights;
    Matrix biases;
    int ACTIVATION;
public:
    Layer();
    Layer(int numberOfInputs, int size, int ACTIVATION);

    Matrix Calculate(const Matrix&);
};
#endif 