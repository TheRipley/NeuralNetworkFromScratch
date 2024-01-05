#include "header.h"
#include "layer.hpp"

Layer::Layer()
    : size(1) {}

Layer::Layer(int numberOfInputs, int size, int ACTIVATION)
    : size(size), ACTIVATION(ACTIVATION)
    {
        weights = Matrix(numberOfInputs, size);
        weights.setRandomValues();    
        weights = weights.Transpose();

        biases = Matrix(size, 1);
        biases.setRandomValues();
    }

Layer::Layer(const Layer& other)
    : size(other.size), weights(other.weights), biases(other.biases), ACTIVATION(other.ACTIVATION), input(other.input), Z(other.Z), A(other.A) {}


Matrix Layer::getInput() const {return input;}
Matrix Layer::getZ() const {return Z;}
Matrix Layer::getA() const {return A;}
Matrix Layer::getWeights() const {return weights;}
Matrix Layer::getBiases() const {return biases;}



Matrix Layer::Forward(const Matrix& layerInput)
{
    input = layerInput;
    //std::cout << "bruh" << std::endl;
    Matrix output = weights * input + biases;
    Z = output;

    switch(ACTIVATION)
    {
        case 1:
            mTanh(output);
            //std::cout << "tanh" << std::endl;
            break;
        case 2:
            mReLU(output);
            break;
        case 3:
            mSigmoid(output);
            break;
    }

    A = output;
    //std::cout << A << std::endl;
    return output;
}

Matrix Layer::Backward(const Matrix& outputGradient, float learningRate)
{
    // Calculate weights gradient
    Matrix weightsGradient = outputGradient * input.Transpose();

    // Calculate input gradient
    Matrix inputGradient = weights.Transpose() * outputGradient;

    // Update weights and bias
    weights = weights - weightsGradient * learningRate;
    biases = biases - outputGradient * learningRate;

    Matrix activation_prime = input;
    switch (ACTIVATION)
    {
    case 1:
        mTanhPrime(activation_prime);
        break;
    case 2:
        mReLUPrime(activation_prime);
        break;
    case 3:
        mSigmoidPrime(activation_prime);
        break;
    
    default:
        break;
    }
    return HadamardProduct(inputGradient, activation_prime);   
}



