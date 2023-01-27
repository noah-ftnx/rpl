class Solution {


    // in particular component: is there a cyclic course dependencie or not
    bool cycleDFS(const vector<vector<int>> &AL,
                  vector<bool> &visited, vector<bool> &in_stack, int node) {
        // VISIT
        visited[node]=true;
        in_stack[node]=true;

        // VISIT NEIGHBORS
        for (int nei: AL[node]) {
            if (visited[nei]) { // already visited: may have a cycle
                if (in_stack[nei]) return true; // cycle detected (back-edge) 
                // else: not a cycle
            } else { // not visited
                if (cycleDFS(AL, visited, in_stack, nei)) return true; // cycle
            }
        }

        // deal w/ stack
        in_stack[node]=false;
        return false; // no cycles (in this cmp)
    }

public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // prereq:
        // 0: restricted course
        // 1: prereq

        // BUILD ADJACENCY LIST
        vector<vector<int>> AL(numCourses, vector<int>());
        for (auto pair: prerequisites) {
            int rcourse=pair[0];  // restricted course
            int prereq=pair[1];

            // if we take prereq -> we are then allowed to take course
            AL[prereq].push_back(rcourse);
        }

        // IF CYCLES: cannot finish
        vector<bool> visited(numCourses, false); // taken course
        for (int i=0; i<numCourses; i++) {
            vector<bool> in_stack(numCourses, false);
            if (cycleDFS(AL, visited, in_stack, i)) return false; // cycle -> CANNOT finish course
        }

        return true; // no cycles: can finish course
    }
};