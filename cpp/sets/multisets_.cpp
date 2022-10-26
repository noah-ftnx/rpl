#include <set>  // multiset
#include <map>  // multimap
// equivalent for unordered variants

#include "../test/base.h"

void demo_multimaps() {
    cout << "########\nDEMO: multimap\n"<< endl;
    multimap<int, string> mm;
    mm.insert({1, "nick"});
    mm.insert({1, "yoda"});
    mm.insert({3, "george"});
    mm.insert({4, "michael"});
    mm.insert({4, "john"});
    cout << "multimap:\n";
    cout << to_string(mm) << endl << endl;

    cout << "erase(1): key=1 (nick, yoda)\n";
    mm.erase(1);
    cout << to_string(mm) << endl << endl;

    cout << "erase(it): it=find(4) (iterator points to michael)\n";
    auto it = mm.find(4);
    if (it != mm.end()) {
        mm.erase(it);
    }
    cout << to_string(mm) << endl << endl;

}


void demo_multisets() {
    cout << "########\nDEMO: multiset\n"<< endl;
    multiset<int> ms;
    ms.insert(1);
    ms.insert(1);
    ms.insert(3);
    ms.insert(4);
    ms.insert(4);
    cout << "multiset:\n";
    cout << to_string(ms) << endl << endl;

    cout << "erase(1): key=1 (both: 1, 1)\n";
    ms.erase(1);
    cout << to_string(ms) << endl << endl;

    cout << "erase(it): it=find(4) (iterator points to the first 4)\n";
    auto it = ms.find(4);
    if (it != ms.end()) {
        ms.erase(it);
    }
    cout << to_string(ms) << endl << endl;
}

int main() {
    demo_multimaps();
    demo_multisets();
    return 0;
}