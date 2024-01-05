#include "header.h"
#include "layer.hpp"

Layer::Layer()
    : size(1) {}

Layer::Layer(int numberOfInputs, int size, int ACTIVATION)
    : size(size), ACTIVATION(ACTIVATION)
    {
        weights = Matrix(numberOfInputs, size);
        weights.setRandomValues();    
        weights.Transpose();

        biases = Matrix(size, 1);
        biases.setRandomValues();
    }

Layer::Layer(const Layer& other)
    : size(other.size), weights(other.weights), biases(other.biases), ACTIVATION(other.ACTIVATION), input(input), Z(Z), A(A) {}

Matrix Layer::getInput() const {return input;}
Matrix Layer::getZ() const {return Z;}
Matrix Layer::getA() const {return A;}



Matrix Layer::Calculate(const Matrix& layerInput)
{
    input = layerInput;
    Matrix output = weights * input + biases;
    Z = output;

    switch(ACTIVATION)
    {
        case 1:
            mTanh(output);
            std::cout << "tanh" << std::endl;
            break;
        case 2:
            mReLU(output);
            break;
        case 3:
            mSigmoid(output);
            break;
    }

    A = output;
    std::cout << A << std::endl;
    return output;
}

void Layer::updateWeights(const Matrix& gradient, const float& learningRate)
{
    std::cout << "hello there";
    weights = weights - gradient * learningRate;
}

