#ifndef INC_070__CPP_TO_STRING_VEC_H
#define INC_070__CPP_TO_STRING_VEC_H

/**
 * 1D vector
 *
 * @param width iomanip width
 */
template<class T>
string to_string(vector<T> vec, int width=1) {
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


string to_string(vector<char> vec, int width=1) {
    if (vec.empty()) return "{}";
    else {
        string s = "{";
        for (auto ch: vec) {
            stringstream ss;
            ss << setw(width) << ch;
            s+= ss.str() + ", ";
        }
        s.pop_back();
        s.pop_back();
        s+="}";
        return s;
    }
}


/**
 * 2D vector
 *
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


template<class T>
string to_string_pretty(vector<vector<T>> vec, bool sameLine=true, int width=4) {
  return to_string(vec, false, 3);
}

#endif //INC_070__CPP_TO_STRING_VEC_H
