#ifndef RPL_DCP_TEST_018_BONUS2_H_
#define RPL_DCP_TEST_018_BONUS2_H_

#include <iostream>

void test(vector<pair<string, string>> flights, string starting, vector<string> correct) {
  auto itinerary = get_itinerary(flights, starting);

  cout << "itinerary: ";
  if (itinerary.size()==0) { cout << "<empty>\n"; return; }
  else {
    auto last_flight = itinerary.back(); itinerary.pop_back();
    for (auto flight: itinerary) cout << flight << " -> ";
    cout << last_flight;
    itinerary.push_back(last_flight);
  }

  cout << (itinerary != correct? " (WRONG)":"") << endl;
}

void test1() {
  string starting = "YUL";
  vector<pair<string, string>> flights {
      {"HNL", "AKL"},
      {"YUL", "ORD"},
      {"ORD", "SFO"},
      {"SFO", "HNL"}
  };

  vector<string> correct { "YUL", "ORD", "SFO", "HNL", "AKL" };

  test(flights, starting, correct);
}

void test2() {
  string starting = "YUL";
  vector<pair<string, string>> flights {
      {"HHH", "AKL"},
      {"YUL", "ORD"},
      {"ORD", "SFO"},
      {"SFO", "HNL"}
  };

  vector<string> correct {};

  test(flights, starting, correct);
}

void test3() {
  string starting = "YUL";
  vector<pair<string, string>> flights {
  };

  vector<string> correct {};

  test(flights, starting, correct);
}


void test4() {
  string starting = "YUL";
  vector<pair<string, string>> flights {
      {"SFO", "HKO"},
      {"YYZ", "SFO"},
      {"YUL", "YYZ"},
      {"HKO", "ORD"}
  };

  vector<string> correct {"YUL", "YYZ", "SFO", "HKO", "ORD"};
  test(flights, starting, correct);
}

void test5() {
  string starting = "COM";
  vector<pair<string, string>> flights {
      {"SFO", "COM"}, {"COM", "YYZ"}
  };

  vector<string> correct {};
  test(flights, starting, correct);
}

void test6() {
  string starting = "A";
  vector<pair<string, string>> flights {
      {"A", "B"},
      {"A", "C"},
      {"B", "C"},
      {"C", "A"}
  };

  vector<string> correct {"A", "B", "C", "A", "C"};
  test(flights, starting, correct);
}


void run_tests() {
  test1();
  test2();
  test3();
  test4();
  test5();
  test6();
}


#endif  // RPL_DCP_TEST_018_BONUS2_H_
