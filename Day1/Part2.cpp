#include <iostream>
#include <list>
#include <set>
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

    int sum = 0;
    int count = 0;

    for (int num1 : list1){
        for (int num2 : list2){
            if (num1 == num2){
                sum += num1;
            }
        }
    }
    std::cout << sum << std::endl;
}
