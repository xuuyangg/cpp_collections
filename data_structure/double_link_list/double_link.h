/*
double link list implementation
created by xuyang in zju
*/
#ifndef DOUBLE_LINK__
#define DOUBLE_LINK__
// #define NDEBUG

#include <vector>
#include <iostream>
#include <cassert>
#include <unordered_map>

template <typename T>
struct Node {
  T value;
  typename std::vector<Node<T>>::iterator prev;
  typename std::vector<Node<T>>::iterator next;
};

template <typename T>
class DoubleLinkList {
 public:
  DoubleLinkList(int);
  bool Push(T);
  bool Erase(T);
  void setValue(int, T);                            // for test
  int size();                                       // for test
  typename std::vector<Node<T>>::iterator begin();  // for test
  typename std::vector<Node<T>>::iterator end();    // for test
  static void Test(DoubleLinkList<T>&);

 private:
  std::unordered_map < int,
      typename std::vector<Node<T>>::iterator > hash_table;
  typename std::vector<Node<T>> nodes_;
  typename std::vector<Node<T>>::iterator free_;
  typename std::vector<Node<T>>::iterator head_;
};

template <typename T>
bool DoubleLinkList<T>::Push(T value) {
  if (hash_table.find(value) != hash_table.end()) {
    return true;
  }

  if (free_ == nodes_.end()) { // full
    return false;
  }

  auto node = free_;
  if (free_->prev == free_ && free_->next == free_) {
    // the last free node;
    free_ = nodes_.end();
  } else {
    free_ = node->next;
    node->prev->next = node->next;
    node->next->prev = node->prev;
  }

  node->value = value;
  hash_table[value] = node;
  // insert into head;
  if (head_ == nodes_.end()) {
    head_ = node;
    head_->next = head_;
    head_->prev = head_;
  } else {
    node->next = head_;
    head_->prev->next = node;
    node->prev = head_->prev;
    head_->prev = node;
    head_ = node;
  }

  return true;
}

template <typename T>
bool DoubleLinkList<T>::Erase(T value) {
  if (hash_table.find(value) == hash_table.end()) {
    return false;
  }

  auto node = hash_table[value];
  if (head_->prev == head_ && head_->next == head_) {
    head_ = nodes_.end();
  } else {
    head_ = node->next;
    node->prev->next = node->next;
    node->next->prev = node->prev;
  }

  hash_table.erase(value);
  // insert into head;
  if (free_ == nodes_.end()) {
    free_ = move(node);
    free_->next = free_;
    free_->prev = free_;
  } else {
    node->next = free_;
    free_->prev->next = node;
    node->prev = free_->prev;
    free_->prev = node;
    free_ = node;
  }
  return true;
}

template <typename T>
typename std::vector<Node<T>>::iterator DoubleLinkList<T>::begin() {
  return nodes_.begin();
}

template <typename T>
typename std::vector<Node<T>>::iterator DoubleLinkList<T>::end() {
  return nodes_.end();
}

template <typename T>
int DoubleLinkList<T>::size() {
  return nodes_.size();
}

template <typename T>
DoubleLinkList<T>::DoubleLinkList(int size) {
  nodes_.resize(size);
  for (auto iter = nodes_.begin(); iter != nodes_.end(); iter++) {
    iter->next = (iter + 1);
    if (iter != nodes_.begin()) {
      iter->prev = (iter - 1);
    }
  }
  nodes_.begin()->prev = (nodes_.end() - 1);
  (nodes_.end() - 1)->next = nodes_.begin();
  free_ = nodes_.begin();
  head_ = nodes_.end();
}

template <typename T>
void DoubleLinkList<T>::setValue(int index, T value) {
  if (index < 0 || (size_t)index >= nodes_.size()) {
    // error index out of range
    std::cout << "error index out of range" << std::endl;
    return;
  }
  nodes_[index].value = value;
}

template <typename T>
void DoubleLinkList<T>::Test(DoubleLinkList<T>& slist_) {
  std::cout << "Test 1:  Fill the list with some value" << std::endl;
  for (int i = 0; i < slist_.size(); i++) {
    slist_.setValue(i, i);
  }
  std::cout << "Test 1 Done" << std::endl;

  std::cout << "Test 2  Forward check value twice" << std::endl;
  auto iter = slist_.begin();
  int total_elements = slist_.size();
  for (int start = 0; start < total_elements * 2; start++) {
    if (start == 0) {
      std::cout << "Round 1" << std::endl;
    } else if (start == total_elements) {
      std::cout << std::endl;
      std::cout << "Round 2" << std::endl;
    }
    std::cout << iter->value << " ";
    iter = iter->next;
  }
  std::cout << std::endl;
  std::cout << "Test 2 Done" << std::endl;

  std::cout << "Test 3  Backward check value twice" << std::endl;
  iter = slist_.end() - 1;
  for (int start = 0; start < total_elements * 2; start++) {
    if (start == 0) {
      std::cout << "Round 1" << std::endl;
    } else if (start == total_elements) {
      std::cout << std::endl;
      std::cout << "Round 2" << std::endl;
    }
    std::cout << iter->value << " ";
    iter = iter->prev;
  }
  std::cout << std::endl;
  std::cout << "Test 3 Done" << std::endl;

  std::cout << std::endl;
  std::cout << std::endl;

  std::cout << "Test 4 Inserting test" << std::endl;
  std::cout << "size of slist is " << slist_.size() << std::endl;

  for (int i = 0; i < slist_.size(); i ++) {
    assert(slist_.Push(i) == true);
  }

  for (int i = 0; i < slist_.size(); i ++) {
    assert(slist_.Erase(i) == true);
  }

  for (int i = 0; i < slist_.size(); i ++) {
    assert(slist_.Erase(i) == false);
  }
}

#endif