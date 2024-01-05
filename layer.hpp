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

    Matrix input;
    Matrix Z;
    Matrix A;
public:
    Layer();
    Layer(int numberOfInputs, int size, int ACTIVATION);
    Layer(const Layer& other);

    //Layer& operator=(const Layer&);
    Matrix getInput() const;
    Matrix getZ() const;
    Matrix getA() const;

    Matrix Calculate(const Matrix&);
    void updateWeights(const Matrix&, const float&);
};
#endif 