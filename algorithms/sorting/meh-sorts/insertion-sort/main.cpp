#include <bits/stdc++.h>
using namespace std;

void insertion_sort(vector<int> &numbers) {
  const int N = numbers.size();
  for (int i = 1; i < N; ++i) {
    int temp = numbers[i];
    int j;
    for (j = 0; j < i; ++j) {
      if (numbers[j] > temp) {
        break;
      }
    }
    if (j != i) {
      for (int k = i; k > j; --k) {
        numbers[k] = numbers[k - 1];
      }
      numbers[j] = temp;
    }
  }
}

void solve() {
  int N;
  cin >> N;

  vector<int> numbers(N);
  for (auto &elem : numbers) {
    cin >> elem;
  }

  insertion_sort(numbers);

  for (const auto &elem : numbers) {
    cout << elem << " ";
  }
  std::cout << "\n";
}

int main(int argc, char *argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T;
  cin >> T;
  while (T--) {
    solve();
  }

  return 0;
}
