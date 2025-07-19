#include <iostream>
#include <fstream>
#include <string>

std::string replaceText(std::string line, std::string s1, std::string s2)
{
    std::string newLine;
    size_t i = 0;

    while (i < line.length())
    {
        if (line.substr(i, s1.length()) == s1)
        {
            newLine += s2;
            i += s1.length();
        }
        else
        {
            newLine += line[i];
            i++;
        }
    }
    return (newLine);
}

int main(int argc, char **argv)
{
    if (argc != 4)
    {
        std::cout << "Usage: ./sed <filename> <s1> <s2>\n";
        return (1);
    }
    std::string filename = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];
    if (s1.empty())
    {
        std::cout << "Error: s1 cannot be empty\n";
        return (1);
    }
    std::ifstream inputFile(filename.c_str());
    if (!inputFile)
    {
        std::cout << "Error: Cannot open input file\n";
        return (1);
    }
    std::ofstream outputFile((filename + ".replace").c_str());
    if (!outputFile)
    {
        std::cout << "Error: Cannot create output file\n";
        return (1);
    }
    std::string line;
    while (std::getline(inputFile, line))
    {
        std::string modifiedLine = replaceText(line, s1, s2);
        outputFile << modifiedLine << "\n";
    }
    inputFile.close();
    outputFile.close();
    return (0);
}
