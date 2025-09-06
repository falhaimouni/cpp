#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
    std::cout << "ScalarConverter constructor called" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter&)
{
    std::cout << "ScalarConverter copy constructor called" << std::endl;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter&)
{
    std::cout << "ScalarConverter assignment operator called" << std::endl;
    return *this;
}

ScalarConverter::~ScalarConverter()
{
    std::cout << "ScalarConverter destructor called" << std::endl;
}

void ScalarConverter::printChar(double d)
{
    if (std::isnan(d) || d < 0 || d > 127)
        std::cout << "char: impossible" << std::endl;
    else if (isprint(static_cast<char>(d)))
        std::cout << "char: '" << static_cast<char>(d) << "'" << std::endl;
    else
        std::cout << "char: Non displayable" << std::endl;
}

void ScalarConverter::printInt(double d)
{
    if (std::isnan(d) || d < std::numeric_limits<int>::min() || d > std::numeric_limits<int>::max())
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(d) << std::endl;
}

void ScalarConverter::printFloat(double d)
{
    float f = static_cast<float>(d);
    std::cout << "float: ";

    if (std::isnan(f))
        std::cout << "nanf";
    else if (std::isinf(f))
    {
        if (f < 0)
            std::cout << "-inff";
        else
            std::cout << "+inff";
    }
    else
    {
        std::ostringstream oss;
        oss << std::setprecision(7) << f;
        std::string result = oss.str();
        if (result.find('.') == std::string::npos && result.find('e') == std::string::npos)
            result += ".0";
        result += "f";
        std::cout << result;
    }
    std::cout << std::endl;
}


void ScalarConverter::printDouble(double d)
{
    std::cout << "double: ";
    if (std::isnan(d))
        std::cout << "nan";
    else if (std::isinf(d))
    {
        if (d < 0)
            std::cout << "-inf";
        else
            std::cout << "+inf";
    }
    else
    {
        std::ostringstream oss;
        oss << std::setprecision(15) << d;
        std::string result = oss.str();
        if (result.find('.') == std::string::npos && result.find('e') == std::string::npos)
            result += ".0";

        std::cout << result;
    }
    std::cout << std::endl;
}


bool ScalarConverter::isCharLiteral(const std::string& str)
{
    return str.length() == 1 && !isdigit(str[0]);
}

bool ScalarConverter::isInt(const std::string& str)
{
    std::stringstream ss(str);
    int i;
    ss >> i;
    return !ss.fail() && ss.eof();
}

bool ScalarConverter::isFloat(const std::string& str)
{
    if (str == "nanf" || str == "+inff" || str == "-inff")
        return true;
    if (str[str.length() - 1] != 'f')
        return false;
    std::string numPart = str.substr(0, str.length() - 1);
    std::stringstream ss(numPart);
    float f;
    ss >> f;
    return !ss.fail() && ss.eof();
}

bool ScalarConverter::isDouble(const std::string& str)
{
    if (str == "nan" || str == "+inf" || str == "-inf")
        return true;

    std::stringstream ss(str);
    double d;
    ss >> d;
    return !ss.fail() && ss.eof();
}

void ScalarConverter::convert(const std::string& str)
{
    double value = 0.0;
    if (str == "nan" || str == "nanf")
        value = std::numeric_limits<double>::quiet_NaN();
    else if (str == "+inf" || str == "+inff")
        value = std::numeric_limits<double>::infinity();
    else if (str == "-inf" || str == "-inff")
        value = -std::numeric_limits<double>::infinity();
    else if (str.empty())
    {
        std::cout << "Invalid input: empty string" << std::endl;
        return;
    }
    else if (isCharLiteral(str))
        value = static_cast<double>(str[0]);
    else if (isInt(str))
    {
        std::stringstream ss(str);
        int i;
        ss >> i;
        value = static_cast<double>(i);
    }
    else if (isFloat(str))
    {
        std::string numPart = str.substr(0, str.length() - 1);
        std::stringstream ss(numPart);
        float f;
        ss >> f;
        value = static_cast<double>(f);
    }
    else if (isDouble(str))
    {
        std::stringstream ss(str);
        double d;
        ss >> d;
        value = d;
    }
    else
    {
        std::cout << "Invalid input" << std::endl;
        return;
    }

    if (std::isnan(value) || std::isinf(value))
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        if (str[str.length() - 1] == 'f')
            std::cout << "float: " << str << std::endl;
        else
            std::cout << "float: " << str << "f" << std::endl;
        std::cout << "double: " << (str[str.length() - 1] == 'f' ? str.substr(0, str.length() - 1) : str) << std::endl;
        return;
    }
    printChar(value);
    printInt(value);
    printFloat(value);
    printDouble(value);
}

