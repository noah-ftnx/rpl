#include <string>
#include <vector>
using namespace std;

int longest_path(string fsys) {
  if (fsys.empty()) return 0;

  int res;
  int local = 0;
  vector<int> depth_len;  // keep depths of cur folders. idx is depth.

  bool folder=true;
  int start = 0;
  int depth = 0;
  for (int i=start; i<=fsys.size(); i++) {
    const char c = i==fsys.size()?'\n':fsys[i];

    // dir:3
    // dir/fooooo: 3+ 1+6
    // dir/fooooo/.txt: 3+1+6+ 1+4

    // dir:3
    // dir/fooooo: 3+ 1+6
    // dir/baar:
    // dir/baar/.txt: 3+1+6+ 1+4

    if  (c=='\n') { // file/folder found
      // i has an extra char: '\n'. but it's ok:
      // assume single char folder at idx: 7. its 7 to 7, and it must be 1.
      const int len = i-start;

      if (folder) {
        // subtract previous levels
        // DL: 0, 1, 2: 3
        // D: 1
        while (depth < depth_len.size()) {
          local-=depth_len.back();
          depth_len.pop_back();
        }

        local+=len;
        depth_len.push_back(len);

      } else { // file: update max
        const int slash_num = depth;
        res = max(res, local+slash_num+len);
      }

      // reset for next fs node
      start=i+1;
      depth=0;
      folder=true;
    } else if (c=='\t') {
      depth++;
      start=i+1;
    } else if (c == '.') {
      folder=false;
    }
  }

  return res;
}



#include "test/017.h"
int main() { run_tests(); return 0; }