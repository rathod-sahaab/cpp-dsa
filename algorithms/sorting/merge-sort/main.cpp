#include "merge-sort.hpp"

int main() {
  std::vector<int> arr = {5, 9, 6, 6, 2, 3, 4, 1};
  std::vector<int> arr_dec = {5, 9, 6, 6, 2, 3, 4, 1};
  merge_sort<int, std::greater<int>>(arr_dec, 0, arr_dec.size() - 1);
  merge_sort(arr, 0, arr.size() - 1);

  copy(std::begin(arr), std::end(arr),
       std::ostream_iterator<decltype(arr[0])>{std::cout, " "});
  std::cout << std::endl;
  copy(std::begin(arr_dec), std::end(arr_dec),
       std::ostream_iterator<decltype(arr_dec[0])>{std::cout, " "});
  std::cout << "\n";

  return 0;
}
