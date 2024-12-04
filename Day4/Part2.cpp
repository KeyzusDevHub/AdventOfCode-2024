#include <iostream>
#include <vector>
#include <string>
#include <bits/stdc++.h>

int x_mas_search(std::vector<std::vector<char>> data){
    int result = 0;
    for (int i = 1; i < data.size() - 1; i++){
        for (int j = 1; j < data[i].size() - 1; j++){
            std::string s1 = "";
            s1 += data[i - 1][j - 1];
            s1 += data[i][j];
            s1 += data[i + 1][j + 1];
            
            if (s1 != "MAS" && s1 != "SAM"){
                continue;
            }

            std::string s2 = "";
            s2 += data[i + 1][j - 1];
            s2 += data[i][j];
            s2 += data[i - 1][j + 1];
            if (s2 == "MAS" || s2 == "SAM"){
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

    std::cout << x_mas_search(data) << std::endl;
}