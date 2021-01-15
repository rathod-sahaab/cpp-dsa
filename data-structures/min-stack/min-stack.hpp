#ifndef MINSTACK_HPP
#define MINSTACK_HPP
#include <bits/stdc++.h>

// MinStack --------------------------------------------------------------------
template <typename T> class MinStack {
  std::stack<std::pair<T, T>> _stack;

public:
  void push(T val) {
    T min = val;
    if (not _stack.empty() and _stack.top().second < val) {
      min = val;
    }
    _stack.push({val, min});
  }
  void pop() { _stack.pop(); }
  T top() { return _stack.top().first; }
  bool empty() { return _stack.empty(); }

  T min() { return _stack.top().second; }
};

// TESTS -----------------------------------------------------------------------
// If parameter is not true, test fails
// This check function would be provided by the test framework
#define TEST(x)                                                                \
  {                                                                            \
    std::string status = x ? "passed" : "failed";                              \
    std::cout << "Test in " << __FUNCTION__ << "() " << status << " on line "  \
              << __LINE__ << std::endl;                                        \
  }

namespace MinStackTest {
void minstack_test() {
  MinStack<int> ms;
  ms.push(5);
  ms.push(3);
  ms.push(2);
  ms.push(4);
  ms.push(1);

  TEST((ms.min() == 1));
  ms.pop();
  ms.pop();
  TEST((ms.min() == 2));
  TEST((ms.min() != 3));
}
} // namespace MinStack

#endif // MINSTACK_HPP
