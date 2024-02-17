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
    void floydwarshallMatrix() {
        vector<vector<int>> dist = adjMatrix;

        for (int k = 0; k < V; k++) {
            for (int u = 0; u < V; u++) {
                for (int v = 0; v < V; v++) {
                    if (adjMatrix[u][k] != INF && adjMatrix[k][v] != INF) {
                        dist[u][v] = min(dist[u][v], dist[u][k] + dist[k][v]);
                    }
                }
            }
        }
        print_solution(dist);
    }
    void floydwarshallList(){
        adjMatrix = toAdjMatrix();
        vector<vector<int>> dist = adjMatrix;
        for (int k = 0; k < V; k++) {
            for (int u = 0; u < V; u++) {
                for (int v = 0; v < V; v++) {
                    if (adjMatrix[u][k] != INF && adjMatrix[k][v] != INF) {
                        dist[u][v] = min(dist[u][v], dist[u][k] + dist[k][v]);
                    }
                }
            }
        }
        print_solution(dist);
    }

    void print_solution(const vector<vector<int>> &dist) const {
        cout<<"顶点对之间的最短距离："<<endl;
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (dist[i][j] == INF) {
                    cout << "INF ";
                } else {
                    cout << dist[i][j] << " ";
                }
            }
            cout << endl;
        }
    }
    vector<vector<int>> toAdjMatrix() {
        vector<vector<int>> adjMatrix(V, vector<int>(V, INF));
        for (int i = 0; i < V; i++) {
            adjMatrix[i][i] = 0;
            for (auto& p : adjList[i]) {
                int v = p.first;
                int w = p.second;
                adjMatrix[i][v] = w;
            }
        }
        return adjMatrix;
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

    void floydwarshall() {
        if (useAdjMatrix) {
            floydwarshallMatrix();
        } else {
            floydwarshallList();
        }
    }
};
int main(){
    Graph graph(9, true);
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
    graph.floydwarshall();
    return 0;
}