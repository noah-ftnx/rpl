#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
  bool DFS(unordered_map<int, vector<int>> &AL,
           vector<bool> &visited, vector<bool> &in_stack, int i) {
    visited[i]=in_stack[i]=true;

    for (int nei: AL[i]) {
      if (!visited[nei]) {
        if (DFS(AL, visited, in_stack, nei)) return true;
      } else {
        if (in_stack[nei]) return true; // back-edge
      }
    }

    in_stack[i]=false;
    return false;
  }

  bool hasCycles(int N, unordered_map<int, vector<int>> &AL) {
    vector<bool> visited(N, false);
    vector<bool> in_stack(N, false);

    for (auto pair: AL) {
      int vertex = pair.first;
      if (!visited[vertex] && DFS(AL, visited, in_stack, vertex)) return true;
    }

    return false;
  }

 public:
  bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

    unordered_map<int, vector<int>> AL;
    for (auto prereq: prerequisites) {
      int vertex=prereq[0];
      int neighbor=prereq[1];

      AL[vertex].push_back(neighbor);
    }

    return !hasCycles(numCourses, AL);
  }
};
