#include "BitcoinExchange.hpp"

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
    // std::map<std::string, double> ::iterator it;
    // for (it = bitCoins.begin() ; it != bitCoins.end() ; it++)
    // {
    //     std::cout << it->first << " -> " << it->second << std::endl;
    // }
    
    std::string inputF = argv[1];
    if (!openFile(inputF, bitCoins))
    {
        std::cerr << "Error : could't open input file" << std::endl;
        return (1);
    }
}