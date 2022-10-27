
class Foo {
  int xx;
  Foo(int x) {
    xx=x;
  }
};

void demo() {

  // LEFTHERE... TEST w/ explicit..
  auto f1 = new Foo(10);
  auto f2= new Foo(10.5f);

}


int main () {
  demo();
  return 0;
}
