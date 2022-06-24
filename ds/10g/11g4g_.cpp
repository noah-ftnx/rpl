#include <vector>
#include <queue>
#include <utility>
using namespace std;

// N is the number of cities/Node given
// #define N 4
#define INF INT_MAX

// Structure to store all the necessary information
// to form state space tree
struct Node {

  // Helps in tracing the path when the answer is found
  // stores the edges of the path
  // completed till current visited node
  vector<pair<int, int> > path;

  vector<vector<int>> reducedMatrix;  // Stores the reduced matrix

  int cost;  // Stores the lower bound

  int vertex;  // Stores the current city number

  int level;  // Stores the total number of cities visited
};

// Formation of edges and assigning
// all the necessary information for new node
Node* newNode(vector<vector<int>> parentMatrix,
              vector<pair<int, int>> const& path,
              int level, int i, int j) {
  Node* node = new Node;

  // Stores parent edges of the state-space tree
  node->path = path;

  // Skip for the root node
  if (level != 0) {

    // Add a current edge to the path
    node->path.push_back(make_pair(i, j));
  }

  const int N = parentMatrix.size();
  node->reducedMatrix = parentMatrix;

  // Change all entries of row i and column j to INF
  // skip for the root node
  for (int k = 0; level != 0 && k < N; k++) {

    // Set outgoing edges for the city i to INF
    node->reducedMatrix[i][k] = INF;

    // Set incoming edges to city j to INF
    node->reducedMatrix[k][j] = INF;
  }

  // Set (j, 0) to INF
  // here start node is 0
  node->reducedMatrix[j][0] = INF;

  // Set number of cities visited so far
  node->level = level;

  // Assign current city number
  node->vertex = j;

  // Return node
  return node;
}

// Function to reduce each row so that
// there must be at least one zero in each row
int rowReduction(vector<vector<int>> reducedMatrix,
                 vector<int> row) {
  const int N = reducedMatrix.size();

  // row[i] contains minimum in row i
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (reducedMatrix[i][j] < row[i]) {
        row[i] = reducedMatrix[i][j];
      }
    }
  }

  // Reduce the minimum value from each element
  // in each row
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (reducedMatrix[i][j] != INF
          && row[i] != INF) {
        reducedMatrix[i][j] -= row[i];
      }
    }
  }
  return 0;
}

// Function to reduce each column so that
// there must be at least one zero in each column
int columnReduction(vector<vector<int>> reducedMatrix, vector<int> col) {
  const int N = reducedMatrix.size();

  // col[j] contains minimum in col j
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (reducedMatrix[i][j] < col[j]) {
        col[j] = reducedMatrix[i][j];
      }
    }
  }
  // Reduce the minimum value from each element
  // in each column
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (reducedMatrix[i][j] != INF
          && col[j] != INF) {
        reducedMatrix[i][j] -= col[j];
      }
    }
  }
  return 0;
}

// Function to get the lower bound on the path
// starting at the current minimum node
int calculateCost(vector<vector<int>> reducedMatrix)
{
  const int N = reducedMatrix.size();

  // Initialize cost to 0
  int cost = 0;

  // Row Reduction
  vector<int> row(N, INF);
  rowReduction(reducedMatrix, row);

  // Column Reduction
  vector<int> col(N, INF);
  columnReduction(reducedMatrix, col);

  // The total expected cost is
  // the sum of all reductions
  for (int i = 0; i < N; i++) {
    cost += (row[i] != INT_MAX) ? row[i] : 0,
        cost += (col[i] != INT_MAX) ? col[i] : 0;
  }
  return cost;
}



// Comparison object to be used to order the heap
struct Min_Heap {
  bool operator()(const Node* lhs, const Node* rhs) const
  {
    return lhs->cost > rhs->cost;
  }
};

// TSP w/ Branch and Bound
int tsp(vector<vector<int>> CostGraphMatrix) {
  const int N = CostGraphMatrix.size();
  // Create a priority queue to store live nodes
  // of the search tree
  priority_queue<Node*, vector<Node*>, Min_Heap> pq;
  vector<pair<int, int> > v;

  // Create a root node and calculate its cost.
  // The TSP starts from the first city, i.e., node 0
  Node* root = newNode(CostGraphMatrix, v, 0, -1, 0);

  // Get the lower bound of the path
  // starting at node 0
  root->cost = calculateCost(root->reducedMatrix);

  // Add root to the list of live nodes
  pq.push(root);

  // Finds a live node with the least cost,
  // adds its children to the list of live nodes,
  // and finally deletes it from the list
  while (!pq.empty()) {

    // Find a live node with
    // the least estimated cost
    Node* min = pq.top();

    // The found node is deleted from
    // the list of live nodes
    pq.pop();

    // i stores the current city number
    int i = min->vertex;

    // If all cities are visited
    if (min->level == N - 1) {

      // Return to starting city
      min->path.push_back(make_pair(i, 0));

      // Return optimal cost
      return min->cost;
    }

    // Do for each child of min
    // (i, j) forms an edge in a space tree
    for (int j = 0; j < N; j++) {
      if (min->reducedMatrix[i][j] != INF) {

        // Create a child node and
        // calculate its cost
        Node* child
            = newNode(min->reducedMatrix, min->path,
                      min->level + 1, i, j);

        child->cost
            = min->cost + min->reducedMatrix[i][j]
              + calculateCost(child->reducedMatrix);

        // Add a child to the list of live nodes
        pq.push(child);
      }
    }

    // Free node as we have already stored edges (i, j)
    // in vector. So no need for a parent node while
    // printing the solution.
    delete min;
  }
  return 0;
}



#include "test/11.h"
int main() { run_tests(tsp); return 0; }