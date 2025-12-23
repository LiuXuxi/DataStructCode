#pragma once
#include "../01_MatrixGraph/matrixGraph.h"
#include <vector>
#include <algorithm> // 用于 std::sort
#include <numeric>   // 用于 std::iota
#include"common.h"

template<class T>
class Kruskal {
private:
    std::vector<Edge> allEdges;      // 存储图的所有边
    std::vector<Edge> mstEdges;      // 存储最小生成树的边
    int totalWeight = 0;             // 最小生成树的总权重

    std::vector<int> parent;         // 用于并查集

    // 并查集：查找根节点
    int findRoot(int i) {
        if (parent[i] == i)
            return i;
        // 路径压缩
        return parent[i] = findRoot(parent[i]);
    }

    // 并查集：合并集合
    void uniteSets(int i, int j) {
        int rootI = findRoot(i);
        int rootJ = findRoot(j);
        if (rootI != rootJ) {
            parent[rootI] = rootJ;
        }
    }

    // 执行 Kruskal 算法的核心逻辑
    void calculate(const MatrixGraph<T>& graph) {
        // 1. 从邻接矩阵提取所有边
        for (int i = 0; i < graph.getNodeNum(); ++i) {
            for (int j = i + 1; j < graph.getNodeNum(); ++j) {
                int weight = graph.getEdgeWeight(i, j);
                if (weight > 0) {
                    allEdges.push_back({i, j, weight});
                }
            }
        }

        // 2. 对所有边按权重进行排序
        std::sort(allEdges.begin(), allEdges.end());

        // 3. 初始化并查集
        parent.resize(graph.getNodeNum());
        std::iota(parent.begin(), parent.end(), 0); // parent[i] = i

        // 4. 遍历所有已经按权重从小到大排序好的边，以构建最小生成树。
        // 这是 Kruskal 算法的核心思想：贪心地选择当前权重最小且不会形成环的边。
        for (const auto& edge : allEdges) {
            // 使用并查集的 findRoot 方法检查当前边的两个端点是否属于同一个集合（或连通分量）。
            // 如果它们的根节点不同，说明这两个顶点尚未连通，添加这条边不会形成环路。
            if (findRoot(edge.begin) != findRoot(edge.end)) {
                // 如果不会形成环路，则接受这条边作为最小生成树的一部分。

                // a. 合并这两个顶点所在的集合，表示它们现在已经连通。
                uniteSets(edge.begin, edge.end);

                // b. 将这条边添加到最小生成树的边集 (mstEdges) 中。
                mstEdges.push_back(edge);

                // c. 累加这条边的权重到总权重中。
                totalWeight += edge.weight;

                // 优化：一个包含 N 个顶点的图的最小生成树恰好有 N-1 条边。
                // 当我们已经找到了 N-1 条边时，最小生成树就已经构建完成，可以提前结束循环。
                if (mstEdges.size() == graph.getNodeNum() - 1) {
                    break;
                }
            }
        }
    }

public:
    // 构造函数接收一个图对象，并执行算法
    Kruskal(const MatrixGraph<T>& graph) {
        calculate(graph);
    }

    ~Kruskal() {
        allEdges.clear();
        mstEdges.clear();
        parent.clear();
    }

    // 获取最小生成树的边
    const std::vector<Edge>& getMstEdges() const {
        return mstEdges;
    }

    // 获取最小生成树的总权重
    int getTotalWeight() const {
        return totalWeight;
    }
};


//typedef struct edge {
//    int begin;
//    int end;
//    int weight;
//    bool operator<(const edge& other) const{
//        return weight < other.weight;
//    }
//}Edge;
//
//template<class T>
//class Kruskal {
//private:
//    std::vector<Edge>allEdges;
//    std::vector<Edge>mstEdges;
//    std::vector<int>parent;
//    int totalWeight = 0;
//
//    int findRoot(int a) {
//        if (a == parent[a])return a;
//        return parent[a] = findRoot(parent[a]);
//    }
//
//    void uniteSet(int i, int j) {
//        int rootI = findRoot(i);
//        int rootJ = findRoot(j);
//        if (rootI != rootJ) {
//            parent[rootI] = rootJ;
//        }
//    }
//
//    void calculate(MatrixGraph<T>& graph) {
//        int n = graph.getNodeNum();
//        for (int i = 0; i < n; i++) {
//            for (int j = i + 1; j < n; j++) {
//                int weight = graph.getEdgeWeight(i, j);
//                if (weight > 0) {
//                    allEdges.push_back({ i,j,weight });
//                }
//            }
//        }
//
//        std::sort(allEdges.begin(), allEdges.end());
//
//        parent.resize(n);
//        for (int i = 0; i < n; i++)parent[i] = i;
//
//        for (auto& i : allEdges) {
//            if (findRoot(i.begin) != findRoot(i.end)) {
//                uniteSet(i.begin, i.end);
//                totalWeight += i.weight;
//                mstEdges.push_back(i);
//                if (parent.size() == n - 1)break;
//            }
//        }
//    }
//
//    
//
//    public:
//        // 构造函数接收一个图对象，并执行算法
//        Kruskal(MatrixGraph<T>& graph) {
//            calculate(graph);
//        }
//    
//        // 获取最小生成树的边
//        const std::vector<Edge>& getMstEdges() const {
//            return mstEdges;
//        }
//    
//        // 获取最小生成树的总权重
//        int getTotalWeight() const {
//            return totalWeight;
//        }
//};