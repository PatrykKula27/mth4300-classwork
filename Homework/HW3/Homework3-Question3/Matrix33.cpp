#include "Matrix33.h"
#include <iostream>
#include <cmath>

        Matrix33::Matrix33() {}
        
        Matrix33::Matrix33(double matrixInput[3][3])
        {
            for (int x = 0; x < 3; x++)
            {
                for (int y = 0; y < 3; y++)
                {
                    matrix[x][y] = matrixInput[x][y];
                }
            }
        }

        Matrix33 Matrix33::operator*(Matrix33& separateMatrix)
        {
            Matrix33 result;
            for (int x = 0; x < 3; x++)
            {
                for (int y = 0; y < 3; y++)
                {
                    result.matrix[x][y] = 0;
                    for (int z = 0; z < 3; z++)
                    {
                        result.matrix[x][y] += matrix[x][z] * separateMatrix.matrix[z][y];
                    }
                }
            }
            return result;
        }

        Matrix33 Matrix33::operator*(double scalar)
        {
            Matrix33 result;
            for (int x = 0; x < 3; x++)
            {
                for (int y = 0; y < 3; y++)
                {
                    result.matrix[x][y] = matrix[x][y] * scalar;
                }
            }
            return result;
        }

        Matrix33 Matrix33::operator+(Matrix33& other)
        {
            Matrix33 result;
            for (int x = 0; x < 3; x++)
            {
                for (int y = 0; y < 3; y++)
                {
                    result.matrix[x][y] = other.matrix[x][y] + matrix[x][y];
                }
            }
            return result;
        }

        double Matrix33::operator()(int row, int col)
        {
            return matrix[row][col];
        }

        std::ostream& operator<<(std::ostream& messageOutput, const Matrix33& matrixOutput)
        {
            for (int x = 0; x < 3; x++)
            {
                for (int y = 0; y < 3; y++)
                {
                    messageOutput<<matrixOutput.matrix[x][y]<<" ";
                }
                messageOutput<<std::endl;
            }
            return messageOutput;
        }

        std::istream& operator>>(std::istream& messageInput, Matrix33& matrixInput)
        {
            for (int x = 0; x < 3; x++)
            {
                for (int y = 0; y < 3; y++)
                {
                    std::cout<<"Enter a value for point ("<<x<<", "<<y<<"): "<<std::endl;
                    messageInput>>matrixInput.matrix[x][y];
                }
            }
            return messageInput;
        }

        double Matrix33::determinant()
        {
            double determinantValue = matrix[0][0] * (matrix[1][1] * matrix[2][2] - matrix[1][2] * matrix[2][1]) - matrix[0][1] * (matrix[1][0] * matrix[2][2] - matrix[1][2] * matrix[2][0]) + matrix[0][2] * (matrix[1][0] * matrix[2][1] - matrix[1][1] * matrix[2][0]);
            return determinantValue;
        }