#ifndef KNAPSACK_H
#define KNAPSACK_H

#include<vector>

template<class T>
class knapsack{
private:
    std::vector<T> wt_goods;
    std::vector<T> val_goods;
    T capacity;

private:
    T Helper01(int index,T c){
        if (index < 0 || c <= 0)return 0;
        T res = Helper01(index - 1, c);
        if (c >= wt_goods[index]) {
            res = std::max(res, val_goods[index] + Helper01(index - 1, c - wt_goods[index]));
        }
        return res;
    }

    T Helper02(int index,T c,std::vector<std::vector<T>>&mem){
        if (index < 0 || c <= 0)return 0;
        if (mem[index][c] != -1)return mem[index][c];
        T res = Helper02(index - 1, c, mem);
        if(c>=wt_goods[index])res = std::max(res, val_goods[index] + Helper02(index - 1, c - wt_goods[index],mem));
        mem[index][c] = res;
        return res;
    }

public:
    knapsack(const std::vector<T>&wt_goods,const std::vector<T>&val_goods,T capacity):
    wt_goods(wt_goods),val_goods(val_goods),capacity(capacity){}

    T knapsack01(){
        return Helper01(wt_goods.size()-1,capacity);
    }

    T knapsack02(){
        std::vector<std::vector<T>>mem(wt_goods.size(),std::vector<T>(capacity+1,-1));
        return Helper02(wt_goods.size() - 1, capacity, mem);
    }
    
    T DP(){
        std::vector<std::vector<T>>dp(wt_goods.size(), std::vector<T>(capacity + 1, -1));
        for (auto& i : dp[0]) i = i >= wt_goods[0] ? wt_goods[0] : 0;
        for (int i = 1; i < dp.size(); i++) {
            for (int j = 0; j < dp[i].size(); j++) {
                dp[i][j] = dp[i - 1][j];
                if (j >= wt_goods[i])dp[i][j] = std::max(dp[i][j], val_goods[i] + dp[i - 1][j - wt_goods[i]]);
            }
        }
        return dp[wt_goods.size() - 1][capacity];
    }
};

#endif // KNAPSACK_H