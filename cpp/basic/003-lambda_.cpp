#include <iostream>
using namespace std;

void test() {

    // creates and inits var in lambda
    auto foo = [var1 = 10, var2 = 2]() {
        cout << var1 << " " << var2;
    };

    foo();
}

int main () {
    test();
    return 0;
}
