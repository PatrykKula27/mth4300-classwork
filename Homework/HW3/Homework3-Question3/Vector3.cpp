#include "Vector3.h"
#include <iostream>
#include <cmath>

Vector3::Vector3(double v1, double v2, double v3):  var1(v1), var2(v2), var3(v3) {};

Vector3 Vector3::operator+(Vector3& other) // Pass by reference
{
    return Vector3(var1 + other.var1, var2 + other.var2, var3 + other.var3);
}

Vector3 Vector3::operator-(Vector3& other)
{
    return Vector3(var1 - other.var1, var2 - other.var2, var3 - other.var3);
}

Vector3 Vector3::operator*(double other)
{
    return Vector3(var1*other, var2*other, var3*other);
}

Vector3 Vector3::operator/(double other)
{
    return Vector3(var1/other, var2/other, var3/other);
}

bool Vector3::operator==(Vector3& other)
{
    return (var1 == other.var1) && (var2 == other.var2) && (var3 == other.var3);
}

double Vector3::operator()(int index)
{
    if (index == 0)
    {
        return var1;
    }
    else if (index == 1)
    {
        return var2;
    }
    else //if (index == 2)
    {
        return var3;
    }
}

std::ostream& operator<<(std::ostream& noutput, const Vector3& newOutput)
{
    noutput<<"("<<newOutput.var1<<", "<<newOutput.var2<<", "<<newOutput.var3<<")"<<std::endl;
    return noutput;
}

std::istream& operator>>(std::istream& ninput, Vector3& newInput)
{
    std::cout<<"Enter a Point (x, y, z): "<<std::endl;
    ninput>>newInput.var1>>newInput.var2>>newInput.var3;
    return ninput;
}

double Vector3::displayMagnitude()
{
    return sqrt(pow(var1,2) + pow(var2, 2) + pow(var3, 2));
}