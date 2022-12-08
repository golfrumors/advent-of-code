#include <vector>
#include <fstream>
#include <iostream>

using namespace std;

const int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

bool isVisible(int i, int j, vector<vector<int>>& grid){
    int m = grid.size();
    int n = grid[0].size();

        for (int k = 0; k < 4; ++k)
        {
            int ni = i + directions[k][0];
            int nj = j + directions[k][1];

            while (ni >= 0 && ni < m && nj >= 0 && nj < n && grid[ni][nj] < grid[i][j])
            {
                ni += directions[k][0];
                nj += directions[k][1];
            }

            if (!(ni >= 0 && ni < m && nj >= 0 && nj < n))
            {
                return true;
            }
        }

        return false;
}

int score(int i, int j, vector<vector<int>>& grid){
    int m = grid.size();
    int n = grid[0].size();

        int s = 1;
        for (int k = 0; k < 4; ++k)
        {
            int curr = 0;
            int ni = i + directions[k][0];
            int nj = j + directions[k][1];

            while (ni >= 0 && ni < m && nj >= 0 && nj < n)
            {
                ++curr;
                if (grid[ni][nj] >= grid[i][j])
                {
                    break;
                }

                ni += directions[k][0];
                nj += directions[k][1];
            }

            s *= curr;
        }

        return s;
    }

int solvePart1(vector<vector<int>>& grid)
{
    int res = 0;
    int m = grid.size();
    int n = grid[0].size();

    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (isVisible(i, j, grid))
            {
                ++res;
            }
        }
    }

    return res;
}

int solvePart2(vector<vector<int>>& grid)
{
    int res = 0;
    int m = grid.size();
    int n = grid[0].size();

    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            res = max(res, score(i, j, grid));
        }
    }

    return res;
}

int main()
{
    vector<vector<int>> grid;

    ifstream file("grid.txt");
    string line;
    while (getline(file, line))
    {
        vector<int> row;
        for (const char c : line)
        {
            row.push_back(c - '0');
        }
        grid.push_back(row);
    }

    cout << "Solution for part one: " << solvePart1(grid) << endl;
    cout << "Solution for part two: " << solvePart2(grid) << endl;

    return 0;
}