#include <iostream>
#include <vector>

int main()
{
    std::vector<int> nums;
    int tmp, a = 0, b = 0, c = 0, d = 0, e = 0;
    while (std::cin >> tmp) nums.push_back(tmp);
    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = i + 1; j < nums.size(); j++)
        {
            if (nums[i] + nums[j] == 2020)
            {
                a = nums[i];
                b = nums[j];
            }
            for (int k = j + 1; k < nums.size(); k++)
            {
                if (nums[i] + nums[j] + nums[k] == 2020)
                {
                    c = nums[i];
                    d = nums[j];
                    e = nums[k];
                }
            }
        }
    }
    std::cout << a * b << std::endl << c * d * e;
    return 0;
}