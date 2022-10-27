#include <iostream>
using namespace std;

class Person {
public:
  void foo() { cout << "Person.foo\n"; }
  virtual void bar() { cout << "Person.bar\n"; }
};

class Student : public Person {
public:
  void foo() { cout << "Student.foo\n"; }
  void bar() override { cout << "Student.bar\n"; }
};

void demo () {
  Person *p = new Student();
  p->foo();
  p->bar();

  Student *s = static_cast<Student*>(p);
  s->foo();
  s->bar();

  s->Person::bar();
}

int main () {
  demo();
  return 0;
}