#ifndef INC_070__CPP_TO_STRING_PRIMITIVE_H
#define INC_070__CPP_TO_STRING_PRIMITIVE_H

string to_string(void* ptr) {
    stringstream ss;
    ss << "0x" << std::hex << reinterpret_cast<uintptr_t>(ptr);

    return ss.str();
}

string to_string(string s) { // just for compatibility
    return s;
}

#endif //INC_070__CPP_TO_STRING_PRIMITIVE_H
