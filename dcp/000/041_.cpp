#include <vector>
#include <string>
#include <unordered_map>
#include <utility>
using namespace std;

void BT(unordered_multimap<string, string>& flights, int N,
        vector<string>& result, string src) {
  static vector<string> cur_trip;

  if(cur_trip.size() == N) { // found a valid trip
    cur_trip.push_back(src); // add last dest

    bool use_trip=result.empty();
    if (!use_trip) { // is it lexicographically first?
      for (int i=0; !use_trip && i<=N; i++) {
        string cur_t=cur_trip[i];
        string best_t=result[i];
        if (best_t < cur_t) break;
        else if(cur_t < best_t) use_trip=true;
      }
    }

    if (use_trip) {
      result=cur_trip;
    }
    cur_trip.pop_back(); // remove last dest
    return;
  }

  if (flights.contains(src)) {
    auto it = flights.find(src);
    flights.erase(it);
    cur_trip.push_back(it->first);

    BT(flights, N, result, it->second);

    cur_trip.pop_back();
  }
}

vector<string> get_itinerary
    (vector<pair<string, string>> flights, string start) {
  vector<string> result;
  unordered_multimap<string, string> mp;
  for (auto p: flights) mp.insert(p); // TODO insert pair
  BT(mp, flights.size(), result, start);
  return result;
}



#include "test/041.h"
int main() { run_tests(); return 0; }