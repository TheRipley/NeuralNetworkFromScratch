#include "header.h"
#include "matrix.hpp"

Matrix::Matrix()
    : height(1), width(1), values({{0.0f}}) {}
    
Matrix::Matrix(int height, int width)
    : height(height), width(width) 
    {
        for (int i=0; i<height; i++)
        {
            std::vector<float> row;
            for (int j=0; j<width; j++)
            {
                row.push_back(0.0f);
            }
            values.push_back(row);
        }
    }

Matrix::Matrix(std::vector<std::vector<float>> values)
    : height(values.size()), width(values[0].size()), values(values) {}

Matrix::Matrix(const Matrix& other)
    : height(other.height), width(other.width), values(other.values) {}

int Matrix::getHeight() const {return height;}
int Matrix::getWidth() const {return width;}
std::vector<std::vector<float>> Matrix::getValues() const {return values;}

void Matrix::setAt(int y, int x, float newVal) {values[y][x] = newVal;}


Matrix Matrix::Transpose()
{
    Matrix transposed(width, height);
    //transposed.values.clear();

    for (int i=0; i<height; i++)
    {
        for (int j=0; j<width; j++)
        {
            transposed.values[j][i] = values[i][j];
        }
    }
    return transposed;
}

void Matrix::setRandomValues()
{
    for (int i=0; i<height; i++)
        {
            for (int j=0; j<width; j++)
            {
                values[i][j] = distribution(generator);
            }
        }
}

Matrix Matrix::sechSquared()
{
    Matrix output = *this;
    for (int i = 0; i < height; ++i) 
    {
        output.values[i][0] = pow(1/cosh(output.values[i][0]), 2);
    }
    return output;
}

Matrix& Matrix::operator=(const Matrix& other) {
    if (this != &other) {  // Check for self-assignment
        height = other.height;
        width = other.width;
        values = other.values;
    }
    return *this;
}

Matrix Matrix::operator*(const Matrix& other) const
{
    if (this->width != other.getHeight())
    {
        std::cerr << "Error: The two matrices can't be multiplied." << std::endl;
        return Matrix();
    }

    Matrix returnMatrix(this->height, other.getWidth());

    for (int i = 0; i < this->height; ++i) {
        for (int j = 0; j < other.getWidth(); ++j) {
            float sum = 0.0;
            for (int k = 0; k < this->width; ++k) {
                sum += this->values[i][k] * other.values[k][j];
            }
            returnMatrix.values[i][j] = sum;
        }
    }

    return returnMatrix;

}

Matrix Matrix::operator*(const float& scalar) const
{

    Matrix returnMatrix(this->height, this->width);

    for (int i = 0; i < this->height; ++i) {
        for (int j = 0; j < this->width; ++j) {
            returnMatrix.values[i][j] = this->values[i][j] * scalar;
        }
    }

    return returnMatrix;
}

Matrix Matrix::operator+(const Matrix& other) const
{
    if (this->width != other.getWidth() or this->height != other.getHeight())
    {
        std::cerr << "Error: The two matrices can't be added." << std::endl;
        return Matrix();
    }

    Matrix returnMatrix(this->height, other.getWidth());

    for (int i = 0; i < this->height; ++i) {
        for (int j = 0; j < this->width; ++j) {
            returnMatrix.values[i][j] = this->values[i][j] + other.values[i][j];
        }
    }

    return returnMatrix;
}

Matrix Matrix::operator-(const Matrix& other) const
{
    if (this->width != other.getWidth() or this->height != other.getHeight())
    {
        std::cerr << "Error: The two matrices can't be added." << std::endl;
        return Matrix();
    }

    Matrix returnMatrix(this->height, other.getWidth());

    for (int i = 0; i < this->height; ++i) {
        for (int j = 0; j < this->width; ++j) {
            returnMatrix.values[i][j] = this->values[i][j] - other.values[i][j];
        }
    }

    return returnMatrix;
}

Matrix HadamarProduct(const Matrix& matrix1, const Matrix& matrix2)
{
    if (matrix1.getHeight() != matrix2.getHeight() || matrix1.getWidth() != matrix2.getWidth())
        
    {
        std::cerr << "Error: Matrix dimensions mismatch in HadamarProduct." << std::endl;
        return Matrix(); // Return an empty matrix or handle the error appropriately
    }

    Matrix output(matrix1.getHeight(), matrix1.getWidth());
    for (int i = 0; i < output.getHeight(); i++)
    {
        for (int j = 0; j < output.getWidth(); j++)
        {
            output.setAt(i, j, output.getValues()[i][j] * matrix2.getValues()[i][j]);
        }
    }

    return output;
}

std::ostream& operator<<(std::ostream &stream, const Matrix &matrix)
{
   for (int i=0; i<matrix.getHeight(); i++) 
   {
        for (int j=0; j<matrix.getWidth(); j++)
        {
            stream << matrix.getValues()[i][j] << "\t";
        }
        stream << std::endl;
   }
   return stream;
}