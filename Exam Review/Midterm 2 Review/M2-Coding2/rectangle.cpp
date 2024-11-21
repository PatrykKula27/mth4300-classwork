#include<iostream>
#include "rectangle.h"

// Constructor definition
Rectangle::Rectangle(double width, double height) : width(width), height(height) {}

// Function to calculate the area of the rectangle
double Rectangle::getArea() const
{
    return width * height;
}

// Sets height
double Rectangle::getPerimeter() const
{
    return 2 * (width + height);
}

// Function to calculate the perimeter of the rectangle
double Rectangle::setHeight(double h) const
{
    height=h;
}

// Gets height
void getHeight()
{
    return height;
}