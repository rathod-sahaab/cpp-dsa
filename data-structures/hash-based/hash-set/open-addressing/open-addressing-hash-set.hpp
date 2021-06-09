#ifndef HASH_SET_HPP
#define HASH_SET_HPP

#include <iostream>
#include <utility>
#include <vector>

enum class CellState { OCCUPIED, EMPTY, DELETED };
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
  /*
   * @param i previous index
   * @return next index to search
   */
  int linear_probing(int index) {
    index++; // linear probing
    if (index >= data.size()) {
      index %= data.size();
    }
    return index;
  }

private:
  int capacity;
  std::vector<std::pair<CellState, int>> data;
};

HashSet::HashSet(int size) : data(size, {CellState::EMPTY, -1}) {}

void HashSet::insert(int x) {
  const int SIZE = data.size();

  int index = hash(x);
  while (data[index].first == CellState::OCCUPIED) {
    if (data[index].second == x) {
      // already exists
      return;
    }
    index = linear_probing(index);
  }
  data[index] = {CellState::OCCUPIED, x};
}

void HashSet::remove(int x) {
  int index = hash(x);
  while (data[index].first == CellState::OCCUPIED) {
    if (data[index].second == x) {
      data[index].first = CellState::DELETED;
    }

    index = linear_probing(index);
  }
}

bool HashSet::find(int x) {
  int index = hash(x);
  while (data[index].first == CellState::OCCUPIED) {
    if (data[index].second == x) {
      return true;
    }
    index = linear_probing(index);
  }
  return false;
}

void HashSet::display() {
  int i = 0;
  for (const auto &entry : data) {
    char status;
    switch (entry.first) {
    case CellState::OCCUPIED:
      status = 'O';
      break;
    case CellState::DELETED:
      status = 'D';
      break;
    case CellState::EMPTY:
      status = 'E';
      break;
    }
    std::cout << i++ << '\t' << status << " " << entry.second << "\n";
  }
}

#endif // HASH_SET_HPP
