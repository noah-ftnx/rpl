#include <vector>
#include <string>
#include <utility>
#include <map>
#include <deque>
using namespace std;

int longest_substring(string s, int k) {
  if (s.empty() || k == 0) return 0;
  if (k >=s.size()) return s.size();
  map<char, int> mp;
  deque<char> unq;

  int local=0;
  for (int i=0; i<s.size(); i++) {
    char c = s[i];
    if (mp.contains(c)) { // existing char: update count
      mp[i]++;
    } else { // insert new  char
      // last k unique characters
      if (unq.size()==k) { // move window
        local-=mp[unq.front()];
        mp.erase(unq.front());
        unq.pop_front();
      }
      // push character
      unq.push_back(c);
      mp[c]=1;
    }
    local++;
  }

  return local;
}



#include "test/013.h"
int main() { run_tests(); return 0; }