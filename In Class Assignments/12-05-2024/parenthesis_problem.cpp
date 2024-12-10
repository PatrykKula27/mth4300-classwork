#include <iostream>
#include <stack>

bool isBalanced(std::string str)
{
    std::stack<char> s;

    for (auto& c: str)
    {
        if (c == "(")
        {
            s.push("(");
        }
        else if (c == "[")
        {
            s.push("[");
        }
        else if (c == "{")
        {
            s.push("{");
        }
        else if ((c == ")") && (s.top() == "(") && (!s.empty()))
        {
            s.pop();
        }
        else if ((c == "]") && (s.top() == "[") && (!s.empty()))
        {
            s.pop();
        }
        else if ((c == "}") && (s.top() == "{") && (!s.empty()))
        {
            s.pop();
        }
        else
        {
            return false;
        }
    }

    if (s.empty())
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    std::string s1 ="([{}])()";
    std::string s2 ="([{}]))";
    std::cout<<isBalanced(s1)<<" "<<isBalanced(s2)<<std::endl; 
    return 0;
}