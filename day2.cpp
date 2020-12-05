#include <iostream>
#include <string>

bool is_valid(const std::string& str, char ch, int n, int m, bool new_spec)
{
    if (new_spec) return (str[n - 1] == ch && str[m - 1] != ch) && (str[n - 1] == ch || str[m - 1] == ch);
    else
    {
        int count = 0;
        for (unsigned int i = 0; i < str.length(); i++) if (str[i] == ch) count++;
        return count >= n && count <= m;
    }
}

int main()
{
    int n, m, valid_old = 0, valid_new = 0;
    char c;
    std::string s;
    while (std::cin >> n)
    {
        std::cin.ignore();
        std::cin >> m;
        std::cin >> c;
        std::cin.ignore();
        std::cin >> s;
        if (is_valid(s, c, n, m, false)) valid_old++;
        if (is_valid(s, c, n, m, true)) valid_new++;
    }
    std::cout << valid_old << std::endl << valid_new;
}