/*
chain hash table implemenation

created by xuyang at zju 6/30 2022

*/



#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

struct bucket {
  int value;
  struct bucket *next;
  bucket(int value): value(value), next(nullptr) {
     
  }
};

class HashTable {
 private:
  vector <struct bucket*> table;

 public:
  HashTable(size_t size) {
    table.resize(size);
    for (auto bkt: table) {
        bkt = nullptr;
    }
  }
  ~HashTable() {
    for (int i = 0; i < size(); i ++) {
        while (table[i]) {
            auto bucket_ptr = table[i];
            table[i] = table[i]->next;
            free(bucket_ptr);
        }
    }
  }

  int hash(int key) const {
    return key % table.size();
  }
  
  void insert(int key) {
    int bucket_idx = hash(key);
    auto bucket_ptr = &table[bucket_idx];
    while (true) {
        if (*bucket_ptr == nullptr) {
            *bucket_ptr = new struct bucket(key);
            return;
        }
        bucket_ptr = &(*bucket_ptr)->next;
    }
  }


  bool remove(int key) {
    int bucket_idx = hash(key);
    struct bucket * bucket_ptr = table[bucket_idx];
    struct bucket * prev = nullptr;
    while(true) {
        if (bucket_ptr == nullptr) {
            break;
        }
        if (bucket_ptr->value == key) {
            if (prev == nullptr) {
                table[bucket_idx] = bucket_ptr->next;
            } else {
                prev->next = bucket_ptr->next;
            }
            free(bucket_ptr);
            return true;
        }
        prev = bucket_ptr;
        bucket_ptr = bucket_ptr->next;
    }
    return false;
  }

  size_t size() {
    return table.size();
  }


  void printHashTable() const  {
    cout << "Print Hash Table" << endl;
    for (int i = 0; i < table.size(); i ++) {
        if (table[i] != nullptr) {
            cout << "bucket id " << i << " : ";
            auto bucket_ptr = table[i];
            while(bucket_ptr->next) {
                cout << bucket_ptr->value << " ";
                bucket_ptr = bucket_ptr->next;
            }
            cout << "\n";
        }
    }
  }
  static void test(HashTable hash_table) {
    cout << "Test begin\n";
    cout << "Hash Table size: " << hash_table.size() << endl;
    for (int i = 0; i < 20; i ++ ) {
        hash_table.insert(i);
    }

    for (int i = 428; i >= 0; i --) {
        hash_table.insert(i);
    }

    hash_table.printHashTable();

    for (int i = 0; i < 20; i ++) {
        assert(hash_table.remove(i) == true);
    }
    assert(hash_table.remove(10000) == false);


  }

};

int main() {
    HashTable hash_table(10);
    HashTable::test(hash_table);
    return 0;
}