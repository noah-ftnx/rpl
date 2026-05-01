#include "base.h"

void test(vector<char> input, int n, int correct) {
    const string msg = "N=" + to_string(n) + " ";
    auto result = solve(input, n);
    bool wrong = result != correct;

    cout << (wrong ? "[FAIL] " : "[PASS] ");
    cout << msg << to_string(input) << ":\t" << to_string(result);
    if (wrong) cout << " Expected: " << correct;
    cout << endl;
}

vector<char> to_vector(string s) {
    vector<char> v;
    copy(s.begin(), s.end(), back_inserter(v));
    return v;
}

void run_tests() {
    test(to_vector("AAABBB"), 0, 6);
    // A_A_AB_B_B
    test(to_vector("AAABBB"), 1, 10);
    // A__A__AB__B__B
    test(to_vector("AAABBB"), 2, 14);
}
