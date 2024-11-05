#ifndef MATRIX33_h
#define MATRIX33_h

#include <iostream>

class Matrix33
{
    private:
        double matrix[3][3];
    
    public:
        Matrix33();
        
        Matrix33(double matrixInput[3][3]);

        Matrix33 operator*(Matrix33& separateMatrix);
        Matrix33 operator*(double scalar);
        Matrix33 operator+(Matrix33& other);

        double operator() (int row, int col);

        friend std::ostream& operator<<(std::ostream& messageOutput, const Matrix33& matrixOutput);
        friend std::istream& operator>>(std::istream& messageInput, Matrix33& matrixInput);

        double determinant();
};

#endif