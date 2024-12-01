#include <iostream>
#include <list>
#include <bits/stdc++.h>

bool comp(int a, int b) {
    return a <= b;
}

int main(){
    std::list<int> list1 = std::list<int>();
    std::list<int> list2 = std::list<int>();

    int num1, num2;
    while (std::cin >> num1 >> num2){
        list1.push_back(num1);
        list2.push_back(num2);
    }
    list1.sort();
    list2.sort();

    int difference = 0;

    while (!list1.empty()){
        num1 = list1.front();
        num2 = list2.front();
        list1.pop_front();
        list2.pop_front();
        difference += abs(num1 - num2);
    }
    std::cout << difference << std::endl;
}
