#include <iostream>
#include <string>
#include <vector>
#include <utility>

int main(int argc, char* argv[])
{
    std::vector<std::pair<int, int>> slopes;
    slopes.push_back(std::make_pair(1, 1));
    slopes.push_back(std::make_pair(3, 1));
    slopes.push_back(std::make_pair(5, 1));
    slopes.push_back(std::make_pair(7, 1));
    slopes.push_back(std::make_pair(1, 2));
    std::vector<std::string> map;
    std::string line;
    while (std::cin >> line) map.push_back(line);
    unsigned long long product = 1;
    for (int i = 0; i < slopes.size(); i++)
    {
        int posx = 0, posy = 0, trees = 0;
        while (posy < map.size())
        {
            if (map[posy][posx] == '#')
            {
                trees++;
            }
            posx = (posx + slopes[i].first) % map[0].length();
            posy += slopes[i].second;
        }
        product *= trees;
        std::cout << slopes[i].first << "," << slopes[i].second << "=" << trees << std::endl;
    }
    std::cout << product;
    return 0;
}