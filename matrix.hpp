#include "header.h"


#ifndef MATRIX_HPP
#define MATRIX_HPP
struct Matrix
{
private:
    int height;
    int width;
    std::vector<std::vector<float>> values;
public:
    Matrix();
    Matrix(int, int);
    Matrix(std::vector<std::vector<float>>);
    Matrix(const Matrix& other);

    int getHeight() const;
    int getWidth() const;
    std::vector<std::vector<float>> getValues() const;

    void setAt(int, int, float);
    float getAt(int, int) const;

    Matrix Transpose();
    void setRandomValues();
    Matrix sechSquared();
    Matrix sumAlongRows() const;
    

    Matrix operator+(const Matrix&) const;
    Matrix operator-(const Matrix&) const;
    Matrix operator*(const Matrix&) const;
    Matrix operator*(const float&) const;
    Matrix& operator=(const Matrix&);
};

std::ostream& operator<<(std::ostream&, const Matrix&);

#endif 