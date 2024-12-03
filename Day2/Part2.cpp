#include <iostream>
#include <bits/stdc++.h>
#include <string>
#include <vector>

bool is_safe(std::vector<int> option){
    int slope = option[1] - option[0];
    if (abs(slope) > 3 || slope == 0){
        return false;
    }
    for (int i = 0; i < option.size() - 1; i++){
        int dist = option[i + 1] - option[i];
        if (abs(dist) > 3 || dist * slope <= 0){
            return false;
        }
    }
    return true;
}

bool check_safe(std::vector<int> line){
    std::vector<std::vector<int>> options = std::vector<std::vector<int>>();
    options.push_back(line);
    for (int i = 0; i < line.size(); i++){
        std::vector<int> option = std::vector<int>(line);
        option.erase(option.begin() + i);
        options.push_back(option);
    }

    for (std::vector<int> o : options){
        if (is_safe(o)){
            return true;
        }
    }
    return false;
}


int main() {
    std::string line;
    int safe = 0;
    while (std::getline(std::cin, line)){
        std::vector<int> num_line = std::vector<int>();
        std::istringstream iss(line);
        int num;
        while (iss >> num){
            num_line.push_back(num);
        }
        if (check_safe(num_line)){
            safe++;
        }

    }
    std::cout << safe << std::endl;
}
