#include"Floyd.h"
#include<string>
#include<vector>

int main(){
    std::vector<std::string>names{"V0", "V1", "V2", "V3"};
    MatrixGraph<std::string>G(names, 0, 0);
    G.addMGraphEdge(0, 1, 1);
    G.addMGraphEdge(0, 3, 4);
    G.addMGraphEdge(1, 2, 9);
    G.addMGraphEdge(1, 3, 2);
    G.addMGraphEdge(2, 0, 3);
    G.addMGraphEdge(2, 1, 5);
    G.addMGraphEdge(2, 3, 8);
    G.addMGraphEdge(3, 2, 6);

    Floyd<std::string> floyd(G);
    floyd.shortestPath();
    floyd.printPath(1,0);
    cout<<endl;

    return 0;
}