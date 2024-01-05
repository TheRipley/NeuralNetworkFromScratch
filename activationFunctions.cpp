#include "header.h"
#include "matrix.hpp"


void mTanh(Matrix& input)
{
    for (int i=0; i<input.getHeight(); i++)
    {
        for (int j=0; j<input.getWidth(); j++)
        {
            input.setAt(i, j, tanh(input.getAt(i, j)));
        }
    }
}

void mTanhPrime(Matrix& input)
{
    for (int i=0; i<input.getHeight(); i++)
    {
        for (int j=0; j<input.getWidth(); j++)
        {
            input.setAt(i, j, 1 - pow(tanh(input.getAt(i, j)), 2));
        }
    }
}

void mReLU(Matrix& input)
{
    for (int i=0; i<input.getHeight(); i++)
    {
        for (int j=0; j<input.getWidth(); j++)
        {
            input.setAt(i, j, (input.getAt(i, j)>0) ? input.getAt(i, j) : 0);
        }
    }
}

void mReLUPrime(Matrix& input)
{
    for (int i=0; i<input.getHeight(); i++)
    {
        for (int j=0; j<input.getWidth(); j++)
        {
            input.setAt(i, j, (input.getAt(i, j)>0) ? 1 : 0);
        }
    }
}

float sigmoid(float x)
{
    return (1/(1+exp(-x)));
}

void mSigmoid(Matrix& input)
{
    for (int i=0; i<input.getHeight(); i++)
    {
        for (int j=0; j<input.getWidth(); j++)
        {
            input.setAt(i, j, sigmoid(input.getAt(i, j)));
        }
    }
}


void mSigmoidPrime(Matrix& input)
{
    float x;
    for (int i=0; i<input.getHeight(); i++)
    {
        for (int j=0; j<input.getWidth(); j++)
        {
            x = input.getAt(i, j);
            input.setAt(i, j, sigmoid(x)*(1-sigmoid(x)));
        }
    }
}


