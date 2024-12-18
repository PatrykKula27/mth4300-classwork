#include <iostream>
#include <string>
#include <cctype>
#include <unordered_map>

bool anagram(const std::string &inputOne, const std::string &inputTwo)
{
    if (inputOne.length() != inputTwo.length())
    {
        return false;
    }

    std::unordered_map<char, int> characters;

    for (char c: inputOne)
    {
        characters[c]++;
    }

    for (char c: inputTwo)
    {
        characters[c]--;
        if (characters[c] < 0)
        {
            return false;
        }
    }

    return true;
}

int main()
{

    std::string wordOne;
    std::string wordTwo;

    std::cout<<"Enter a word: ";
    std::cin>>wordOne;
    std::cout<<std::endl;

    std::cout<<"Enter another word: ";
    std::cin>>wordTwo;
    std::cout<<std::endl;

    if (anagram(wordOne, wordTwo))
    {
        std::cout<<wordOne<<" and "<<wordTwo<<" are anagrams of each other."<<std::endl;
    }
    else
    {
        std::cout<<wordOne<<" and "<<wordTwo<<" are NOT anagrams of each other."<<std::endl;
    }
    return 0;
}