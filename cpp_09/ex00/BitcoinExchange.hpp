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

    void    openFile(std::ifstream& file, std::string path);
    std::string     readDate(std::string& line, const char delimiter);
    double  readValue(std::string& line, const char delimiter);
    int     fitsInInt(std::string& str);
    int     convertInt(std::string& str);
    int     getDaysInMonth(int month, int year);
    bool    loadDate(std::string& sDate, Date& date);
    bool    isDateFormat(std::string& sDate);
    bool    isDateRange(Date& date);

    bool    isValidDate(std::string& line);
    bool    isValidValue(std::string& line);

public:
    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange& other);
    BitcoinExchange&    operator=(const BitcoinExchange& other);
    ~BitcoinExchange();

    bool    loadDatabase(std::string path);
    bool    readInput(std::string path);
    void    printAll();
};


#endif