#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
#include <map>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <string>

class BitcoinExchange
{
public:
    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange& other);
    BitcoinExchange& operator=(const BitcoinExchange& other);
    ~BitcoinExchange();  
};

bool    storeData(const std::string &fileName, std::map<std::string, double> &bitCoin);
bool    openFile(const std::string &fileName, std::map<std::string, double> &bitCoin);

#endif