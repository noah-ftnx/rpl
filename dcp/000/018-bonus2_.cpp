#include <vector>
#include <utility>
#include <string>
using namespace std;

bool solve(vector<pair<string, string>> flights,
           vector<string>& itinerary) {
  if (flights.empty()) return true;

  for (auto it=flights.begin(); it!=flights.end(); ) {
    auto p = (*it);
    if (itinerary.back() == p.first) {
      // try a solution
      itinerary.push_back(p.second);
      it = flights.erase(it);

      if(solve(flights, itinerary)) return true;

      // backtrack
      it = flights.insert(it, p);
      itinerary.pop_back();
    }
    it++;
  }

  return false;
}

vector<string> get_itinerary(vector<pair<string, string>>& flights, string starting) {
  if (flights.empty() || starting.empty()) return {};

  vector<string> itinerary;
  itinerary.push_back(starting);
  if (!solve(flights, itinerary)) return {};

  return itinerary;
}

void _get_itinerary(vector<pair<string, string>>& flights,
                             vector<string>& itinerary) {

  if (flights.empty()) { return; }

  string last_location=itinerary.back();

  for (int i=0; i<flights.size(); i++) {
    auto pair = flights[i];

    itinerary.push_back(pair.second); // try
    if (pair.first == last_location) { // continue building solution
      flights.erase(flights.begin()+i); // consume flight
      _get_itinerary(flights, itinerary);
      return;
    }
    itinerary.pop_back(); // backtrack
  }

  itinerary.clear();  // no solution
}


vector<string> complex_get_itinerary(vector<pair<string, string>>& flights, string starting) {
  if (starting.empty() || flights.empty()) return {};
  vector<string> itinerary({starting});
  _get_itinerary(flights, itinerary);

  if (flights.empty()) return itinerary;

  return {};
}

#include "test/018-bonus2.h"
int main() {
  run_tests();
  return 0;
}