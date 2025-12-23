#pragma once

struct Edge {
    int begin;
    int end;
    int weight;

    // 为 std::sort 提供比较函数
    bool operator<(const Edge& other) const {
        return weight < other.weight;
    }
};