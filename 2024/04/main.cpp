#include <bits/stdc++.h>

using namespace std;

bool isInvalidRow(int indexR, int numR) {
    return indexR >= numR || indexR < 0;
}

bool isInvalidCol(int indexC, int numC) {
    return indexC >= numC || indexC < 0;
}

int findMasDir(int r, int c, int dirR, int dirC, const vector<string>& mat, const vector<char>& word, int numR, int numC) {
    for (int i = 0; i < word.size(); i++) {
        int indexR = r + (i * dirR) + dirR;
        if (isInvalidRow(indexR, numR)) {
            return 0;
        }

        int indexC = c + (i * dirC) + dirC;
        if (isInvalidCol(indexC, numC)) {
            return 0;
        }

        if (mat[indexR][indexC] != word[i]) {
            return 0;
        }
    }

    return 1;
}

int find(int r, int c, const vector<string>& mat, const vector<char>& word, int numR, int numC) {
    int dirs[] = {-1, 0, 1};

    int result = 0;
    for (int dirR : dirs) {
        for (int dirC : dirs) {
            result += findMasDir(r, c, dirR, dirC, mat, word, numR, numC);
        }
    }

    return result;
}

bool findXChar(int r, int c, int dirR, int dirC, char toFind, const vector<string>& mat, int numR, int numC) {
    int indexR = r + dirR;
    if (isInvalidRow(indexR, numR)) {
        return false;
    }

    int indexC = c + dirC;
    if (isInvalidCol(indexC, numC)) {
        return false;
    }

    return mat[indexR][indexC] == toFind;
}

bool findXHalf(int r, int c, int dirR, int dirC, const vector<string>& mat, int numR, int numC) {
    return
        findXChar(r, c, dirR, dirC, 'M', mat, numR, numC) &&
        findXChar(r, c, dirR * -1, dirC * -1, 'S', mat, numR, numC);
}

int findX(int r, int c, const vector<string>& mat, int numR, int numC) {
    int dirs[] = {1, -1};

    int result = 0;
    for (int dirR : dirs) {
        for (int dirC : dirs) {
            result += findXHalf(r, c, dirR, dirC, mat, numR, numC) ? 1 : 0;
        }
    }

    return result == 2 ? 1 : 0;
}

int main() {
    ifstream in("input");
    vector<string> mat;
    string line;

    while (getline(in, line)) {
        mat.push_back(line);
    }

    int numR = mat.size();
    int numC = mat[0].size();

    vector<char> word = {'M', 'A', 'S'};

    int answer1 = 0;
    int answer2 = 0;

    for (int r = 0; r < numR; r++) {
        for (int c = 0; c < numC; c++) {
            if (mat[r][c] == 'X') {
                answer1 += find(r, c, mat, word, numR, numC);
            } else if (mat[r][c] == 'A') {
                answer2 += findX(r, c, mat, numR, numC);
            }
        }
    }

    cout << "Part 1 : " << answer1 << endl;
    cout << "Part 2 : " << answer2 << endl;

    return 0;
}
