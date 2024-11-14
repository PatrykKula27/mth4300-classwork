#ifndef RECTANGLE_H
#define RECTANGLE_H

class Rectangle
{
    public:
        Rectangle(double width, double height); // Constructor

        double getPerimeter() const; // Member function to get perimeter

        void setHeight(double height) const; // Sets height

        void getHeight(); // Gets height
        
    private:
        double width; // Member variables
        double height;
};
#endif // RECTANGLE_H