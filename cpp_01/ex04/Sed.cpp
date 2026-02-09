#include "Sed.hpp"

Sed::Sed(std::string s1, std::string s2, std::string filename)
{
    this->s1 = s1;
    this->s2 = s2;
    this->filename = filename;
}

bool    Sed::openFile(std::ifstream& in, std::ofstream& out)
{
    std::string nameOut;

    nameOut = filename + ".replace";
    in.open(filename.c_str());
    if(!in)
    {
        std::cout << RED << "failed to open input file\n" << RESET;
        return (false);    
    }
    out.open(nameOut.c_str());
    if(!out)
    {
        std::cout << RED << "failed to open output file\n" << RESET;
        return (false);
    }
    return (true);
}

bool    Sed::checkArg(void) const
{
    if(filename.empty())
        return (false);
    if(s1.empty())
        return (false);
    return (true);
}

bool    Sed::replaceWords(void)
{
    std::size_t     start;
    std::size_t     pos;
    std::string     line;
    std::string     result;
    std::ifstream   in;
    std::ofstream   out;

    if (!checkArg())
    {
        std::cout << RED << "empty arguments are prohibited\n" << RESET;
        return (false);
    }
    if (!openFile(in, out))
        return (false);
    
    while (std::getline(in, line))
    {
        start = 0;
        result = "";
        while ((pos = line.find(s1, start)) != std::string::npos)
        {
            result += line.substr(start, pos - start);
            result += s2;
            start = pos + s1.length();
        }
        result += line.substr(start);
        out << result << "\n";
    }
    return (true);
}
