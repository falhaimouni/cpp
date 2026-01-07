#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << "Error : invalid number of argumets." << std::endl;
        return 1 ; 
    }
    std::string fileName = "data.csv";
    std::map<std::string, double> bitCoins;
    if (!storeData(fileName, bitCoins))
    {
        std::cerr << "Error : could't open database file" << std::endl;
        return (1);
    }
    std::string inputF = argv[1];
    if (!openFile(inputF, bitCoins))
        return (1);
}