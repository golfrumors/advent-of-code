#include <algorithm>
#include <fstream>
#include <iostream>
#include <regex>
#include <vector>

std::vector<int> ints(const std::string& string)
{
    std::vector<int> result;
    std::regex pattern(R"(-?[0-9]+)");
    std::sregex_iterator it(string.begin(), string.end(), pattern);
    std::sregex_iterator end;

    for (; it != end; ++it)
    {
        result.push_back(std::stoi((*it).str()));
    }

    return result;
}

int main()
{
    std::vector<std::vector<char>> stacks(10);

    std::ifstream file("input.txt");
    std::string line;
    while (std::getline(file, line))
    {
        if (line.empty())
        {
            break;
        }
        if (line.find(" 1") == 0)
        {
            continue;
        }
        for (size_t i = 0; i < line.size(); i += 4)
        {
            char c = line[i + 1];
            if (!std::isspace(c))
            {
                stacks[i / 4 + 1].insert(stacks[i / 4 + 1].begin(), c);
            }
        }
    }

    std::vector<std::vector<char>> stacks2 = stacks;

    while (std::getline(file, line))
    {
        std::vector<int> values = ints(line);
        int count = values[0];
        int fro = values[1];
        int to = values[2];

        for (int i = 0; i < count; ++i)
        {
            stacks[to].push_back(stacks[fro].back());
            stacks[fro].pop_back();
        }

        std::vector<char> items = stacks2[fro];
        items.resize(items.size() - count);
        stacks2[to].insert(stacks2[to].end(), items.begin(), items.end());
    }

    std::string part1;
    for (const std::vector<char>& s : stacks)
    {
        if (s.empty())
        {
            continue;
        }
        part1.push_back(s.back());
    }

    std::string part2;
    for (const std::vector<char>& s : stacks2)
    {
        if (s.empty())
        {
            continue;
        }
        part2.push_back(s.back());
    }

    std::cout << "Part 1: " << part1 << std::endl;
    std::cout << "Part 2: " << part2 << std::endl;

    return 0;
}
