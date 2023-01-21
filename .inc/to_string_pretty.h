#ifndef INC_070__CPP_TO_STRING_PRETTY_H
#define INC_070__CPP_TO_STRING_PRETTY_H


template<class T, class Y>
string pretty_num(pair<T, Y> pair) {
    string s1 = to_string(pair.first);
    string s2 = to_string(pair.second);
    return "{"+s1+", "+s2+"}";
}   

string pretty_num(float num) {
    string str = to_string(num);
    // remove trailing zeros:
    str.erase( str.find_last_not_of('0') + 1, std::string::npos);
    str.erase( str.find_last_not_of('.') + 1, std::string::npos);
    return str;
}

string pretty_num(int num) {
    if (num >= INT_MAX) return "+∞";
    else if (num == INT_MIN) return "-∞";
    else return to_string(num);
}

#endif //INC_070__CPP_TO_STRING_PRETTY_H
