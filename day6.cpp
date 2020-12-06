#include <iostream>
#include <string>
#include <sstream>
#include <map>

int main()
{
    std::string line, answers;
    std::map<char, int> answer_counts;
    int count_anyone = 0, count_everyone = 0;
    while (std::getline(std::cin, line))
    {
        int members = 0;
        answer_counts.clear();
        while (line != "")
        {
            members++;
            std::stringstream ss(line);
            while (ss >> answers)
            {
                for (int i = 0; i < answers.length(); i++)
                {
                    answer_counts.emplace(answers[i], 0),
                    answer_counts[answers[i]]++;
                }
            }
            if (!std::getline(std::cin, line)) break;
        }
        count_anyone += answer_counts.size();
        for (std::map<char, int>::iterator it = answer_counts.begin(); it != answer_counts.end(); it++) if (it->second == members) count_everyone++;
    }
    std::cout << count_anyone << std::endl << count_everyone;
    return 0;
}