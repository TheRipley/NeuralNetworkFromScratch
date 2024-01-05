#pragma once
#include <vector>
#include <iostream>
#include <random>
#include <math.h>

#include "matrix.hpp"
#include "layer.hpp"
#include "network.hpp"

#define TANH 1
#define RELU 2
#define SIGMOID 3


extern std::default_random_engine generator;
extern std::uniform_real_distribution<float> distribution;

void mTanh(Matrix&);
void mTanhPrime(Matrix& input);

void mReLU(Matrix&);
void mSigmoid(Matrix&);

Matrix HadamarProduct(const Matrix&, const Matrix&);