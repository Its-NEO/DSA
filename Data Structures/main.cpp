#include <iostream>

class Queue {
  public:
  int data[];
  int head;
  int tail;
  const int SIZE;

  explicit Queue(int const SIZE) : data {SIZE}, head {-1}, tail {-1}, SIZE {SIZE} {}
  ~Queue()=default;

  [[nodiscard]] bool is_empty() const { return head == -1; }
  [[nodiscard]] bool is_full() const { return tail == SIZE - 1; }
  void insertFront(int value) {
    if (is_full()) {
      std::cout << "The queue is full!\n";
      return;
    }

    for (int i = 0; i < SIZE; i++) {
      if (head <= i && i <= tail)
        std::cout << data[i] << ", ";
      else
        std::cout << "-";
    }

    int prev = data[head];
    for(int i = head + 1; i <= tail + 1; i++) {
      int const temp = data[i];
      data[i] = prev;
      prev = temp;
    }

    for (int i = 0; i < SIZE; i++) {
      if (head <= i && i <= tail)
        std::cout << data[i] << ", ";
      else
        std::cout << "-";
    }
  }
};

int main() {

}
