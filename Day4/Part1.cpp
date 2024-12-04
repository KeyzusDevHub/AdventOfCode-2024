#include <iostream>
#include <vector>
#include <string>
#include <bits/stdc++.h>

int horizontal_search(std::vector<std::vector<char>> data){
    int result = 0;
    for (std::vector<char> line : data){
        for (int i = 0; i < line.size() - 3; i++){
            std::string s = "";
            s += line[i];
            s += line[i + 1];
            s += line[i + 2];
            s += line[i + 3];
            if (s == "XMAS" || s == "SAMX"){
                result++;
            }
        }
    }
    return result;
}

int vertical_search(std::vector<std::vector<char>> data) {
    int result = 0;
    for (int i = 0; i < data.size() - 3; i++){
        for (int j = 0; j < data[i].size(); j++){
            std::string s = "";
            s += data[i][j];
            s += data[i + 1][j];
            s += data[i + 2][j];
            s += data[i + 3][j];
            if (s == "XMAS" || s == "SAMX"){
                result++;
            }
        }
    }
    return result;
}

int diagonal_search_right(std::vector<std::vector<char>> data){
    int result = 0;
    for (int i = 0; i < data.size() - 3; i++){
        for (int j = 0; j < data[i].size() - 3; j++){
            std::string s = "";
            s += data[i][j];
            s += data[i + 1][j + 1];
            s += data[i + 2][j + 2];
            s += data[i + 3][j + 3];
            if (s == "XMAS" || s == "SAMX"){
                result++;
            }
        }
    }
    return result;
}

int diagonal_search_left(std::vector<std::vector<char>> data){
    int result = 0;
    for (int i = 3; i < data.size(); i++){
        for (int j = 3; j < data[i].size(); j++){
            std::string s = "";
            s += data[i][j - 3];
            s += data[i - 1][j - 2];
            s += data[i - 2][j - 1];
            s += data[i - 3][j];
            if (s == "XMAS" || s == "SAMX"){
                result++;
            }
        }
    }
    return result;
}


int main() {

    std::string line;
    std::vector<std::vector<char>> data = std::vector<std::vector<char>>();
    while (std::getline(std::cin, line)) {
        std::istringstream iss(line);
        std::vector<char> l = std::vector<char>();
        char c;
        while (iss >> c) {
            l.push_back(c);
        }
        data.push_back(l);
    }

    int result = horizontal_search(data) + vertical_search(data) + diagonal_search_right(data) + diagonal_search_left(data);
    std::cout << result << std::endl;
}