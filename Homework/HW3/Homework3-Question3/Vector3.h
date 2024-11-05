#ifndef VECTOR3_h
#define VECTOR3_h

#include <iostream>

class Vector3
{
    private:
        double var1;
        double var2;
        double var3;

    public:
        Vector3(double v1 = 0.0, double v2 = 0.0, double v3 = 0.0);

        Vector3 operator+(Vector3& other);
        Vector3 operator-(Vector3& other);
        Vector3 operator*(double other);
        Vector3 operator/(double other);
        bool operator==(Vector3& other);

        double operator()(int index);

        friend std::ostream& operator<<(std::ostream& noutput, const Vector3& newOutput);
        friend std::istream& operator>>(std::istream& ninput, Vector3& newInput);

        double displayMagnitude();
};

#endif