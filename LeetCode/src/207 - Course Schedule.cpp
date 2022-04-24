/*
Problem Name: Course Schedule
Problem Link: https://leetcode.com/problems/course-schedule/
Tag: graph, cycle detection directed graph
Concept: cycle detection in directed graph
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    bool cycleDetectionBFS(vector<vector<int>>& graph, int n) {
        vector<int> indegree(n);
        for (int v = 0; v < n; v++) {
            for (int it : graph[v]) {
                indegree[it]++;
            }
        }

        queue<int> q;
        for (int v = 0; v < n; v++)
            if (indegree[v] == 0) q.push(v);

        int count = 0;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            count++;
            for (int it : graph[node]) {
                indegree[it]--;
                if (indegree[it] == 0) q.push(it);
            }
        }

        if (count == n) return true;
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        for (auto it : prerequisites) {
            graph[it[1]].push_back(it[0]);
        }

        return cycleDetectionBFS(graph, numCourses);
    }
};
