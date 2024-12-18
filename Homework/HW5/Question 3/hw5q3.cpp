#include <iostream>
#include <stack>
#include <string>
#include <cctype>

int main()
{
    std::string input;

    std::cout<<"Enter any word: ";
    std::getline(std::cin, input);

    if (palindrome(input))
    {
        std::cout<<"The given word is a palindrome."<<std::endl;
    }
    else
    {
        std::cout<<"The given word is NOT a palindrome."<<std::endl;
    }
    
    return 0;
}

bool palindrome(const std::string& input)
{
    std::stack<char> characters;
    std::string word;

    for (char c: input)
    {
        if (isalnum(c))
        {
            char lowercase = std::tolower(c);
            word += lowercase;
            characters.push(lowercase);
        }
    }

    for (char c: word)
    {
        if (c != characters.top())
        {
            return false;
        }
        characters.pop();
    }

    return true;
}