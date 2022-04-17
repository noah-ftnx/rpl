#ifndef RPL_DCP_TEST_024_H_
#define RPL_DCP_TEST_024_H_

#include <iostream>
using namespace std;

bool _wrong = false;
void check(string msg, bool res, bool correct, string postmsg="") {
  bool wrong = res != correct;
  _wrong|=wrong;
  cout << msg << ": " << boolalpha  << res << " "
  << (wrong? " (WRONG)":"") << postmsg << endl;
}

void run_tests() {
  Node* root = new Node();

  Node* l = new Node();
  root->left=l;
  l->parent=root;

  Node* r = new Node();
  root->right=r;
  r->parent=root;

  Node* rl = new Node();
  r->left=rl;
  rl->parent=r;

  Node* rll = new Node();
  rl->left=rll;
  rll->parent=rl;

  Node* rr = new Node();
  r->right=rr;
  rr->parent=r;

  check("rl.lock", rl->lock(), true);
  check("rl.isLocked", rl->is_locked(), true);
  cout << endl;

  check("rll.isLocked", rll->is_locked(), false);
  check("rll.unlock", rll->unlock(), false);
  check("rll.lock", rll->lock(), false);
  check("rll.isLocked", rll->is_locked(), false);
  cout << endl;

  check("r.isLocked", r->is_locked(), false);
  check("r.unlock", r->unlock(), false);
  check("r.lock", r->lock(), false);
  check("r.isLocked", r->is_locked(), false);
  cout << endl;

  check("root.unlock", root->unlock(), false);
  cout << endl;

  check("rl.unlock", rl->unlock(), true);
  cout << endl;


  check("r.isLocked", r->is_locked(), false);
  check("r.unlock", r->unlock(), false);


  check("r.lock", r->lock(), true);
  check("r.isLocked", r->is_locked(), true);

  check("l.lock", l->lock(), true, "\t\t(tricky case. must be able to lock)");
  check("root.lock", root->lock(), false);
  check("r.isLocked", r->is_locked(), true);

  cout << "\n" << (_wrong? "WRONG RESULTS.": "Correct.") << endl;
}


#endif  // RPL_DCP_TEST_024_H_