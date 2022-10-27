#include <iostream>
using namespace std;

struct Base {
  void Foo() {
    cout << __PRETTY_FUNCTION__ << endl;
  }
};

class Child : public Base {
  void Foo() {
    cout << __PRETTY_FUNCTION__ << endl;
  }
};


int main() {
  Child c;
  // c.Foo(); // ERR: priv
  c.Base::Foo(); // OK: scope operator
  Base *b=&c;
  b->Foo(); // OK: through downcasting

}