#include "header.h"

#ifndef LAYER_HPP
#define LAYER_HPP
struct Layer
{
private:
    int size;
    Matrix weights;
    Matrix biases;
    int ACTIVATION;
public:
    Layer();
    Layer(int numberOfInputs, int size, int ACTIVATION);
    Layer(const Layer& other);

    //Layer& operator=(const Layer&);

    Matrix Calculate(const Matrix&);
};
#endif 