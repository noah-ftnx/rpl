#include <vector>
#include <utility>
#include <string>
using namespace std;

// SLOWER VERSION: does not use a HashMap

void BT(vector<pair<string, string>>& flights,
        vector<string>& result,
        vector<string>& cur_trip, string src) {

  static vector<bool> flight_used(flights.size(), false);
  if (cur_trip.size() == flights.size()) {
    cur_trip.push_back(src); // push the last destination
    bool use_trip=result.empty();
    if (!use_trip) { // see if lexicographically 1st
      for (int i=0; !use_trip && i<cur_trip.size(); i++) {
        auto cp = cur_trip[i];
        auto rp = result[i];
        if (rp < cp) break; // dont use it
        else if (cp < rp) use_trip=true; // use it
      }
    }
    if (use_trip) result=cur_trip;
    cur_trip.pop_back(); // pop the last destination
    return;
  }

  for (int i=0; i<flights.size(); i++) {
    auto p = flights[i];
    if (!flight_used[i] && p.first == src) {
      flight_used[i]=true;
      cur_trip.push_back(src);
      BT(flights, result, cur_trip, p.second);
      cur_trip.pop_back();
      flight_used[i]=false;
    }
  }
}


vector<string> get_itinerary
    (vector<pair<string, string>> flights, string start) {
  if (flights.empty() || start.empty()) return {};
  vector<string> result, cur_trip;
  BT(flights, result, cur_trip, start);
  return result;
}



#include "test/041.h"
int main() { run_tests(); return 0; }