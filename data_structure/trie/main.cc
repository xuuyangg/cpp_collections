#include <iostream>
#include <memory>
#include <cstring>
#include <string>
#include <vector>
#include <cassert>

#define SIZE 26

using namespace std;

struct TrieNode {
  struct TrieNode *children[SIZE];
  bool isEnd;
  TrieNode() {
    memset(children, 0, 26);
    isEnd = false;
  }
};

class Dictionary {
 private:
  TrieNode *head;

 public:
  Dictionary() { head = new TrieNode(); }

  void BuildDictioinary(vector<string> &v) {
    for (auto &str : v) {
      struct TrieNode *node_ptr = head;
      for (auto &ch : str) {
        if (!node_ptr->children[ch - 'a']) {
          node_ptr->children[ch - 'a'] = new TrieNode();
        }
        node_ptr = node_ptr->children[ch - 'a'];
      }
      node_ptr->isEnd = true;
    }
  }

  bool Find(string str) { 
    struct TrieNode *node_ptr = head;
    for (auto ch: str) {
      if (node_ptr->children[ch - 'a'] == nullptr) {
        return false;
      }
      node_ptr = node_ptr->children[ch - 'a'];
    }

    return node_ptr->isEnd;
  }
};

void Test() {
  Dictionary dict;
  vector<string> v{"sheep", "cat", "dog", "fjsljflsjflsjflsjlfljslf"};

  dict.BuildDictioinary(v);
  assert(dict.Find("sheep") == true);
  assert(dict.Find("cat") == true);
  assert(dict.Find("dog") == true);
  assert(dict.Find("do11") == false);
  assert(dict.Find("fjsljflsjflsjflsjlfljslf") == true);
}

int main() {
  Test();
  return 0;
}