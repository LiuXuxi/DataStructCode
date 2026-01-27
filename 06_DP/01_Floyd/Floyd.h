#include"../../03_GraphStruct/01_MatrixGraph/matrixGraph.h"
#include<iostream>
using namespace std;

template<class T>
class Floyd {
    private:
        int dist[MaxNodeNum][MaxNodeNum] = { 0 };
        int path[MaxNodeNum][MaxNodeNum] = { 0 };
        int n;
    public:
        Floyd(MatrixGraph<T>& G) {          
            n = G.getNodeNum();
            for (int i = 0; i < G.getNodeNum(); i++) {
                for (int j = 0; j < G.getNodeNum(); j++) {
                    dist[i][j] = G.getEdgeWeight(i, j);
                    if (dist[i][j] < INF && i != j) {
                        path[i][j] = i;
                    }
                    else {
                        path[i][j] = -1;
                    }
                }
            }
        }

        void shortestPath() {
            for (int k = 0; k < n; k++) {
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < n; j++) {
                        if (dist[i][k] + dist[k][j] < dist[i][j]) {
                            dist[i][j] = dist[i][k] + dist[k][j];
                            path[i][j] = path[k][j];
                        }
                    }
                }
            }
        }

        void printPath(int i,int j){
            if (i == j) {
		        cout<<i<<" ";
		        return;
	        }
	        int k = path[i][j];
	        printPath(i, k);
		    cout<<j<<" ";
        }
};