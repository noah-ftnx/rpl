
// #gg
#include <iostream>

#include <vector>
using namespace std;



    using namespace std;
vector<bool>visited; // might possible that graph not connected
vector<int>color; // stored the color of each node , -1 represent no coloring is done yet
bool iscolorable(vector<vector<int>>&graph , int currentNode , const int &k){
  visited[currentNode] = true;
  for(int itr=0;itr<4;++itr){
    if(graph[currentNode][itr] == 0){
      continue;
    }
    if(color[itr] == color[currentNode]){ // if color match with adjacent vertex
      return false;
    }
    if(color[itr] == -1){ // let's color it
      for(int i=0;i<k;++i){ // check all the color
        if(i == color[currentNode]){ // don't color with same as parent
          continue;
        }
        color[itr] = i;
        if(iscolorable(graph , itr , k)){
          return true;
        }
        color[itr] = -1;
      }
      if(color[itr]==-1){ // if can't color this node then no need to check further , let's roll back
        return false;
      }
    }
  }
  return true;
}
int main(void){
  int n = 4; // number of node in graph , starting from 0
  visited.assign(n , false);
  color.assign(n , -1);
  vector< vector<int> > graph  = {
      {0, 1, 1, 1},
      {1, 0, 1, 1},
      {1, 1, 0, 1},
      {1, 1, 1, 0}
  };
  int k = 3; // number of colors
  bool ispossible = true;
  for(int i=0;i<n;++i){
    if(not(visited[i])){
      color[i] = 0; // this is new component so we can color it with any color
      ispossible and_eq iscolorable(graph ,i, k);
    }
  }
  if(ispossible){
    cout<<boolalpha << true<<'\n';
  }else{
    cout<<boolalpha << false<<'\n';
  }
  return 0;
}