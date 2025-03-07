//
// Created by Rakib Mondal on 17/08/24.
//

#include <iostream>

struct Node {
  int data;
  Node* next;

  Node() : data {}, next {nullptr} {}
};

class Queue {
  public:
  Node* head;
  Node* tail;

  Queue() : head {nullptr}, tail {nullptr} {}
  ~Queue() =default;

  void insertFront(int const data) {
    if (head == nullptr) {
      head = new Node();
      head->data = data;
      tail = head;
      return;
    }

    auto const temp = new Node();
    temp->data = data;
    temp->next = head;
    head = temp;
  }

  int deleteFront() {
    if (head == nullptr) {
      std::cout << "Empty Queue\n";
      return 0;
    }

    int const value = head->data;
    auto const temp = head;
    head = head->next;
    delete temp;

    return value;
  }

  void insertBack(int const data) {
    if (head == nullptr) {
      head = new Node();
      head->data = data;
      tail = head;
      return;
    }

    tail->next = new Node();
    tail = tail->next;
    tail->data = data;
  }

  int deleteBack() {
    if (head == nullptr) {
      std::cout << "Empty Queue\n";
      return 0;
    }

    if (head == tail) {
      int const value = tail->data;
      delete tail;
      tail = nullptr;
      head = nullptr;
      return value;
    }

    auto current = head;
    for (; current->next != tail; current = current->next) {}
    int const value = tail->data;
    delete tail;
    tail = current;
    tail->next = nullptr;

    return value;
  }

  void display() const {
    if (head == nullptr) {
      std::cout << "Empty Queue\n";
      return;
    }

    for (auto current = head; current != nullptr; current = current->next) {
      std::cout << current->data << '\n';
    }
  }
};
