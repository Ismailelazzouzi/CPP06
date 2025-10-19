#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>

enum inputType
{
    C,
    I,
    D,
    F,
    U
};

class ScalarConverter
{
private:
    ScalarConverter(){};
public:
    static void    convert(std::string input);
    static inputType detectType(std::string &input);
    ~ScalarConverter(){};
};
