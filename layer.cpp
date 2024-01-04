#include "header.h"
#include "layer.hpp"

Layer::Layer()
    : size(1) {}

Layer::Layer(int numberOfInputs, int size, int ACTIVATION)
    : size(size), ACTIVATION(ACTIVATION)
    {
        weights = Matrix(numberOfInputs, size);
        weights.setRandomValues();    

        biases = Matrix(size, 1);
        biases.setRandomValues();
    }

Layer::Layer(const Layer& other)
    : size(other.size), weights(other.weights), biases(other.biases), ACTIVATION(other.ACTIVATION) {}

/*Layer& Layer::operator=(const Layer& other)
{
    if (this!=&other)
    {
        size = other.size;
        weights = other.weights;
        ACTIVATION = other.ACTIVATION;
    }
    return *this;
}*/

Matrix Layer::Calculate(const Matrix& input)
{
    Matrix output;
    weights.Transpose();
    output = weights * input + biases;
    weights.Transpose();

    switch(ACTIVATION)
    {
        case 1:
            mTanh(output);
            break;
        case 2:
            mReLU(output);
            break;
        case 3:
            mSigmoid(output);
            break;
    }

    return output;
}