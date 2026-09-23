#ifndef BITCOIN_EXCHANGE_HPP
#define BITCOIN_EXCHANGE_HPP

#include <map>
#include <string>
#include <stdexcept>
#include <fstream>

struct Date
{
    int year;
    int month;
    int day;
};


class BitcoinExchange
{
private:
    std::map<std::string, double> _dataBase;

    bool    openFile(std::ifstream& file, const std::string& path) const;
    bool    readDate(const std::string& line, const char delimiter, std::string& date) const;
    bool    readValue(const std::string& line, const char delimiter, double& value) const;
    int     convertInt(const std::string& str) const;
    int     getDaysInMonth(int month, int year) const;
    bool    loadDate(const std::string& sDate, Date& date) const;
    bool    isDateFormat(const std::string& sDate) const;
    bool    isDateRange(const Date& date) const;

    bool    isValidDate(const std::string& line) const;
    bool    isValidValue(const std::string& line) const;
    bool    isValidDatabaseDate(const std::string& line) const;
    bool    isValidDatabaseValue(const std::string& line) const;
    std::map<std::string, double>::const_iterator findDate(const std::string& date) const;
    bool    calculateFinalPrice(const std::string& line) const;

public:
    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange& other);
    BitcoinExchange&    operator=(const BitcoinExchange& other);
    ~BitcoinExchange();

    void    loadDatabase(const std::string& path);
    void    readInput(const std::string& path) const;
    bool    isEmpty() const;
    //void    printAll();
};


#endif