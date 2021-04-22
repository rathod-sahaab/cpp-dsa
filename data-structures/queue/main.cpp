#include "queue.hpp"
#include <cassert>
#include <iostream>
#include <vector>

int main(int argc, char *argv[]) {

  ArrayQueue<int> q(100);

  q.push(1);
  q.push(3);
  q.push(2);
  q.pop();
  q.push(4);
  q.pop();

  std::vector<int> result, expected{2, 4};
  while (not q.empty()) {
    std::cout << q.front() << ", ";

    result.push_back(q.front());
    q.pop();
  }
  std::cout << std::endl;

  assert(result == expected);

  return 0;
}
