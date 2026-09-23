#include "BitcoinExchange.hpp"
#include <iostream>
#include <sstream>
#include <limits>
#include <cctype>

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

bool  BitcoinExchange::openFile(std::ifstream& file, const std::string& path) const
{
    file.open(path.c_str());
    if (file.fail())
        return false;

    return true;
}

bool BitcoinExchange::readDate(const std::string& line, const char delimiter, std::string& date) const
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

bool  BitcoinExchange::readValue(const std::string& line, const char delimiter, double& value) const
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

int     BitcoinExchange::convertInt(const std::string& str) const
{
    std::stringstream ss(str);
    int value;

    ss >> value;

    if (ss.fail())
        throw std::runtime_error("failure to convert number");

    return value;
}

int     BitcoinExchange::getDaysInMonth(int month, int year) const
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

bool    BitcoinExchange::loadDate(const std::string& sDate, Date& date) const
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

bool    BitcoinExchange::isDateFormat(const std::string& sDate) const
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

bool    BitcoinExchange::isDateRange(const Date& date) const
{
    if (date.month < 1 || date.month > 12)
        return false;

    if (date.day < 1 || date.day > getDaysInMonth(date.month, date.year))
        return false;

    return true;
}

bool    BitcoinExchange::isValidDate(const std::string& line) const
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
        std::cout << "Error: bad input => " << line << std::endl;
        return false;
    }

    if (!isDateFormat(sDate))
    {
        std::cout << "Error: invalid date format (expected YYYY-MM-DD) => " << sDate << std::endl;
        return false;
    }

    if (!loadDate(sDate, date))
    {
        std::cout << "Error: date conversion failed => " << line << std::endl;
        return false;
    }

    if (!isDateRange(date))
    {
        std::cout << "Error: invalid calendar date => " << sDate << std::endl;
        return false;
    }
    
    return true;
}

bool    BitcoinExchange::isValidValue(const std::string& line) const
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

bool    BitcoinExchange::isValidDatabaseDate(const std::string& line) const
{
    std::string sDate;
    Date    date;

    if (!readDate(line, ',', sDate))
        return false;

    if (sDate.empty())
        return false;

    if (!isDateFormat(sDate))
        return false;

    if (!loadDate(sDate, date))
        return false;

    if (!isDateRange(date))
        return false;
    
    return true;
}

bool    BitcoinExchange::isValidDatabaseValue(const std::string& line) const
{
    double    value;

    if (!readValue(line, ',', value))
        return false;

    if (value < 0)
        return false;

    return true;
}

std::map<std::string, double>::const_iterator BitcoinExchange::findDate(const std::string& date) const
{
    std::map<std::string, double>::const_iterator it;

    it = _dataBase.lower_bound(date);

    if (it == _dataBase.end())
    {
        if (!_dataBase.empty())
            --it;
        return it;
    }

    if (it->first != date && it != _dataBase.begin())
        --it;

    return it;
}

bool    BitcoinExchange::calculateFinalPrice(const std::string& line) const
{
    std::map<std::string, double>::const_iterator it;
    std::string date;
    double  amount;
    double  finalPrice;
    double  rate;
    double  maxDouble;

    if (!readDate(line, '|', date))
        return false;

    if (!readValue(line, '|', amount))
        return false;

    it = findDate(date);

    if (it->first > date)
    {
        std::cout << "Error: date not found." << std::endl;
        return true;
    }

    rate = it->second;
    maxDouble = std::numeric_limits<double>::max();

    if (amount > 1.0 && rate > maxDouble / amount)
    {
        std::cout << "Error: result too large." << std::endl;
        return true;
    }

    finalPrice = it->second * amount;
    
    std::cout << date << " => " << amount << " = " << finalPrice << std::endl;

    return true;
}

bool    BitcoinExchange::isEmpty() const
{
    if (_dataBase.empty())
        return true;

    return false;
}

void    BitcoinExchange::loadDatabase(const std::string& path)
{
    std::ifstream file;
    std::string line;
    std::string key;
    double  value;

    if (!openFile(file, path))
        throw std::runtime_error("Error: could not open file.");

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
        
        if (!isValidDatabaseDate(line) || !isValidDatabaseValue(line))
            throw std::runtime_error("invalid database");
        
        _dataBase[key] = value;
    }
}

void    BitcoinExchange::readInput(const std::string& path) const
{
    std::ifstream   file;
    std::string     line;
    
    if (!openFile(file, path))
        throw std::runtime_error("Error: could not open file.");

    if (!std::getline(file, line))
        throw std::runtime_error("empty input");

    if (line != "date | value")
        throw std::runtime_error("invalid input header");

    while(std::getline(file, line))
    {
        if (isValidDate(line) && isValidValue(line))
        {
            if (!calculateFinalPrice(line))
                throw std::runtime_error("failure to calculate final price");
        }
    }
}

/* void    BitcoinExchange::printAll()
{
    std::map<std::string, double>::iterator it;

    it = _dataBase.begin();

    while(it != _dataBase.end())
    {
        std::cout << it->first << " -> " << it->second << std::endl;
        ++it;
    }
} */
