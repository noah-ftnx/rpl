#ifndef RPL_DCP_TEST_017_H_
#define RPL_DCP_TEST_017_H_

#include <iostream>
#include <iomanip>

bool _wrong;
int _test_num=0;
void test (string path, int correct) {

 cout << "Input" << to_string(++_test_num) << ": "
     << "\n----------------------------------------------\n"
     << path
     << "\n----------------------------------------------\n";

  int res = longest_path(path);
  bool wrong = (res != correct);
  _wrong|=wrong;
  cout << "longest path: " << res << (wrong? " (WRONG)":"") << endl << endl;
}

void run_tests() {
  test("", 0);
  test("dir\n\tsubdir1\n\tsubdir2\n\t\tfile.ext", 20);
  test("dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext", 32);
  test("dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tanotherfolder", 21);
  test("dir\n\tsubdir1\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tanotherfolder", 0);
  test("file.txt", 8); // TRICKY

  if (_wrong) cout << "\n\nERRORS FOUND.\n";
}

#endif  // RPL_DCP_TEST_017_H_
