#include <vector>
#include <utility>
#include <string>
using namespace std;

vector<string> _get_itinerary(vector<pair<string, string>>& flights,
                             vector<string>& itinerary) {

  if (flights.empty()) { return itinerary; }

  string last_location=itinerary.back();

  for (int i=0; i<flights.size(); i++) {
    auto pair = flights[i];

    itinerary.push_back(pair.second); // try
    if (pair.first == last_location) { // continue building solution
      flights.erase(flights.begin()+i); // consume flight
      return _get_itinerary(flights, itinerary);
    }
    itinerary.pop_back(); // backtrack
  }

  return {};  // nothing found
}


vector<string> get_itinerary(vector<pair<string, string>>& flights, string starting) {
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