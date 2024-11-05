#include <iostream>
#include <vector>

class matrix33
{
    private:
        int row;
        int col;
        std::vector<std::vector<double>> matrix;
    
    public:
        matrix33(int n, int m)
        {
            row = n;
            col = m;
            matrix.resize(m, std::vector<double>(m, 0));
        }

        matrix33(std::vector<std::vector<double>>& matrixInput)
        {
            row = matrixInput.size();
            col = matrixInput[0].size();
            matrix = matrixInput;
        }

        matrix33 operator*(double scalar)
        {
            matrix33 result(row, col);
            for (int x = 0; x < row; x++)
            {
                for (int y = 0; y < col; y++)
                {
                    result.matrix[x][y] = matrix[x][y] * scalar;
                }
            }
            return result;
        }

        matrix33 operator+(matrix33& other)
        {
            matrix33 result(row, col);
            for (int x = 0; x < row; x++)
            {
                for (int y = 0; y < col; y++)
                {
                    result.matrix[x][y] = other.matrix[x][y] + matrix[x][y];
                }
            }
            return result;
        }

        friend std::ostream& operator<<(std::ostream& messageOutput, const matrix33& matrixOutput)
        {
            for (int x = 0; x < row; x++)
            {
                for (int y = 0; y < col; y++)
                {
                    messageOutput<<matrixOutput.matrix[x][y]<<" ";
                }
                messageOutput<<std::endl;
            }
            return messageOutput;
        }

        friend std::istream& operator>>(std::istream& messageInput, matrix33& matrixInput)
        {
            for (int x = 0; x < row; x++)
            {
                for (int y = 0; y < col; y++)
                {
                    std::cout<<"Enter a value for point ("<<x<<", "<<y<<"): "<<std::endl;
                    messageInput>>matrixInput.matrix[x][y];
                }
            }
            return messageInput;
        }

        double determinant()
        {
            if (row != col)
            {
                return 0;
            }
            if (row == 1) && (col == 1)
            {
                return matrix[0][0];
            }
            if (row == 2) && (row == 2)
            {
                return matrix[0][0] * (matrix[1][1] * matrix[2][2] - matrix[1][2] * matrix[2][1]) - matrix[0][1] * (matrix[1][0] * matrix[2][2] - matrix[1][2] * matrix[2][0]) + matrix[0][2] * (matrix[1][0] * matrix[2][1] - matrix[1][1] * matrix[2][0]);
            }

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