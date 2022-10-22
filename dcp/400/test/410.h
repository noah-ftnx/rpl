#include "base.h"

void test(vector<float> input, vector<int> correct) {
    auto result = solve(input);
    check_result(input, result, correct);
}

void run_tests() {
    test({1.0, 2.0, 2.0}, {1, 2, 2});
    test({1.9, 2.9, 2.9}, {2, 3, 3});

    // rounded: 12.6=13
    // flooredSum: 11, we need 2 ceils: pick 5.7 and 3.4
    test({1.2, 3.4, 2.3, 5.7}, {1, 4, 2, 6});
}