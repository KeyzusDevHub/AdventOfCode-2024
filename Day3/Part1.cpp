#include <iostream>
#include <regex>
#include <string>

int main() {
    int sum = 0;
    std::string line;
    while (std::getline(std::cin, line)){
        const std::regex r("mul\\((\\d{1,3}),(\\d{1,3})\\)");  

        auto words_begin = std::sregex_iterator(line.begin(), line.end(), r);
        auto words_end = std::sregex_iterator();
        
        for (std::sregex_iterator i = words_begin; i != words_end; ++i) {
            sum += std::stoi(i->str(1)) * std::stoi(i->str(2));
        }
    }
    std::cout << sum << std::endl;
}