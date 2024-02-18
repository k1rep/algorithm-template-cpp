//
// Created on 2024/2/18.
//
#include <iostream>
#include <vector>
using namespace std;
class Graph{
private:
    int n;
    vector<vector<int>> graph;
public:
    explicit Graph(int n){
        this->n = n;
        graph.resize(n, vector<int>(n, -1));
    }
    void add_edge(int u, int v, int w){
        graph[u][v] = w;
        graph[v][u] = w; // 无向图
    }
    void prim(){
        // lowcost[i]表示生成树到达节点i的最小权值
        vector<int> lowcost(n, -1);
        // closest[i]表示生成树到达节点i的最小权值的边的另一端节点
        vector<int> closest(n, -1);
        // 已经在最小生成树中的节点
        vector<bool> s(n, false);
        s[0] = true;
        for(int i = 1; i < n; i++){
            lowcost[i] = graph[0][i];
            closest[i] = 0;
        }
        for(int i = 1; i < n; i++){
            int min = INT_MAX;
            int j = 0;
            for(int k = 1; k < n; k++){
                if(lowcost[k] >= 0 && lowcost[k] < min){
                    min = lowcost[k];
                    j = k;
                }
            }
            cout << closest[j] << " " << j << endl;
            s[j] = true;
            lowcost[j] = -1;
            for(int k = 1; k < n; k++){
                if(graph[j][k] >= 0 && !s[k] && (lowcost[k] == -1 || graph[j][k] < lowcost[k])){
                    lowcost[k] = graph[j][k];
                    closest[k] = j;
                }
            }
        }
    }
};
int main(){
    Graph g(6);
    g.add_edge(0, 1, 6);
    g.add_edge(0, 2, 1);
    g.add_edge(0, 3, 5);
    g.add_edge(1, 2, 5);
    g.add_edge(1, 4, 3);
    g.add_edge(2, 3, 5);
    g.add_edge(2, 4, 6);
    g.add_edge(2, 5, 4);
    g.add_edge(3, 5, 2);
    g.add_edge(4, 5, 6);
    g.prim();
    return 0;
}
