#include <iostream>
#include <fstream>
#include <string>

int main()
{
    // Reading from a file
    std::ifstream inputFile("test1.txt");
    if (!inputFile.is_open())
    {
        std::cerr<<"Error"<<std::endl;
        return 1;
    }

    std::string line1;
    while (std::getline(inputFile, line1))
    {
        std::cout<<line1<<std::endl;
    }
    inputFile.close();

    // Writing to a file
    std::ofstream outputFile("test2.txt");
    if (!outputFile.is_open())
    {
        std::cerr<<"Error"<<std::endl;
        return 1;
    }

    outputFile<<"This is a line of text.";
    outputFile<<"This is another line of text.";
    outputFile.close();

    // Reading from and Writing to a file
    std::fstream generalFile("test3.txt" , std::ios::in | std::ios::out | std::ios::app);
    if (!generalFile.is_open())
    {
        std::cerr<<"Erorr"<<std::endl;
        return 1;
    }

    generalFile<<"This is yet another line of text.";
    generalFile<<"This is a fourth line of text.";

    generalFile.seekg(0, std::ios::beg);
    std::string line2;
    while (std::getline(generalFile, line2))
    {
        std::cout<<line2<<std::endl;
    }

    generalFile.close();

    // Copying file contents
    std::ifstream inputFile2("test4.txt");
    std::ofstream outputFile2("test5.txt");

    if (!inputFile2.is_open() || !outputFile2.is_open())
    {
        std::cerr<<"Error"<<std::endl;
        return 1;
    }

    std::string line3;

    while (std::getline(inputFile2, line3))
    {
        outputFile2<<line3<<std::endl;
    }

    inputFile2.close();
    outputFile2.close();

    return 0;
}