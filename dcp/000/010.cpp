
// method to call
void add(int a, int b) {
  cout << a << " + " << b << " = " << (a+b) << endl;
}

// c:way1 void*
void schedule_way1(void* func, uint64_t ms);

// c:way2 fptr
void schedule_way2(.., uint64_t ms);

// c++:way1: std::function
void schedule_way3(.., uint64_t ms);

// c++:way2
void schedule_way4(.., uint64_t ms);

int main() {
  schedule_way1((void*)add, 500);
  schedule_way2(add, 500);
  schedule_way3(add, 500);
  schedule_way4(add, 500);
}
