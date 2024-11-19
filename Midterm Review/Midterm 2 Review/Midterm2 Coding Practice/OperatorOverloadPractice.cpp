#include <iostream>
#include <cmath>

class OperatorOverload
{
    private:
        int val;

    public:
        OperatorOverload(int v)
        {
            val = v;
        }

        OperatorOverload operator+(OperatorOverload& val2)
        {
            return OperatorOverload(val + val2.val);
        }

        OperatorOverload operator-(OperatorOverload& val2)
        {
            return OperatorOverload(val - val2.val);
        }

        OperatorOverload operator*(double val2)
        {
            return val * val2;
        }

        OperatorOverload operator/(double val2)
        {
            return val / val2;
        }

        bool operator==(OperatorOverload& val2)
        {
            return (val == val2.val);
        }

        OperatorOverload operator->()
        {
            // return &val;
        }

        friend std::ostream& operator<<(std::ostream& newOutput, OperatorOverload& val2)
        {
            newOutput<<val2.val<<std::endl;
            return newOutput;
        }

        friend std::istream& operator>>(std::istream& newInput, OperatorOverload& val2)
        {
            std::cout<<"Enter a value: "<<std::endl;
            newInput>>val2.val;
            return newInput;
        }
};