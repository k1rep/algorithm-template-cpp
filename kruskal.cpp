//
// Created on 2024/2/18.
//
#include <iostream>
#include <vector>
using namespace std;

class DisjointSetUnion{
private:
    vector<int> parent;
    vector<int> rank;
public:
    DisjointSetUnion(int n){
        parent.resize(n);
        rank.resize(n);
        for(int i = 0; i < n; i++){
            parent[i] = i;
            rank[i] = 1;
        }
    }
    int find(int x){
        if(parent[x] == x){
            return x;
        }
        parent[x] = find(parent[x]);
        return parent[x];
    }
    void unite(int x, int y){
        int root_x = find(x);
        int root_y = find(y);
        if(root_x == root_y){
            return;
        }
        if(rank[root_x] < rank[root_y]){
            swap(root_x, root_y);
        }
        parent[root_y] = root_x;
        rank[root_x] += rank[root_y];
    }
};
class Graph{
private:
    int n;
    vector<vector<int>> edges;
public:
    Graph(int n){
        this->n = n;
    }
    void add_edge(int u, int v, int w){
        edges.push_back({w, u, v});
    }
    void kruskal(){
        DisjointSetUnion dsu(n);
        sort(edges.begin(), edges.end());
        int res = 0;
        for(auto &edge : edges){
            int w = edge[0], u = edge[1], v = edge[2];
            if(dsu.find(u) != dsu.find(v)){
                dsu.unite(u, v);
                res += w;
                cout<<u<<"--"<<v<<"=="<<w<<endl;
            }
        }
        cout<<res<<endl;
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
    g.kruskal();
    return 0;
}
