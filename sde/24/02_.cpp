class Solution {
 public:
  //Function to find the shortest distance of all the vertices
  //from the source vertex S.
  vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
  {
    // adj: i: vertex: list is: target, cost
    vector<int> dist(V, INT_MAX);
    queue<pair<int, int>> q;
    dist[S]=0; // no cost to reach itself
    q.push({S, 0});
        
    while(!q.empty()) {
      auto p = q.front(); q.pop();
      // visit here, so we can keep updating the costs
      // (consider all edges in loop)
      int vertex=p.first;
      int cost=p.second;

            
      for (auto p: adj[vertex]) {
        int nei=p[0];
        int ncost=p[1];
     
        if (cost+ncost < dist[nei]) {
          dist[nei]=cost+ncost;
          q.push({nei, dist[nei]});
        }
      }
    }
    return dist;
  }
};



class SolutionOPT {
 public:
  //Function to find the shortest distance of all the vertices
  //from the source vertex S.
  vector <int> dijkstra(int V, vector<vector<int>> adj[], int S) {
    // adj: i: vertex: list is: target, cost
    vector<int> dist(V, INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    dist[S]=0; // no cost to reach itself
    q.push({S, 0});

    while(!q.empty()) {
      auto p = q.top(); q.pop();
      // visit here, so we can keep updating the costs
      // (consider all edges in loop)
      int vertex=p.first;
      int cost=p.second;

      for (auto p: adj[vertex]) {
        int nei=p[0];
        int ncost=p[1];

        if (cost+ncost < dist[nei]) {
          dist[nei]=cost+ncost;
          q.push({nei, dist[nei]});
        }
      }
    }
    return dist;
  }
};