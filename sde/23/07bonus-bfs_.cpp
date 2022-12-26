class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // 5, 3: to take 3, must first finish 5: 3 has prerequisite 6
        // prereq, course

        // graph:
        // nodes w/o prereq: no incoming edges
        // an edge: points: from prereq, to restricted course
        // AL: 

        // Dim1: node
        // Dim2: edges to nei that have node as prerequisite (inner vector)
        vector<vector<int>> AL(numCourses, vector<int>());
        vector<int> indegree(numCourses, 0);

        // build DiGraph & compute indegree
        for (auto pair: prerequisites) {
            int rcourse = pair[0]; // to take course 0 (restricted course)
            int prereq = pair[1];  // must finish course 1 before

            AL[prereq].push_back(rcourse);
            indegree[rcourse]++;
        }

        // BFS solution
        queue<int> q;
        for (int vertex=0; vertex<numCourses; vertex++) {
            if (indegree[vertex]==0) q.push(vertex);
        }

        int takenCourses=0;
        while (!q.empty()) {
            // visit: take course (one w/ satisfied prereq)
            auto course=q.front(); q.pop();
            takenCourses++;

            // check what restricted courses we can take
            for (int nei: AL[course]) {
                indegree[nei]--; // satisfied one restriction
                if (indegree[nei]==0) {
                    q.push(nei);
                }
            }
        }

        return takenCourses == numCourses;
    }
};