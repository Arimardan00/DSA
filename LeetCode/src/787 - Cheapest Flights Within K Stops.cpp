/*
Problem Name: Cheapest Flights Within K Stops
Problem Link: https://leetcode.com/problems/cheapest-flights-within-k-stops/
Tag: Graph, Bellman Ford
Concept:
    - Use Bellman Ford to find the shortest distance
    - use a temp array in every interator of k size,
      so that only adjacent steps value gets updated
      d[v] = min(d[v], dist[u] + wt) where d is temp array
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> dist(n, 1e9);
        dist[src] = 0;

        for (int i = 0; i <= k; i++) {
            vector<int> d(dist);
            for (auto it : flights) {
                int u = it[0], v = it[1], wt = it[2];
                d[v] = min(d[v], dist[u] + wt);
            }
            dist = d;
        }

        return dist[dst] == 1e9 ? -1 : dist[dst];
    }
};