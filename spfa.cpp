//
// Created on 2024/2/17.
//
#include <iostream>
#include <vector>
#include <list>
#include <limits>
#include <queue>
using namespace std;

const int INF = numeric_limits<int>::max();
class Graph {
private:
    int V; // 顶点数
    bool useAdjMatrix; // 是否使用邻接矩阵
    vector<vector<int>> adjMatrix; // 邻接矩阵
    vector<list<pair<int, int>>> adjList; // 邻接表
    void spfaMatrix(int src) {
        vector<int> dist(V, INF);
        vector<int> count(V, 0);// 记录每个顶点入队次数
        vector<bool> inQueue(V, false);
        queue<int> q;
        dist[src] = 0;
        q.push(src);
        inQueue[src] = true;
        count[src]++;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            inQueue[u] = false;
            for (int v = 0; v < V; v++) {
                if (adjMatrix[u][v] != INF && dist[v] > dist[u] + adjMatrix[u][v]) {
                    dist[v] = dist[u] + adjMatrix[u][v];
                    if (!inQueue[v]) {
                        q.push(v);
                        inQueue[v] = true;
                        count[v]++;
                        if (count[v] >= V) {
                            cout << "Graph contains negative weight cycle" << endl;
                            return;
                        }
                    }
                }
            }
        }

        print_solution(dist);
    }
    void spfaList(int src){
        vector<int> dist(V, INF);
        vector<int> count(V, 0);// 记录每个顶点入队次数
        vector<bool> inQueue(V, false);
        queue<int> q;
        q.push(src);
        inQueue[src] = true;
        count[src]++;
        dist[src] = 0;
        while(!q.empty()){
            int u = q.front();
            q.pop();
            inQueue[u] = false;
            for(auto it=adjList[u].begin();it!=adjList[u].end();it++){
                int v = it->first;
                int w = it->second;
                if(dist[v]>dist[u]+w){
                    dist[v] = dist[u] + w;
                    if(!inQueue[v]){
                        q.push(v);
                        inQueue[v] = true;
                        count[v]++;
                        if(count[v]>=V){
                            cout << "Graph contains negative weight cycle" << endl;
                            return;
                        }
                    }
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

    void spfa(int src) {
        if (useAdjMatrix) {
            spfaMatrix(src);
        } else {
            spfaList(src);
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
    graph.spfa(0);
    return 0;
}