#include <iostream>
using namespace std;

class Base {
public: int a=1;
 void prt() {
   cout << "Base: abc: " << a << ", " << b << ", " << c << endl;
 }
protected: int b=1;
private: int c=1;
};

class ChildD: public Base {
public:
   void prt() {
   cout << "Base: abc: " << a << ", " << b << ", " << c << endl;
 }
  int a=4;
  int b=4;
  int c=4;
};


int main () {

  ChildD cd;
  cd.prt();
  cd.Base::prt();


  return 0;
}