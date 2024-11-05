#include <iostream>

class matrix33
{
    private:
        double matrix[3][3];
    
    public:
        matrix33() {}

        matrix33(double matrixInput[3][3])
        {
            for (int x = 0; x < 3; x++)
            {
                for (int y = 0; y < 3; y++)
                {
                    matrix[x][y] = matrixInput[x][y];
                }
            }
        }

        matrix33 operator*(matrix33& separateMatrix)
        {
            matrix33 result;
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

        matrix33 operator*(double scalar)
        {
            matrix33 result;
            for (int x = 0; x < 3; x++)
            {
                for (int y = 0; y < 3; y++)
                {
                    result.matrix[x][y] = matrix[x][y] * scalar;
                }
            }
            return result;
        }

        matrix33 operator+(matrix33& other)
        {
            matrix33 result;
            for (int x = 0; x < 3; x++)
            {
                for (int y = 0; y < 3; y++)
                {
                    result.matrix[x][y] = other.matrix[x][y] + matrix[x][y];
                }
            }
            return result;
        }

        friend std::ostream& operator<<(std::ostream& messageOutput, const matrix33& matrixOutput)
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

        friend std::istream& operator>>(std::istream& messageInput, matrix33& matrixInput)
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

        double determinant()
        {
            double determinantValue = matrix[0][0] * (matrix[1][1] * matrix[2][2] - matrix[1][2] * matrix[2][1]) - matrix[0][1] * (matrix[1][0] * matrix[2][2] - matrix[1][2] * matrix[2][0]) + matrix[0][2] * (matrix[1][0] * matrix[2][1] - matrix[1][1] * matrix[2][0]);
            return determinantValue;
        }
};

int main()
{
    matrix33 matrix1;
    matrix33 matrix2;
    double scalar;

    std::cout<<"Enter an Input for Matrix 1: ";
    std::cin>>matrix1;
    std::cout<<std::endl;

    std::cout<<"Enter an Input for Matrix 2: ";
    std::cin>>matrix2;
    std::cout<<std::endl;

    std::cout<<"Enter an Input for Scalar Multiplication: ";
    std::cin>>scalar;
    std::cout<<std::endl;

    std::cout<<"Matrix 1 + Matrix 2: "<<std::endl;
    std::cout<<matrix1 + matrix2<<std::endl;

    std::cout<<"Matrix multiplication: "<<std::endl;
    std::cout<<matrix1 * matrix2<<std::endl;

    std::cout<<"Matrix 1 - Scalar Multiplication:"<<matrix1 * scalar<<std::endl;
    std::cout<<"Matrix 2 - Scalar Multiplication: "<<matrix2 * scalar<<std::endl;
    std::cout<<"Matrix 1 - Determinant: "<<matrix1.determinant()<<std::endl;
    std::cout<<"Matrix 2 - Determinant: "<<matrix2.determinant()<<std::endl;
    return 0;
}