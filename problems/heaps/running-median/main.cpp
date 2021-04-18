#include <bits/stdc++.h>
#include <cassert>
#include <functional>
#include <vector>
using namespace std;

class RunningMedian {
  priority_queue<int, vector<int>, greater<int>> greaters_median;
  priority_queue<int> smallers_median;

public:
  void insert(const int number);
  float get_median();
};

void RunningMedian::insert(const int number) {
  // |------ max_heap -------| median |-------- min_heap -----------|
  if (smallers_median.size() == greaters_median.size()) {
    if (smallers_median.empty()) {
      smallers_median.push(number);
      return;
    }
    if (number < smallers_median.top()) {
      smallers_median.push(number);
      return;
    } else {
      greaters_median.push(number);
      return;
    }
    return;
  } else if (smallers_median.size() > greaters_median.size()) {
    if (number < smallers_median.top()) {
      // number is more worthy of being in the lower half aka
      // smallers_median

      // exchange tops
      const auto temp = smallers_median.top();
      smallers_median.pop();
      greaters_median.push(temp);

      smallers_median.push(number);
      return;
    } else {
      greaters_median.push(number);
      return;
    }
  } else {
    if (number > greaters_median.top()) {
      // number is more worthy of being in the upper half aka
      // greaters_median

      // exchange.top()
      const auto temp = greaters_median.top();
      greaters_median.pop();
      smallers_median.push(temp);

      greaters_median.push(number);
      return;
    } else {
      smallers_median.push(number);
      return;
    }
  }
}

float RunningMedian::get_median() {
  if (smallers_median.size() == greaters_median.size()) {
    return static_cast<float>((smallers_median.top() + greaters_median.top())) /
           2;
  }
  if (smallers_median.size() > greaters_median.size()) {
    return static_cast<float>(smallers_median.top());
  }
  return static_cast<float>(greaters_median.top());
}

int main(int argc, char *argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  RunningMedian rm;

  vector<int> numbers{3, 4, 6, 1, 5, 8, 9, 19, 21, 12, 40, 18, 90};
  vector<float> expected{
      3, 3.5, 4, 3.5, 4, 4.5, 5, 5.5, 6, 7, 8, 8.5, 9,
  };

  vector<float> result;

  for (const auto &number : numbers) {
    rm.insert(number);
    result.push_back(rm.get_median());
  }

  copy(std::begin(result), std::end(result),
       std::ostream_iterator<decltype(result[0])>{std::cout, ", "});
  std::cout << "\n";

  assert(result == expected);
  return 0;
}
