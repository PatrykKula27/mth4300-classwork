#include "Matrix33.h"
#include "Vector3.h"
#include <iostream>

Vector3 returnAxB(Matrix33& A, Vector3& x);

int main()
{
    //Return Ax=B Function
    Matrix33 valueA;
    Vector3 valueX;
    Vector3 valueB;

    std::cout<<"Enter input for Matrix33 A: ";
    std::cin>>valueA;
    std::cout<<std::endl;

    std::cout<<"Enter input for Vector3 X: ";
    std::cin>>valueX;
    std::cout<<std::endl;

    valueB = returnAxB(valueA, valueX);

    std::cout<<"Ax = B, B = "<<valueB<<std::endl;
    return 0;
}

Vector3 returnAxB(Matrix33& A, Vector3& x)
{
    double b1 = A(0, 0) * x(0) + A(0, 1) * x(1) + A(0, 2) * x(2);
    double b2 = A(1, 0) * x(0) + A(1, 1) * x(1) + A(1, 2) * x(2);
    double b3 = A(2, 0) * x(0) + A(2, 1) * x(1) + A(2, 2) * x(2);

    return Vector3(b1, b2, b3);
}