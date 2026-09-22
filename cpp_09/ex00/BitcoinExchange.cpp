#include "BitcoinExchange.hpp"
#include <iostream>
#include <sstream>
#include <limits.h>

BitcoinExchange::BitcoinExchange()
{}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
    : _dataBase(other._dataBase)
{}

BitcoinExchange&    BitcoinExchange::operator=(const BitcoinExchange& other)
{
    if (this != &other)
        _dataBase = other._dataBase;

    return *this;
}

BitcoinExchange::~BitcoinExchange()
{}

void  BitcoinExchange::openFile(std::ifstream& file, std::string path)
{
    file.open(path.c_str());
    if (file.fail())
        throw std::runtime_error("failure to load file");

}

bool BitcoinExchange::readDate(std::string& line, const char delimiter, std::string& date)
{
    size_t  pos;

    pos = line.find(delimiter);
    if (pos == std::string::npos)
        return false;

    while (pos > 0 && line[pos - 1] == 32)
        pos--;
    
    date = line.substr(0, pos);

    return true;
}

bool  BitcoinExchange::readValue(std::string& line, const char delimiter, double& value)
{
    std::string tmp;
    size_t  pos;

    pos = line.find(delimiter);
    if (pos == std::string::npos)
        return false;

    while (line[pos + 1] == 32)
        pos++;
    
    tmp = line.substr(pos + 1);

    std::stringstream ss(tmp);
    ss >> value;

    if (ss.fail())
        return false;

    ss >> std::ws;

    if (!ss.eof())
        return false;

    return true;
}

int     BitcoinExchange::convertInt(std::string& str)
{
    std::stringstream ss(str);
    int value;

    ss >> value;

    if (ss.fail())
        throw std::runtime_error("failure to convert number");

    return value;
}

int     BitcoinExchange::getDaysInMonth(int month, int year)
{
    if (month == 4 || month == 6 || month == 9 || month == 11)
        return 30;

    if (month == 2)
    {
        if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
            return 29;
        return 28;
    }

    return 31;
}

bool    BitcoinExchange::loadDate(std::string& sDate, Date& date)
{
    std::string year;
    std::string month;
    std::string day;

    year = sDate.substr(0, 4);
    month = sDate.substr(5, 2);
    day = sDate.substr(8, 2);

    try
    {
        date.year = convertInt(year);
        date.month = convertInt(month);
        date.day = convertInt(day);
    }
    catch(const std::exception&)
    {
        return false;
    }

    return true;
}

bool    BitcoinExchange::isDateFormat(std::string& sDate)
{
    if (sDate.size() != 10)
        return false;

    for (size_t i = 0; i < sDate.size(); i++)
    {
        if (i == 4 || i == 7)
        {
            if (sDate[i] != '-')
                return false;
        }
        else if (!std::isdigit(sDate[i]))
            return false;
    }

    return true;
}

bool    BitcoinExchange::isDateRange(Date& date)
{
    if (date.month < 1 || date.month > 12)
        return false;

    if (date.day < 1 || date.day > getDaysInMonth(date.month, date.year))
        return false;

    return true;
}

bool    BitcoinExchange::isValidDate(std::string& line)
{
    std::string sDate;
    Date    date;

    if (!readDate(line, '|', sDate))
    {
        std::cout << "Error: bad input => " << line << std::endl;
        return false;
    }
    if (sDate.empty())
    {
        std::cout << "Error: missing date => " << line << std::endl;
        return false;
    }

    if (!isDateFormat(sDate))
    {
        std::cout << "Error: invalid date format (expected YYYY-MM-DD) => " << line << std::endl;
        return false;
    }

    if (!loadDate(sDate, date))
    {
        std::cout << "Error: date conversion failed => " << line << std::endl;
        return false;
    }

    if (!isDateRange(date))
    {
        std::cout << "Error: invalid calendar date => " << line << std::endl;
        return false;
    }
    
    return true;
}

bool    BitcoinExchange::isValidValue(std::string& line)
{
    double    value;

    if (!readValue(line, '|', value))
    {
        std::cout << "Error: bad input => " << line << std::endl;
        return false;
    }

    if (value < 0)
    {
        std::cout << "Error: not a positive number." << std::endl;
        return false;
    }

    if (value > 1000)
    {
        std::cout << "Error: too large a number." << std::endl;
        return false;
    }

    return true;
}

void    BitcoinExchange::loadDatabase(std::string path)
{
    std::ifstream file;
    std::string line;
    std::string key;
    double  value;

    try
    {
        openFile(file, path);
    }
    catch(const std::exception& e)
    {
        throw std::runtime_error(e.what());
    }

    if (!std::getline(file, line))
        throw std::runtime_error("empty database");

    if (line != "date,exchange_rate")
        throw std::runtime_error("invalid database header");

    while (std::getline(file, line))
    {
        key.erase();
        if (!readDate(line, ',', key))
            throw std::runtime_error("failure to load database");
        if (!readValue(line, ',', value))
            throw std::runtime_error("failure to load database");
        _dataBase[key] = value;
    }
}

bool    BitcoinExchange::readInput(std::string path)
{
    std::ifstream   file;
    std::string     line;
    
    try
    {
        openFile(file, path);
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << '\n';
        return false;
    }

    if (!std::getline(file, line))
        throw std::runtime_error("empty input");

    if (line != "date | value")
        throw std::runtime_error("invalid input header");

    while(std::getline(file, line))
    {
        if (isValidDate(line) && isValidValue(line))
            std::cout << "OK" << std::endl;
    }

    return true;    
}

void    BitcoinExchange::printAll()
{
    std::map<std::string, double>::iterator it;

    it = _dataBase.begin();

    while(it != _dataBase.end())
    {
        std::cout << it->first << " -> " << it->second << std::endl;
        ++it;
    }
}
