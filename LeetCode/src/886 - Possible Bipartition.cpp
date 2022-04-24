/*
Problem Name: Possible Bipartition
Problem Link: https://leetcode.com/problems/possible-bipartition/
Tag: graph, check bipartition
Concept: check bipartition in undirected graph
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    bool bfs(int node, vector<int> &color, vector<vector<int>> &graph) {
        queue<int> q;
        q.push(node);
        color[node] = 1;

        while (!q.empty()) {
            node = q.front();
            q.pop();

            for (int it : graph[node]) {
                if (color[it] == -1) {
                    q.push(it);
                    color[it] = 1 - color[node];
                } else if (color[it] == color[node])
                    return false;
            }
        }

        return true;
    }

    bool possibleBipartition(int n, vector<vector<int>> &dislikes) {
        vector<vector<int>> graph(n + 1);
        for (auto p : dislikes) {
            int u = p[0], v = p[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        vector<int> color(n + 1, -1);
        for (int v = 1; v <= n; v++) {
            if (color[v] == -1 && !bfs(v, color, graph)) return false;
        }
        return true;
    }
};