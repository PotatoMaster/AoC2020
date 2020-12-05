#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main()
{
    std::string s;
    int highestId = 0;
    std::vector<int> v;
    while (std::cin >> s)
    {
        int rowMin = 0, rowMax = 127, i = 0;
        for (i = 0; i < 7; i++)
        {
            if (s[i] == 'F')
            {
                rowMax -= (rowMax - rowMin + 1) / 2;
            }
            else if (s[i] == 'B')
            {
                rowMin += (rowMax - rowMin + 1) / 2;
            }
        }
        int colMin = 0, colMax = 7;
        for (; i < 10; i++)
        {
            if (s[i] == 'L')
            {
                colMax -= (colMax - colMin + 1) / 2;
            }
            else if (s[i] == 'R')
            {
                colMin += (colMax - colMin + 1) / 2;
            }
        }
        int id = rowMin * 8 + colMin;
        if (id >= highestId) highestId = id;
        v.push_back(id);
    }
    std::cout << highestId << std::endl;
    for (int i = 0; i < 128; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            int key = i * 8 + j;
            if (std::find(v.begin(), v.end(), key - 1) != v.end() && std::find(v.begin(), v.end(), key) == v.end() && std::find(v.begin(), v.end(), key + 1) != v.end()) std::cout << key;
        }
    }
    return 0;
}