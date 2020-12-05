#include <iostream>
#include <string>
#include <sstream>
#include <regex>

int main()
{
    std::string line, field;
    std::smatch m;
    int fields_present = 0, fields_valid = 0, passports_full = 0, passports_valid = 0;
    while (std::getline(std::cin, line))
    {
        fields_present = 0;
        fields_valid = 0;
        while (line != "")
        {
            std::stringstream ss(line);
            while (ss >> field)
            {
                std::string key = field.substr(0, 3);
                std::string value = field.substr(4);
                if (key == "byr")
                {
                    fields_present++;
                    std::regex re("(19[2-9][0-9]|200[0-2])");
                    if (std::regex_match(value, m, re)) fields_valid++;
                }
                else if (key == "iyr")
                {
                    fields_present++;
                    std::regex re("20(1[0-9]|20)");
                    if (std::regex_match(value, m, re)) fields_valid++;
                }
                else if (key == "eyr")
                {
                    fields_present++;
                    std::regex re("20(2[0-9]|30)");
                    if (std::regex_match(value, m, re)) fields_valid++;
                }
                else if (key == "hgt")
                {
                    fields_present++;
                    std::regex re("(1([5-8][0-9]|9[0-3])cm|(59|6[0-9]|7[0-6])in)");
                    if (std::regex_match(value, m, re)) fields_valid++;
                }
                else if (key == "hcl")
                {
                    fields_present++;
                    std::regex re("#[0-9a-f]{6}");
                    if (std::regex_match(value, m, re)) fields_valid++;
                }
                else if (key == "ecl")
                {
                    fields_present++;
                    std::regex re("amb|b(lu|rn)|gr(y|n)|hzl|oth");
                    if (std::regex_match(value, m, re)) fields_valid++;
                }
                else if (key == "pid")
                {
                    fields_present++;
                    std::regex re("[0-9]{9}");
                    if (std::regex_match(value, m, re)) fields_valid++;
                }
            }
            if (!std::getline(std::cin, line)) { break; }
        }
        if (fields_present == 7) passports_full++;
        if (fields_valid == 7) passports_valid++;
    }
    std::cout << passports_full << std::endl << passports_valid;
    return 0;
}