#include <iostream>
#include <list>
using namespace std;

class Entry {
public:
  int key;
  int value;

  Entry(int key, int value) : key(key), value(value) {}
};

class hashMap {
private:
  list<Entry> *buckets;
  int capacity;
  int size;

  int hash(int key) {
    string keyString = to_string(key);
    size_t hash = 5381;
    for (char c : keyString) {
      hash = ((hash << 5) + hash) + c;
    }
    return hash;
  }

public:
  hashMap(int capacity, int size = 0) : capacity(capacity), size(size) {
    buckets = new list<Entry>[capacity];
  }

  int getHash(int key) { return hash(key) % capacity; }

  void insert(int key, int value) {
    int index = getHash(key);
    buckets[index].push_back(Entry(key, value));
    size++;
  }

  int get(int key) {
    int index = getHash(key);
    list<Entry> &bucket = buckets[index];
    for (Entry entry : bucket) {
      if (entry.key == key) {
        return entry.value;
      }
    }
    return -1;
  }

  void remove(int key) {
    int index = getHash(key);
    list<Entry> &bucket = buckets[index];
    for (auto it = bucket.begin(); it != bucket.end(); ++it) {
      if (it->key == key) {
        bucket.erase(it);
        size--;
        return;
      }
    }
  }
};
