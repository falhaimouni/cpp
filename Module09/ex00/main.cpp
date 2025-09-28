#include "BitcoinExchange.hpp"

#include <map>
#include <fstream>
#include <sstream>
#include <cstdlib>

bool    openFile(const std::string &fileName)
{
    double valueD;
    std::ifstream inputFile(fileName.c_str());
    if (!inputFile)
    {
        std::cerr << "Error: bad input => " << fileName << std::endl;
        return false;
    }
    std::string line;
    std::string head;
    std::getline(inputFile, head);
    while (std::getline(inputFile, line))
    {
        std::string key;
        std::string value;
        std::stringstream s(line);
        char del = '|';
        std::getline(s, key, del);
        std::getline(s, value, del);
        std::stringstream valStream(value);
        if (!(valStream >> valueD))
        {
            std::cerr << "Error: bad value in CSV -> " << value << std::endl;
            continue;
        }
        std::cout << "Value :" << valueD << " ";
        std::cout << "key :" << key << std::endl;
    }
    return true;
}

bool    storeData(const std::string &fileName, std::map<std::string, double> &bitCoin)
{
    double valueD;
    std::ifstream inputFile(fileName.c_str());
    if (!inputFile)
    {
        std::cout << "Error: Cannot open input file\n";
        return false;
    }
    std::string line;
    std::string head;
    std::getline(inputFile, head);
    while (std::getline(inputFile, line))
    {
        std::string key;
        std::string value;
        std::stringstream s(line);
        char del = ',';
        std::getline(s, key, del);
        std::getline(s, value, del);
        std::stringstream valStream(value);
        // Here i use stringstream instead of atof function because 
        // If the string is not a valid number, atof just returns 0.0
        if (!(valStream >> valueD)) // so here if its not a valid num it will give and error 
        {
            std::cerr << "Error: bad value in CSV -> " << value << std::endl;
            continue;
        }
        bitCoin.insert(std::make_pair(key, valueD));
    }
    return true;
}

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << "Error : invalid number of argumets." << std::endl;
        return 1 ; 
    }
    std::string fileName = "cpp_09/data.csv";
    std::map<std::string, double> bitCoins;
    if (!storeData(fileName, bitCoins))
    {
        std::cerr << "Error : could't open database file" << std::endl;
        return (1);
    }
    std::string inputF = argv[1];
    if (!openFile(inputF))
    {
        std::cerr << "Error : could't open input file" << std::endl;
        return (1);
    }
}