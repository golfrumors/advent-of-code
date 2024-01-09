#include <iostream>
#include <fstream>
#include <vector>
#include <cctype>
#include <unordered_map>
#include <algorithm>


std::vector<int> extractDigits(const std::string& line) {
    std::vector<int> digits;
    for (char ch : line) {
        if (isdigit(ch)) {
            digits.push_back(ch - '0');
        }
    }
    return digits;
}

std::string processLine(const std::string& line) {
    std::vector<int> digits = extractDigits(line);
    if (digits.size() == 1) {
        return std::to_string(digits[0]) + std::to_string(digits[0]);
    } else if (digits.size() >= 2) {
        return std::to_string(digits[0]) + std::to_string(digits.back());
    } else {
        return "0";
    }
}

int calculateSum(const std::string& filePath) {
    int totalSum = 0;
    std::ifstream file(filePath);
    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            std::string result = processLine(line);
            std::cout << "Line: " << line << ", Processed: " << result << std::endl;
            totalSum += std::stoi(result);
        }
        file.close();
        std::cout << "Concatenated Sum of first and last digits: " << totalSum << std::endl;
    } else {
        std::cerr << "Unable to open file: " << filePath << std::endl;
    }
    return totalSum;
}

int main() {
    calculateSum("input.txt");
    return 0;
}
