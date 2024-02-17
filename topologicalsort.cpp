//
// Created on 2024/2/17.
//
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

void dfs(int v, vector<bool> &visited, vector<vector<int>> &graph, stack<int> &stack){
    visited[v] = true;
    for(auto &adj : graph[v]){
        if(!visited[adj]){
            dfs(adj, visited, graph, stack);
        }
    }
    stack.push(v); // 当前节点的所有邻接节点都已经访问完毕，将当前节点入栈
}
void dfs_topological_sort(vector<vector<int>> &graph){
    int n = graph.size();
    vector<bool> visited(n, false);
    stack<int> stack;
    for(int i = 0; i < n; i++){
        if(!visited[i]){
            dfs(i, visited, graph, stack);
        }
    }
    while(!stack.empty()){
        cout << stack.top() << " ";
        stack.pop();
    }
    cout << endl;
}
void kahn_topological_sort(vector<vector<int>> &graph){
    int n = graph.size();
    vector<int> in_degree(n, 0);
    // 计算所有节点的入度
    for(int i = 0; i < n; i++){
        for(auto &adj : graph[i]){
            in_degree[adj]++;
        }
    }
    queue<int> q;
    // 将所有入度为0的节点入队
    for(int i = 0; i < n; i++){
        if(in_degree[i] == 0){
            q.push(i);
        }
    }
    // 每次从队列中取出一个节点，将其邻接节点的入度减1，如果减1后入度为0，则入队
    while(!q.empty()){
        int v = q.front();
        q.pop();
        cout << v << " ";
        for(auto &adj : graph[v]){
            in_degree[adj]--;
            if(in_degree[adj] == 0){
                q.push(adj);
            }
        }
    }
    cout << endl;
}
int main(){
    vector<vector<int>> graph = {
            {1, 2},
            {2, 3, 4},
            {3, 7},
            {4, 7},
            {5, 6},
            {6, 7},
            {7},
            {}
    };
    dfs_topological_sort(graph);
    kahn_topological_sort(graph);
    return 0;
}
