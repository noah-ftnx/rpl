#include <vector>
#include <utility>
#include <string>
using namespace std;

vector<string> _get_itirenary(vector<pair<string, string>>& flights,
                             vector<string>& itirenary) {

  if (flights.empty()) {
    return itirenary;
  }

  string last_location=itirenary.back();

  int i = 0;
  for (int i=0; i<flights.size(); i++) {
    auto pair = flights[i];

    itirenary.push_back(pair.second); // try
    if (pair.first == last_location) { // continue building solutoin
      flights.erase(flights.begin()+i);
      return _get_itirenary(flights, itirenary);
    }
    itirenary.pop_back(); // backtrack
  }

  return {};  // nothing found
}


vector<string> get_itirenary(vector<pair<string, string>>& flights, string starting) {
  if (starting.empty() || flights.empty()) return {};
  vector<string> itirenary({starting});
  _get_itirenary(flights, itirenary);

  if (flights.empty()) return itirenary;

  return {};
}

#include "test/018-bonus2.h"
int main() {
  run_tests();
  return 0;
}