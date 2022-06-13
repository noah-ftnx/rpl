#include <stack>
using namespace std;

class StockSpanner {
 public:
  struct Item { int value{-1}, span{}; };
  stack<Item> st;
  StockSpanner() { }

  int next(int price) {
    int span=1;
    while(!st.empty() && st.top().value <= price) {
      span+=st.top().span;
      st.pop();
    }

    st.push({price, span});

    return span;
  }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */