#include "base.h"

void test(vector<char> input, int n, int correct) {
    auto result = solve(input, n);
    check_result(input, result, correct);
}

vector<char> to_vector(string s) {
    vector<char> v;
    copy(s.begin(), s.end(), back_inserter(v));
    return v;
}

void run_tests() {
    test(to_vector("AAABBB"), 0, 6);
    test(to_vector("AAABBB"), 1, 6);
    // A_A_AB_B_B
    test(to_vector("AAABBB"), 2, 10);
}