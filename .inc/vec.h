#ifndef INC_070__CPP_CHECK_VEC_H_
#define INC_070__CPP_CHECK_VEC_H_

#include <string>
#include <sstream>

/**
 * @param width iomanip width
 */
string to_string(vector<int> vec, int width=1) {
  if (vec.empty()) return "{}";
  else {
    string s = "{";
    for (auto v: vec) {
      stringstream ss;
      ss << setw(width) << v;
      s+= ss.str() + ", ";
    }
    s.pop_back();
    s.pop_back();
    s+="}";
    return s;
  }
}


/**
 * @param width iomanip width
 */
template <class T>
string to_string(vector<vector<T>> vec, bool sameLine=true, int width=1) {
  if (vec.empty()) return "{}";
  else {
    string SEP = sameLine? " " : "\n";
    string s;// = "{";
    // string s

    for (auto row: vec) {
      s += to_string(row, width) + ","+SEP;
    }

    s.pop_back();
    s.pop_back();

    // s+="}";
    return s;
  }
}


#endif  // INC_070__CPP_CHECK_VEC_H_
