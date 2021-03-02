#include "quick-sort.hpp"
#include <vector>

int main() {
  std::vector<int> arr = {5, 8, 9, 6, 6, 2, 3, 1};
  std::vector<int> arr_dec = {5, 8, 9, 6, 6, 2, 3, 1};
  quicksort(arr, 0, arr.size() - 1);
  quicksort<int, std::greater<int>>(arr_dec, 0, arr_dec.size() - 1);

  copy(std::begin(arr), std::end(arr),
       std::ostream_iterator<decltype(arr[0])>{std::cout, " "});
  std::cout << std::endl;

  copy(std::begin(arr_dec), std::end(arr_dec),
       std::ostream_iterator<decltype(arr_dec[0])>{std::cout, " "});
  std::cout << "\n";
  return 0;
}
