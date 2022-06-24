#ifndef INC_070__CPP_CHECK_VEC_H_
#define INC_070__CPP_CHECK_VEC_H_

#include <string>
#include <sstream>

string pretty_num(int num) {
  if (num >= INT_MAX) return "++";
  else if (num == INT_MIN) return "--";
  else return to_string(num);
}

/**
 * @param width iomanip width
 */
string to_string(vector<int> vec, int width=1) {
  if (vec.empty()) return "{}";
  else {
    string s = "{";
    for (auto num: vec) {
      stringstream ss;
      ss << setw(width) << pretty_num(num);
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

    bool firstLine=true;
    for (auto row: vec) {
      if (!sameLine) {
        stringstream ss;
        ss << setw(width) << (firstLine?" {":" ");
        s+=ss.str();
      }
      firstLine=false;
      s += to_string(row, width) + ","+SEP;
    }

    s.pop_back();
    s.pop_back();

    if (!sameLine) s+="}";
    return s;
  }
}


string to_string_pretty(vector<vector<int>> vec, bool sameLine=true, int width=4) {
  return to_string(vec, false, 3);
}



#endif  // INC_070__CPP_CHECK_VEC_H_
