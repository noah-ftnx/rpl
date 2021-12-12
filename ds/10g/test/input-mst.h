#ifndef REPL_DS_10G_INPUT_MST_H_
#define REPL_DS_10G_INPUT_MST_H_

#include <vector>
using namespace std;

struct Edge {
  int src;
  int tgt;
  int w; // weight
};

vector<Edge> input_mst() {
  return {
      {1,2,25},
      {1,6,5},
      {2,3,12},
      {2,7,10},
      {3,4,8},
      {4,5,16},
      {4,7,14},
      {5,6,20},
      {5,7,18}
  };
}

const int V=7;
const int E=9;

#endif //REPL_DS_10G_INPUT_MST_H_
