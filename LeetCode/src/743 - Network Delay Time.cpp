/*
Problem Name: Network Delay Time
Problem Link: https://leetcode.com/problems/network-delay-time/
Tag: Graph, Dijkastra Algo
Concept: Use Dijkastra Algo for weighted directed graph to find the shortest distance to farthest node
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> graph(n + 1);
        for (auto it : times) {
            int u = it[0], v = it[1], time = it[2];
            graph[u].push_back({v, time});
        }

        // pq -> {dist, node}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, k});

        vector<int> dist(n + 1, INT_MAX);
        dist[k] = 0;

        while (!pq.empty()) {
            int node = pq.top().second;
            pq.pop();

            for (auto it : graph[node]) {
                int nextNode = it.first;
                int nextDist = it.second;

                if (dist[nextNode] > dist[node] + nextDist) {
                    dist[nextNode] = dist[node] + nextDist;
                    pq.push({dist[nextNode], nextNode});
                }
            }
        }

        int res = 0;
        for (int i = 1; i < dist.size(); i++) {
            if (dist[i] == INT_MAX) return -1;
            res = max(res, dist[i]);
        }
        return res;
    }
};
