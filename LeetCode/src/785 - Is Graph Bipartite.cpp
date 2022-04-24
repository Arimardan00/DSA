/*
Problem Name: Is Graph Bipartite
Problem Link: https://leetcode.com/problems/is-graph-bipartite/
Tag: graph, check bipartite
Concept: check bipartite graph
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool bfs(int node, vector<int> &color, vector<vector<int>> &graph){
        queue<int> q;
        q.push(node);
        color[node] = 1;
        
        while(!q.empty()){
            node = q.front();
            q.pop();
            
            for(int it: graph[node]){
                if(color[it] == -1){
                    q.push(it);
                    color[it] = 1 - color[node];
                } else if(color[it] == color[node]) return false;
            }            
        }
        
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);
        for(int v = 0; v < n; v++){
            if(color[v] == -1 && !bfs(v, color, graph)) return false;
        }
        return true;
    }
};