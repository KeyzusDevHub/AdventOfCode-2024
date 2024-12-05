#include <iostream>
#include <string>
#include <vector>
#include <bits/stdc++.h>
#include <algorithm>

std::string replaceAll(std::string str, const std::string oldSubstr, const std::string newSubstr) {
    size_t pos = 0;
    while ((pos = str.find(oldSubstr, pos)) != std::string::npos) {
        str.replace(pos, oldSubstr.length(), newSubstr);
        pos += newSubstr.length();
    }
    return str;
}

bool violate_rules(int check, std::vector<int> check_list, std::vector<std::pair<int,int>> rules){
    for (std::pair<int, int> p : rules){
        if (p.first == check && std::find(check_list.begin(), check_list.end(), p.second) != check_list.end()){
            return true;
        }
    }
    return false;
}

int score_data(std::vector<int> data_line, std::vector<std::pair<int,int>> rules){
    std::vector<int> past_nums = std::vector<int>();
    past_nums.push_back(data_line[0]);
    for (int i = 1; i < data_line.size(); i++){
        if (violate_rules(data_line[i], past_nums, rules)){
            return 0;
        }
        past_nums.push_back(data_line[i]);
    }
    return data_line[(int)(data_line.size() / 2)];
}

int main() {
    std::string line;

    bool isFirstPart = true;

    int sum = 0;

    std::vector<std::pair<int,int>> rules = std::vector<std::pair<int,int>>();

    while (std::getline(std::cin, line)){
        
        if (line == ""){
            isFirstPart = false;
            continue;
        }
        if (isFirstPart){
            line = replaceAll(line, "|", " ");
            std::istringstream iss(line);
            int num1, num2;
            iss >> num1 >> num2;
            std::pair<int,int> rule = std::make_pair(num1, num2);
            rules.push_back(rule);
        }
        else{
            line = replaceAll(line, ",", " ");
            std::istringstream iss(line);
            int num;
            std::vector<int> data_line = std::vector<int>();
            while (iss >> num){
                data_line.push_back(num);
            }
            sum += score_data(data_line, rules);
        }
        
    }
    std::cout << sum << std::endl;
}