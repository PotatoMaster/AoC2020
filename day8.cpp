#include <iostream>
#include <string>
#include <vector>
#include <sstream>

struct instruction
{
    std::string op;
    int offset;
};

int main()
{
    std::vector<std::pair<instruction, int>> boot_code;
    std::string line;
    while (std::getline(std::cin, line))
    {
        std::stringstream ss(line);
        instruction ins;
        ss >> ins.op;
        std::string number;
        ss >> number;
        ins.offset = std::stoi(number);
        boot_code.push_back(std::make_pair(ins, 0));
    }
    int ptr = 0, acc = 0;
    while (true)
    {
        if (boot_code[ptr].second == 1) break;
        boot_code[ptr].second++;
        if (boot_code[ptr].first.op == "acc")
        {
            acc += boot_code[ptr].first.offset;
            ptr++;
        }
        else if (boot_code[ptr].first.op == "jmp")
        {
            ptr += boot_code[ptr].first.offset;
        }
        else if (boot_code[ptr].first.op == "nop")
        {
            ptr++;
        }
    }
    std::cout << acc << std::endl;
    for (int i = 0; i < boot_code.size(); i++)
    {
        for (int j = 0; j < boot_code.size(); j++) boot_code[j].second = 0;
        ptr = acc = 0;
        if (boot_code[i].first.op == "acc") continue;
        while (ptr < boot_code.size())
        {
            if (boot_code[ptr].second == 1) break;
            boot_code[ptr].second++;
            if (boot_code[ptr].first.op == "acc")
            {
                acc += boot_code[ptr].first.offset;
                ptr++;
            }
            else if (boot_code[ptr].first.op == "jmp")
            {
                if (i == ptr) ptr++;
                else ptr += boot_code[ptr].first.offset;
            }
            else if (boot_code[ptr].first.op == "nop")
            {
                if (i == ptr) ptr += boot_code[ptr].first.offset;
                else ptr++;
            }
        }
        if (ptr == boot_code.size())
        {
            std::cout << acc;
            break;
        }
    }
    return 0;
}