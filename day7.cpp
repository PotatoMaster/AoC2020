#include <iostream>
#include <string>
#include <sstream>
#include <map>

bool contains_bag(std::map<std::string, std::map<std::string, int>> rules, std::string current, std::string bag)
{
    bool contains = false;
    for (std::pair<std::string, int> p : rules[current])
    {
        if (p.first == bag) return true;
        contains = contains || contains_bag(rules, p.first, bag);
    }
    return contains;
}

int count_bags(std::map<std::string, std::map<std::string, int>> rules, std::string current)
{
    int count = 0;
    for (std::pair<std::string, int> p : rules[current])
    {
        count += p.second + p.second * count_bags(rules, p.first);
    }
    return count;
}

int main()
{
    std::map<std::string, std::map<std::string, int>> rules;
    std::string line;
    while (std::getline(std::cin, line))
    {
        std::string parent = line.substr(0, line.find("bag") - 1);
        std::string children = line.substr(0 + parent.length() + 14);
        for (int i = 0; i < children.length(); i++)
        {
            if (isdigit(children[i])) rules[parent][children.substr(i + 2, children.find("bag", i) - i - 3)] = (int)children[i] - '0';
        }
    }
    int part1 = 0;
    for (std::pair<std::string, std::map<std::string, int>> p : rules) if (contains_bag(rules, p.first, "shiny gold")) part1++;
    int part2 = count_bags(rules, "shiny gold");
    std::cout << std::endl << part2;
    return 0;
}