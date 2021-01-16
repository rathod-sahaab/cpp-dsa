#ifndef MINQUEUE_HPP
#define MINQUEUE_HPP
#include <algorithm>
#include <bits/stdc++.h>

template <typename T> class MinHeadQueue {
public:
  void push_back(T val) {
    while (!_min_queue.empty() and _min_queue.back() > val) {
      _min_queue.pop_back();
    }
    _min_queue.push_back(val);
    _normal_queue.push_back(val);
  }

  void pop_front() {
    if (not _normal_queue.empty()) {
      pop_front(_normal_queue.front());
    }
  }
  // Drawback, you have to know which element to remove, suplement with normal
  // queue for full functionality
  void pop_front(T element_to_remove) {
    if (not _min_queue.empty() and _min_queue.front() == element_to_remove) {
      _min_queue.pop_front();
    }
    _normal_queue.pop_front();
  }

  T min() { return _min_queue.front(); }

  T front() { return _normal_queue.front(); }

  bool empty() { return _normal_queue.empty(); }

private:
  std::deque<T> _min_queue, _normal_queue;
};

template <typename T> class MinCountedQueue {
public:
  void push_back(T val) {
    while (!_min_queue.empty() and _min_queue.back().first > val) {
      _min_queue.pop_back();
    }
    _min_queue.push_back({val, _n_added});
    _n_added++; // seperate for clearity
  }

  void pop_front() {
    if (not _min_queue.empty() and _min_queue.front().second == _n_removed) {
      _min_queue.pop_front();
    }
    _n_removed++;
  }
  T min() { return _min_queue.front().first; }

  bool empty() { return _min_queue.empty(); }

private:
  std::deque<std::pair<T, std::size_t>> _min_queue;
  std::size_t _n_added = 0, _n_removed = 0;
};

template <typename T> class DoubleStackMinQueue {
public:
  void push_back(T val) {
    T min = s1.empty() ? val : std::min(val, s1.top().second);
    s1.push({val, min});
  }

  void pop_front() {
    if (s2.empty()) {
      while (not s1.empty()) {
        T element_to_push = s1.top().first;
        s1.pop();
        T min = s2.empty() ? element_to_push
                           : std::min(s2.top().second, element_to_push);
        s2.push({element_to_push, min});
      }
    }
    s2.pop();
  }

  T min() {
    if (s1.empty() or s2.empty()) {
      return s1.empty() ? s2.top().second : s1.top().second;
    } else {
      return std::min(s1.top().second, s2.top().second);
    }
  }

private:
  std::stack<std::pair<T, T>> s1, s2;
  std::size_t _n_added = 0, _n_removed = 0;
};

#endif // MINQUEUE_HPP
