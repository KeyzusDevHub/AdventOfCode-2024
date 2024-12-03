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
        if (is_safe(num_line)){
            safe++;
        }

    }
    std::cout << safe << std::endl;
}
