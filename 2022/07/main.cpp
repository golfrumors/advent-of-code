#include <algorithm>
#include <fstream>
#include <iostream>
#include <map>
#include <regex>
#include <string>
#include <vector>

int dirsize(std::string dirname, std::map<std::string, int>& dirs, std::map<std::string, std::vector<std::string>>& subdirs)
{
    int dsize = dirs[dirname];
    for (const std::string& i : subdirs[dirname])
    {
        if (dirs.count(i) > 0)
        {
            dsize += dirsize(i, dirs, subdirs);
        }
    }
    return dsize;
}

int main()
{
    std::map<std::string, int> dirs;
    std::map<std::string, std::vector<std::string>> subdirs;

    std::ifstream file("input.txt");
    std::string line;
    std::string curdir;

    while (std::getline(file, line))
    {
        std::string sz, fname;
        std::smatch m;
        if (line.length() == 0 || std::regex_match(line, m, std::regex(R"(\$ cd (.*))")))
        {
            continue;
        }
        if (line[0] == '$')
        {
            std::string regex("(\\S+)");
            std::regex r(regex);
            std::sregex_token_iterator tokenitr = std::sregex_token_iterator(line.begin(), line.end(), r, {1});
            std::vector<std::string> args;
            std::copy(tokenitr.begin(), tokenitr.end(), std::back_inserter(args));
            std::string cmd = args[1];
            if (cmd == "cd")
            {
                std::string path = args[2];
                if (path[0] == '/')
                {
                    curdir = path;
                }
                else
                {
                    std::string joined = curdir + "/" + path;
                    curdir = std::regex_replace(joined, std::regex(R"(/{2,})"), "/");
                }

                if (dirs.count(curdir) == 0)
                {
                    dirs[curdir] = 0;
                    subdirs[curdir] = {};
                }
            }
        }
        else
        {
            std::vector<std::string> tokens = std::sregex_token_iterator(line.begin(), line.end(), std::regex(R"(\S+)"), {0, -1}).toVector();
            sz = tokens[0];
            fname = tokens[1];
            if (sz != "dir")
            {
                dirs[curdir] += std::stoi(sz);
            }
            else
            {
                std::string joined = curdir + "/" + fname;
                std::string normpath = std::regex_replace(joined, std::regex(R"(/{2,})"), "/");
                subdirs[curdir].push_back(normpath);
            }
        }
    }

    int totsize = 0;
    for (const auto& [d, size] : dirs)
    {
        int dsize = dirsize(d, dirs, subdirs);
        if (dsize <= 100000)
        {
            totsize += dsize;
        }
    }
    std::cout << "Part one: " << totsize << std::endl;

    int unused = 70000000 - dirsize("/", dirs, subdirs);
    int ms = 0;
    for (const auto& [d, size] : dirs)
    {
        int ds = dirsize(d, dirs, subdirs);
        if (unused + ds >= 30000000)
        {
            ms = std::max(ms, ds);
        }
    }
    std::cout << "Part two: " << ms << std::endl;

    return 0;
}


