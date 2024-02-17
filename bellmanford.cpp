//
// Created on 2024/2/17.
//
#include <iostream>
#include <vector>
#include <list>
#include <limits>
using namespace std;

const int INF = numeric_limits<int>::max();
class Graph {
private:
    int V; // 顶点数
    bool useAdjMatrix; // 是否使用邻接矩阵
    vector<vector<int>> adjMatrix; // 邻接矩阵
    vector<list<pair<int, int>>> adjList; // 邻接表
    void bellmanfordMatrix(int src) {
        vector<int> dist(V, INF);
        dist[src] = 0;
        // 对每条边进行V-1次松弛操作
        for (int i = 0; i < V - 1; i++) {
            for (int u = 0; u < V; u++) {
                for (int v = 0; v < V; v++) {
                    if (adjMatrix[u][v] != INF) {
                        dist[v] = min(dist[v], dist[u] + adjMatrix[u][v]);
                    }
                }
            }
        }
        // 检查是否有负权回路
        for (int u = 0; u < V; u++) {
            for (int v = 0; v < V; v++) {
                if (adjMatrix[u][v] != INF) {
                    if (dist[v] > dist[u] + adjMatrix[u][v]) {
                        cout << "Graph contains negative weight cycle" << endl;
                        return;
                    }
                }
            }
        }
        print_solution(dist);
    }
    void bellmanfordList(int src){
        vector<int> dist(V, INF);
        dist[src] = 0;
        for(int i=0;i<V-1;i++){
            for(int u=0;u<V;u++){
                for(auto it=adjList[u].begin();it!=adjList[u].end();it++){
                    int v = it->first;
                    int weight = it->second;
                    dist[v] = min(dist[v], dist[u]+weight);
                }
            }
        }
        for(int u=0;u<V;u++){
            for(auto it=adjList[u].begin();it!=adjList[u].end();it++){
                int v = it->first;
                int weight = it->second;
                if(dist[v]>dist[u]+weight){
                    cout << "Graph contains negative weight cycle" << endl;
                    return;
                }
            }
        }
        print_solution(dist);
    }

    void print_solution(const vector<int> &dist) const {
        cout << "顶点到源点的最短距离：" << endl;
        for (int i = 0; i < V; i++) {
            cout << i << " " << dist[i] << endl;
        }
    }
public:
    explicit Graph(int V, bool useAdjMatrix = true) : V(V), useAdjMatrix(useAdjMatrix) {
        adjList.resize(V);
        adjMatrix.resize(V, vector<int>(V, INF));
        for(int i=0;i<V;i++){
            adjMatrix[i][i] = 0;
        }
    }

    void addEdge(int u, int v, int w) {
        if (useAdjMatrix) {
            adjMatrix[u][v] = w;
            adjMatrix[v][u] = w; // 无向图
        } else {
            adjList[u].emplace_back(make_pair(v, w));
            adjList[v].emplace_back(make_pair(u, w)); // 无向图
        }
    }

    void bellmanford(int src) {
        if (useAdjMatrix) {
            bellmanfordMatrix(src);
        } else {
            bellmanfordList(src);
        }
    }
};
int main(){
    Graph graph(9, false);
    graph.addEdge(0, 1, 4);
    graph.addEdge(0, 7, 8);
    graph.addEdge(1, 2, 8);
    graph.addEdge(1, 7, 11);
    graph.addEdge(2, 3, 7);
    graph.addEdge(2, 8, 2);
    graph.addEdge(2, 5, 4);
    graph.addEdge(3, 4, 9);
    graph.addEdge(3, 5, 14);
    graph.addEdge(4, 5, 10);
    graph.addEdge(5, 6, 2);
    graph.addEdge(6, 7, 1);
    graph.addEdge(6, 8, 6);
    graph.addEdge(7, 8, 7);
    graph.bellmanford(0);
    return 0;
}