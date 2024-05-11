#include <fstream>
#include <sstream>
#include <ranges>
#include <string>
//#include <string_view>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

struct Map
{
    vector< vector<char> > map = vector< vector<char> >(1'000, vector<char>(1'000, '.'));

    int min_x = 1'000;
    int max_x = -1;
    int min_y = 1'000;
    int max_y = -1;

    void updateBox(int x, int y)
    {
        if(min_x > x) min_x = x;
        if(max_x < x) max_x = x;
        if(min_y > y) min_y = y;
        if(max_y < y) max_y = y;
    }

    void addScan(const string& line)
    {
        stringstream ss(line);
        int prev_y = -1, prev_x = -1;
        int y = 0, x = 0;

        char delim;

        while(ss >> y >> delim >> x)
        {
            if(prev_y == y)
                for (int i : std::views::iota(min(prev_x, x), max(prev_x, x)+1))
                {
                    map[i][y] = '#';
                    updateBox(i, y);
                }

            if(prev_x == x)
                for(int i : std::views::iota(min(prev_y, y), max(prev_y, y)+1))
                {
                    map[x][i] = '#';
                    updateBox(x, i);
                }

            prev_x = x;
            prev_y = y;

            ss >> delim >> delim;
        }
    }

    bool dropSandVoid()
    {
        int y = 0;
        int x = 500;

        auto step = [&y, &x, this]()
        {
            if (y+1 > max_y) return false;
            if (x < min_x) return false;
            if (x > max_x) return false;

            if(map[y+1][x] == '.') {y++;}
            else if (map[y+1][x-1] == '.') {y++; x--;}
            else if (map[y+1][x+1] == '.') {y++; x++;}
            else {map[y][x] = '0'; return false;}

        };

        while(step());

        return map[y][x] == '0';

    }

};

int main()
{
    fstream file("./input.txt");

    Map map;
    string l;
    while(getline(file, l))
        map.addScan(l);

    Map floor_map = map;

    size_t cnt = 0;
    while(map.dropSandVoid()) cnt++;

    cout << cnt;
}
