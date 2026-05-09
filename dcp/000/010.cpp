
// method to call
void add(int a, int b);

// c:way1 void*
// IMPLEMENT: schedule_way1
void schedule_way1(void* func, uint64_t ms);

// c:way2 fptr
// IMPLEMENT: schedule_way2
void schedule_way2(.., uint64_t ms);

// c++:way1: std::function
// IMPLEMENT: schedule_way3
void schedule_way3(.., uint64_t ms);

// c++:way2
// IMPLEMENT: schedule_way4
void schedule_way4(.., uint64_t ms);



#include "test/010.h"
int main() { run_tests(); }