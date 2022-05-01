/*
Problem Name: Path With Minimum Effort
Problem Link: https://leetcode.com/problems/path-with-minimum-effort/
Tag: Graph, Dijkastra Algo
Concept: naive BFS to Dijkastra using newDist < dist[nr][nc] instead of visited nodes
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size(), m = heights[0].size();
        int dir[5] = {0, 1, 0, -1, 0};

        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        dist[0][0] = 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, 0});

        while (!pq.empty()) {
            auto node = pq.top();
            pq.pop();
            int d = node.first, r = node.second / 100, c = node.second % 100;

            if (d > dist[r][c]) continue;
            if (r == n - 1 && c == m - 1) return d;

            for (int i = 0; i < 4; i++) {
                int nr = r + dir[i], nc = c + dir[i + 1];
                if (nr < 0 || nr >= n || nc < 0 || nc >= m) continue;

                int newDist = max(d, abs(heights[nr][nc] - heights[r][c]));
                if (newDist < dist[nr][nc]) {
                    dist[nr][nc] = newDist;
                    pq.push({newDist, nr * 100 + nc});
                }
            }
        }
        return -1;
    }
};