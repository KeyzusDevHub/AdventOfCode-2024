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

std::vector<int> correct_data(std::vector<int> data_line, std::vector<std::pair<int,int>> rules){
    std::sort(data_line.begin(), data_line.end(), [rules](int a, int b){
        for (std::pair<int, int> p : rules){
            if (p.first == a && p.second == b){
                return true;
            }
            else if (p.first == b && p.second == a){
                return false;
            }
        }
        return true;
    });
    return data_line;
}

int score_data(std::vector<int> data_line, std::vector<std::pair<int,int>> rules){
    std::vector<int> past_nums = std::vector<int>();
    past_nums.push_back(data_line[0]);
    for (int i = 1; i < data_line.size(); i++){
        if (violate_rules(data_line[i], past_nums, rules)){
            std::vector<int> corrected_data_line = correct_data(data_line, rules);
            return corrected_data_line[corrected_data_line.size() / 2];
        }
        past_nums.push_back(data_line[i]);
    }
    return 0;
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