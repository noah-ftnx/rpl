#include <iostream>
using namespace std;

class Base {
public: virtual void fooPub() { cout << __PRETTY_FUNCTION__  << endl;}
protected: virtual void fooPro() { cout << __PRETTY_FUNCTION__  << endl;}
private: virtual void fooPrv() { cout << __PRETTY_FUNCTION__  << endl;}
};

/**
 * Just an extra private copy of the 3 methods
 * - within CA can access Base: pub and pro
 * - outiside CA: can access Base::pub with scope
 */
class ChildA : public Base {
// make all private
// private:
void fooPub() { cout << __PRETTY_FUNCTION__  << endl;}
void fooPro() { cout << __PRETTY_FUNCTION__  << endl;}
void fooPrv() { cout << __PRETTY_FUNCTION__  << endl;}
};


/**
 * Just an extra public copy pro and prv
 * - within CA can access Base: pub and pro
 * - outside CA: can access pro, prv. Also  pub (directly w/o need for scope)
 */
class ChildB : public Base {  // DECREASING SCOPE
  // make a private or protected method public
public:
  void fooPro() override { cout << __PRETTY_FUNCTION__; Base::fooPro(); }
  void fooPrv() override { cout << __PRETTY_FUNCTION__  << endl;}
};


/**
 * Decreasing scope
 */
class ChildX : public Base {
 private: // w/o it still private (default)
  using Base::fooPub;
  using Base::fooPro;
  // using Base::fooPrv; // not even visible
};


/**
 * Increasing scope
 */
class ChildY : public Base {
public:
   // using Base::fooPrv; // not even visible. so cannot change
  using Base::fooPro; // visible, so CAN increase (in ChildX was decreased)
  using Base::fooPub; // was already public, so no need for this
};



int main () {
  // DECREASING SCOPE:
  // ChildA ca;
  // ca.fooPub(); // ERR: prv
  // ca.fooPrv(); // ERR: prv
  // ca.fooPro(); // ERR: prv
  // ca.Base::fooPub(); // OK (calling base)


  // ChildB cb;
  // cb.fooPub(); // OK (calling base)
  // cb.fooPro(); // OK: call child then base
  // cb.fooPrv(); // OK: call child

  // ChildX cx;
  // cx.fooPub(); // ERR: prv
  // cx.Base::fooPub(); // OK
  // cx.fooPro(); // ERR: prv
  // cx.fooPrv(); // ERR: prv

  ChildY cy;
  cy.fooPro();
  cy.fooPub();

  return 0;
}