#ifndef HASH_SET_HPP
#define HASH_SET_HPP

#include <algorithm>
#include <cstdio>
#include <iostream>
#include <iterator>
#include <utility>
#include <vector>

class HashSet {
public:
  // constructors, asssignment, destructor
  HashSet(int size);
  void insert(int x);
  bool find(int x);
  void remove(int x);

  void display();

private: // functions
  /*
   * @param x number to hash
   * @return hash of the number
   */
  int hash(int x) { return x * x % data.size(); }

private:
  int capacity;
  std::vector<std::vector<int>> data;
};

HashSet::HashSet(int size) : data(size) {}

void HashSet::insert(int x) {
  int index = hash(x);

  std::vector<int> &chain = data[index];
  if (std::find(chain.begin(), chain.end(), x) == chain.end()) {
    chain.push_back(x);
  }
}

void HashSet::remove(int x) {
  int index = hash(x);
  std::vector<int> &chain = data[index];
  chain.erase(std::remove(chain.begin(), chain.end(), x));
}

bool HashSet::find(int x) {
  int index = hash(x);
  const std::vector<int> &chain = data[index];
  return std::find(chain.begin(), chain.end(), x) != chain.end();
}

void HashSet::display() {
  int i = 0;
  for (const auto &chain : data) {
    std::cout << i++ << '\t';
    copy(std::begin(chain), std::end(chain),
         std::ostream_iterator<decltype(chain[0])>{std::cout, " "});
    std::cout << "\n";
    std::cout << "\n";
  }
}

#endif // HASH_SET_HPP
