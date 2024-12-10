#include <iostream>
#include <cmath>

/*
Creata a class for a 3D points.
Overload + and - to add corresponding indices,
overload * and \ for scalar multiplication\division.
Overload extraction and insertion operators to print and input points,
and overload == to check if two points are equal.
Finally write a function that returns the magnitude of the point and prints it.
*/

class points3D
{
    private:
        double var1;
        double var2;
        double var3;

    public:
        points3D(double v1 = 0.0, double v2 = 0.0, double v3 = 0.0)
        {
            var1 = v1;
            var2 = v2;
            var3 = v3;
        }

        points3D operator+(points3D& other) // Pass by reference
        {
            return points3D(var1 + other.var1, var2 + other.var2, var3 + other.var3);
        }

        points3D operator-(points3D& other)
        {
            return points3D(var1 - other.var1, var2 - other.var2, var3 - other.var3);
        }

        points3D operator*(double other)
        {
            return points3D(var1*other, var2*other, var3*other);
        }

        points3D operator/(double other)
        {
            return points3D(var1/other, var2/other, var3/other);
        }

        bool operator==(points3D& other)
        {
            return (var1 == other.var1) && (var2 == other.var2) && (var3 == other.var3);
        }

        friend std::ostream& operator<<(std::ostream& noutput, const points3D& newOutput)
        {
            noutput<<"("<<newOutput.var1<<", "<<newOutput.var2<<", "<<newOutput.var3<<")"<<std::endl;
            return noutput;
        }

        friend std::istream& operator>>(std::istream& ninput, points3D& newInput)
        {
            std::cout<<"Enter a Point (x, y, z): "<<std::endl;
            ninput>>newInput.var1>>newInput.var2>>newInput.var3;
            return ninput;
        }

        double displayMagnitude()
        {
            return sqrt(pow(var1,2) + pow(var2, 2) + pow(var3, 2));
        }
};

int main()
{
    points3D p1(1.0, 2.0, 3.0);
    points3D p2(10.0, 5.0, 7.5);

    points3D p3=p1+p2;
    points3D p4=p1-p2;
    points3D p5=p1*2;
    points3D p6=p2/5;

    points3D p7;
    std::cin>>p7;

    bool check = p1 == p2;
    std::cout<<p1<<std::endl;
    std::cout<<p2<<std::endl;
    std::cout<<p3<<std::endl;
    std::cout<<p4<<std::endl;
    std::cout<<p5<<std::endl;
    std::cout<<p6<<std::endl;
    std::cout<<p7<<std::endl;
    std::cout<<check<<std::endl;
    std::cout<<"Magnitude: "<<p1.displayMagnitude()<<std::endl; 
    return 0;
}