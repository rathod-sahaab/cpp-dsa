#include <optional>
#include <vector>
template <typename T> class BasicQueue {
public:
  virtual bool push(T val) = 0;
  virtual bool pop() = 0;
  virtual T front() const = 0;
  virtual bool empty() const = 0;
};

template <typename T> class ArrayQueue : public BasicQueue<T> {
  T *_data;
  std::size_t _buffer_size;
  int _head = -1, _tail = -1;

public:
  ArrayQueue(const size_t buffer_size) : _buffer_size{buffer_size} {
    _data = new T[buffer_size];
  }
  ~ArrayQueue() { delete[] _data; }

  bool push(T val) override {
    if (_tail == _buffer_size - 1) {
      return false; // overflow
    }
    _data[++_tail] = val;
    if (_tail == 0) {
      _head = 0;
    }
    return true;
  }

  bool pop() override {
    if (empty()) {
      return false; // under flow
    }
    _head++;
    return true;
  }

  T front() const override { return _data[_head]; }

  bool empty() const override { return _head > _tail or _head == -1; }
};
