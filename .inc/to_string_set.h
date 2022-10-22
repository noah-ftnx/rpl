#ifndef INC_070__CPP_TO_STRING_SET_H
#define INC_070__CPP_TO_STRING_SET_H

template <class T>
string to_string(multiset<T> &mm) {
    stringstream ss;
    for (auto val: mm) {
        ss << to_string(val) << " ";
    }
    string res = ss.str();
    if (!res.empty()) { res.pop_back(); }
    else { res = "[]"; }

    return res;
}

template <class T, class X>
string to_string(multimap<T, X> &mm) {
    stringstream ss;
    for (auto kv : mm) {
        ss << to_string(kv.first) << ":" << to_string(kv.second) << " ";
    }
    string res = ss.str();
    if (!res.empty()) { res.pop_back(); }
    else { res = "[]"; }

    return res;
}

#endif //INC_070__CPP_TO_STRING_SET_H
