#include <unordered_map>
using namespace std;

class SolutionApproach1 {
 public:
  int romanToInt(string s) {
    const int S = s.size();

    unordered_map<char, int> mp {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1e3}
    };

    auto mustMerge = [&](int i) -> bool {
      if (i+1<S) {
        switch (s[i]){
          case 'I': return s[i+1]=='V' || s[i+1]=='X';
          case 'X': return s[i+1]=='L' || s[i+1]=='C';
          case 'C': return s[i+1]=='D' || s[i+1]=='M';
        }
      }
      return false;
    };

    auto getVal = [&] (int i, bool merged) {
      if (merged) {
        return -mp[s[i]] + mp[s[i+1]];
      } else {
        return mp[s[i]];
      }
    };

    int sum=0;
    for (int i=0; i<S; i++) {
      if(mustMerge(i)) {
        sum+=getVal(i, true);
        i++;
      } else sum+=getVal(i, false);
    }

    return sum;
  }
};

#include <unordered_map>
using namespace std;

class Solution {
 public:
  int romanToInt(string s) {
    const int S = s.size();

    unordered_map<char, int> mp {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1e3}
    };

    int sum=0;
    for (int i=0; i<S; i++) {
      // there is a next value that is bigger
      if (i+1 <S && mp[s[i+1]] > mp[s[i]]) {
        sum-=mp[s[i]]; // cur value will be negative
      } else sum+=mp[s[i]];

    }

    return sum;
  }
};