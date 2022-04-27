/*
Problem Name: Path with Maximum Probability
Problem Link: https://leetcode.com/problems/path-with-maximum-probability/
Tag: Graph, Dijkastra Algo
Concept: Use Dijkastra using max heap as we are trying to find maximum success value
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<vector<pair<int, double>>> graph(n);
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0], v = edges[i][1];
            double dist = succProb[i];
            graph[u].push_back({v, dist});
            graph[v].push_back({u, dist});
        }

        priority_queue<pair<double, int>> pq;  // max heap
        pq.push({1, start});

        vector<double> dist(n, -1);
        dist[start] = 1;

        while (!pq.empty()) {
            int node = pq.top().second;
            pq.pop();

            for (auto it : graph[node]) {
                int nextNode = it.first;
                double nextDist = it.second;

                if (dist[nextNode] < dist[node] * nextDist) {
                    dist[nextNode] = dist[node] * nextDist;
                    pq.push({dist[nextNode], nextNode});
                }
            }
        }

        if (dist[end] == -1)
            return 0;
        else
            return dist[end];
    }
};