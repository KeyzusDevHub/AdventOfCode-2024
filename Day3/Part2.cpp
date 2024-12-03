#include <iostream>
#include <regex>
#include <string>

int main() {
    int sum = 0;
    std::string line;
    bool should_do = true;

    while (std::getline(std::cin, line)){
        const std::regex r("mul\\((\\d{1,3}),(\\d{1,3})\\)|do\\(\\)|don\\'t\\(\\)");

        auto words_begin = std::sregex_iterator(line.begin(), line.end(), r);
        auto words_end = std::sregex_iterator();

        for (std::sregex_iterator i = words_begin; i != words_end; ++i) {
            if (i->str() == "do()") {
                should_do = true;
            }
            else if(i->str() == "don't()") {
                should_do = false;
            }
            else if (should_do) {
                sum += std::stoi(i->str(1)) * std::stoi(i->str(2));
            }
        }
    }
    std::cout << sum << std::endl;
}