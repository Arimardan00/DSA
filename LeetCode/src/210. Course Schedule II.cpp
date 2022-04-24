/*
Problem Name: Course Schedule II
Problem Link: https://leetcode.com/problems/course-schedule-ii/
Tag: graph, toposort
Concept: return toposort or {}
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    vector<int> checkCycleBFS(vector<vector<int>>& graph, int n) {
        queue<int> q;
        vector<int> indegree(n);

        for (int v = 0; v < n; v++) {
            for (int it : graph[v]) {
                indegree[it]++;
            }
        }

        for (int v = 0; v < n; v++)
            if (indegree[v] == 0) q.push(v);

        vector<int> toposort;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            toposort.push_back(node);
            for (int it : graph[node]) {
                indegree[it]--;
                if (indegree[it] == 0) {
                    q.push(it);
                }
            }
        }

        if (toposort.size() == n) return toposort;
        return {};
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        for (auto it : prerequisites) {
            graph[it[1]].push_back(it[0]);
        }

        return checkCycleBFS(graph, numCourses);
    }
};