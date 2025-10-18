#include "ScalarConverter.hpp"

bool is_char(std::string &input)
{
    if (input == "." || input == "'.'"
        || input == "+" || input == "-")
        return 0;
    if (input.length() == 1 && !std::isdigit(input[0])
        && std::isprint(input[0]))
        return 1;
    else if (input.length() == 3 && input[0] == '\''
        && input[input.length() - 1] == '\'' && std::isprint(input[1]))
        return 1;
    return 0;
}

bool is_int(std::string &input)
{
    if (input == "." || input == "'.'")
        return 0;
    int i = 0;
    if (input[i] == '-' || input[i] == '+')
        i++;
    if (i == input.length())
        return 0;
    while (std::isdigit(input[i]))
        i++;
    if (i == input.length())
        return 1;
    return 0;
}

bool is_double(std::string &input)
{
    if (input == "nan" || input == "inf"
        || input == "+inf" || input == "-inf")
        return 1;
    size_t pos = input.find(".");
    if (pos == std::string::npos || pos == 0
        || !std::isdigit(input[pos + 1])
        || !std::isdigit(input[pos - 1])
        || pos == input.length() - 1)
        return 0;
    size_t pos2 = input.substr(pos + 1).find(".");
    if (pos2 != std::string::npos)
        return 0;
    size_t i = 0;
    if (input[i] == '-' || input[i] == '+')
        i++;
    while (i < input.length())
    {
        if (i == pos)
        {
            i++;
            continue;
        }
        if (!std::isdigit(input[i]))
            break;
        i++;
    }
    if (i == input.length())
        return (1);
    return 0;
}

bool is_float(std::string &input)
{
    
    if (input[input.length() - 1] != 'f')
        return 0;
    if (input == "nanf" || input == "inff"
        || input == "+inff" || input == "-inff")
        return 1;
    size_t pos = input.find(".");
    if (pos == std::string::npos || pos == 0
        || !std::isdigit(input[pos + 1]) || !std::isdigit(input[pos - 1]))
        return 0;
    size_t pos2 = input.substr(pos + 1).find(".");
    if (pos2 != std::string::npos)
        return 0;
    size_t i = 0;
    if (input[i] == '-' || input[i] == '+')
        i++;
    while (i < input.length() - 1)
    {
        if (i == pos)
        {
            i++;
            continue;
        }
        if (!std::isdigit(input[i]))
            break;
        i++;
    }
    if (i == input.length() - 1)
        return (1);
    return 0;
}

inputType ScalarConverter::detectType(std::string &input)
{
    if (input == "")
        return U;
    else if (is_char(input))
        return C;
    else if (is_int(input))
        return I;
    else if (is_double(input))
        return D;
    else if (is_float(input))
        return F;
    return U;
}

void    foundChar(std::string &input)
{
    char c;
    if (input.length() == 3)
        c = input[1];
    else
        c = input[0];
    int intValue = static_cast<int>(c);
    float floatValue = static_cast<float>(c);
    double doubleValue = static_cast<double>(c);

    std::cout << "char: '" << c << "'" << std::endl;
    std::cout << "int: " << intValue << std::endl;
    std::cout << "double: ";
    std::cout <<  std::fixed << std::setprecision(1) << doubleValue << std::endl;
    std::cout << "float: " << std::fixed << std::setprecision(1) << floatValue << "f" << std::endl;
}

void    ScalarConverter::convert(std::string input)
{
    inputType T = detectType(input);
    switch (T)
    {
    case C: foundChar(input);
        break;
    // case I: foundInt(input);
    //     break;
    // case D: foundDouble(input);
    //     break;
    // case F: foundFloat(input);
    //     break;
    // case U: foundUndefined();
    //     break;
    default:
        break;
    }
}