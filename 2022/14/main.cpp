#include <fstream>
#include <sstream>
#include <ranges>
#include <string>
//#include <string_view>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

struct Map {
    std::vector<std::vector<char>> map = std::vector<std::vector<char>>(1'000, std::vector<char>(1'000, ' '));
    int min_row = 1'000;
    int max_row = -1;
    int min_col = 1'000;
    int max_col = -1;

    void update_bounding_box(int row, int col) {
        if (min_row > row) min_row = row;
        if (max_row < row) max_row = row;
        if (min_col > col) min_col = col;
        if (max_col < col) max_col = col;
    }

    void add_scan(const std::string& line) {
        std::stringstream s(line);
        int prev_col = -1, prev_row = -1;
        int col = 0, row = 0;
        char delim;
        while (s >> col >> delim >> row) {
            if (prev_col == col)
            for (int idx : std::views::iota(std::min(prev_row, row), std::max(prev_row, row)+1)) {
                map[idx][col] = '#';
                update_bounding_box(idx,col);
            }
            if (prev_row == row)
            for (int idx : std::views::iota(std::min(prev_col, col), std::max(prev_col, col)+1)) {
                map[row][idx] = '#';
                update_bounding_box(row,idx);
            }
            prev_row = row;
            prev_col = col;
            s >> delim >> delim; // process '->'
        }
    }

    bool drop_sand_into_void() {
        int row = 0;
        int col = 500;

        auto step = [&row, &col, this]() {
            // detect when the grain will fall into the void
            if (row+1 > max_row) return false;
            if (col < min_col) return false;
            if (col > max_col) return false;

            // can go down
            if (map[row+1][col] == ' ') { row++; }
            // can go down-left
            else if (map[row+1][col-1] == ' ') { row++; col--; }
            // can go down-right
            else if (map[row+1][col+1] == ' ') { row++; col++; }
            // stuck
            else {
                map[row][col] = 'O';
                return false;
            }

            return true;
        };

        // move until stuck or destined for void
        while (step());
        // return true if stuck
        return map[row][col] == 'O';
    }

    bool drop_sand_onto_floor() {
        if (map[0][500] == 'O') return false;

        int row = 0;
        int col = 500;

        auto step = [&row, &col, this]() {
            if (row < 0 || row >= std::ssize(map) || col < 0 || col >= std::ssize(map[0]))
                throw std::runtime_error("Out of bounds, needs bigger map.");

            if (row+1 == max_row+2) {
                map[row][col] = 'O';
                return false;
            } else if (map[row+1][col] == ' ') { row++; }
            else if (map[row+1][col-1] == ' ') { row++; col--; }
            else if (map[row+1][col+1] == ' ') { row++; col++; }
            else {
                map[row][col] = 'O';
                return false;
            }

            return true;
        };

        while (step());
        return map[row][col] == 'O';
    }
};

int parse_and_run(std::string_view path) {
    using namespace day14::sand;

    std::fstream file(path);
    if (!file.is_open()) {
        std::cerr << "Failed to open " << std::quoted(path) << "\n";
        return 1;
    }

    Map map;
    std::string line;
    while (getline(file, line))
        map.add_scan(line);

    Map floor_map = map;

    size_t cnt = 0;
    while (map.drop_sand_into_void()) cnt++;

    size_t floor_cnt = 0;
    while (floor_map.drop_sand_onto_floor()) floor_cnt++;


    std::cout << "Only the first " << cnt << " grains of sand will be captured by reservoir.\n";
    std::cout << "The sand will stop falling after " << floor_cnt << " grains.\n";


    return 0;
}

int main(int argc, char* argv[]) {
    if (argc == 1) {
        return 1;
    } else if (argc == 2) {
        return parse_and_run("./input.txt");
    }
}
