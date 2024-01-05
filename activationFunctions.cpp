#include "header.h"
#include "matrix.hpp"


void mTanh(Matrix& input)
{
    for (int i=0; i<input.getHeight(); i++)
    {
        for (int j=0; j<input.getWidth(); j++)
        {
            input.setAt(i, j, tanh(input.getValues()[i][j]));
        }
    }
}

void mTanhPrime(Matrix& input)
{
    for (int i=0; i<input.getHeight(); i++)
    {
        for (int j=0; j<input.getWidth(); j++)
        {
            input.setAt(i, j, 1 - pow(tanh(input.getValues()[i][j]), 2));
        }
    }
}

void mReLU(Matrix& input)
{
    for (int i=0; i<input.getHeight(); i++)
    {
        for (int j=0; j<input.getWidth(); j++)
        {
            input.setAt(i, j, (input.getValues()[i][j]>0) ? input.getValues()[i][j] : 0);
        }
    }
}

void mSigmoid(Matrix& input)
{
    for (int i=0; i<input.getHeight(); i++)
    {
        for (int j=0; j<input.getWidth(); j++)
        {
            input.setAt(i, j, 1/(1 + exp(-input.getValues()[i][j])));
        }
    }
}


