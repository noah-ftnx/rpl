#ifndef INC_070__CPP_TO_STRING_SET_H
#define INC_070__CPP_TO_STRING_SET_H

#if __has_include ("<set>")
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
#endif



#if __has_include ("<unordered_set>")
template <class T>
string to_string(unordered_multiset<T> &mm) {
    stringstream ss;
    for (auto val: mm) {
        ss << to_string(val) << " ";
    }
    string res = ss.str();
    if (!res.empty()) { res.pop_back(); }
    else { res = "[]"; }

    return res;
}
#endif


#if __has_include ("<map>")
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
#endif


#if __has_include ("<unordered_map>")
template <class T, class X>
string to_string(unordered_multimap<T, X> &mm) {
    stringstream ss;
    for (auto kv : mm) {
        ss << to_string(kv.first) << ":" << to_string(kv.second) << " ";
    }
    string res = ss.str();
    if (!res.empty()) { res.pop_back(); }
    else { res = "[]"; }

    return res;
}
#endif


#endif //INC_070__CPP_TO_STRING_SET_H
