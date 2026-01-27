#include"knapscak.h"
#include<vector>
#include<iostream>

int main(){
    std::vector<int>weight{1,2,3};
    std::vector<int>value{6,10,12};
    int capacity = 5;
    knapsack<int>ks(weight,value,capacity);
    std::cout << ks.knapsack01() << std::endl;
    std::cout << ks.knapsack02() << std::endl;
    std::cout << ks.DP() << std::endl;
    return 0;
}