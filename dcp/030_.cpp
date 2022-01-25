#include <vector>
using namespace std;


int overkill(vector<int> walls) {
  if (walls.size()<=2) return 0;

  int st=INT_MIN, end=INT_MIN, endIdx=-1;
  int slots {}, sum {}, result {};

  auto calc_water = [&]() {
    if (end==INT_MIN) { return; }

    int capacity = min(st, end);
    int w = capacity * slots - sum;
    result+=w;
  };

  st=walls[0];
  for (int i=1; i<walls.size(); i++) {
    if (walls[i] >= walls[i-1]) {  // higher wall:
      // greater than start, with min unset: update start
      if (walls[i] >= st && end==INT_MIN) {
        st=walls[i];
      } else { // new end wall
        slots++;
        sum+=walls[endIdx];
        end=walls[i];
        endIdx=i;
      }
    } else {  // smaller wall
      if (end==INT_MIN) { // init min
        end=walls[i];
        endIdx=i;
      } else {  // assume in a pool
        slots++;
        sum+=walls[i];
      }
    }

    if (end>=st) { // matched start: flush pool
      calc_water();
      st=end;
      end=INT_MIN;
      slots=sum=0;
    }
  }

  // edge case: properly close last pool
  if (end!=INT_MIN)  {
    sum=slots=0;
    end=walls[walls.size()-1];
    for (int i=walls.size()-2; i>=0; i--) {
      if (walls[i]>end) break;
      sum+=walls[i];
      slots++;
    }
    st=end; // does not matter, just to make it a pool
    calc_water();
  }

  return result;
}


int capacity(vector<int> walls){
  int max_wall=0, left=0, right=walls.size()-1, ans {};

  while(left < right){
    // take the lower, and then advance it accordingly
    int idx = walls[left] <= walls[right] ? left++ : right--;
    int lower_wall = walls[idx];

    // max-level/height we have seen so far
    max_wall = max(max_wall, lower_wall);

    ans += (max_wall - lower_wall);
  }
  return ans;
}


#include "test/030.h"
int main() { run_tests(); return 0; }