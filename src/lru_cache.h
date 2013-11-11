class LRUCache {
private:
  int capacity;
  unordered_map<int, list<pair<int, int>>::iterator> cache;
  list<pair<int, int>> queue;

public:
  LRUCache(int capacity) :
      capacity(capacity) {
    assert(capacity > 0);
  }

  int get(int key) {
    auto iter = cache.find(key);
    if (iter != cache.end()) {
      auto iterInQueue = iter->second;
      int value = iterInQueue->second;
      queue.erase(iterInQueue);
      queue.push_front(make_pair(key, value));
      iter->second = queue.begin();
      return value;
    }
    return -1;
  }

  void set(int key, int value) {
    auto iter = cache.find(key);
    if (iter != cache.end()) {
      queue.erase(iter->second);
    } else if (capacity == cache.size()) {
      auto toBeRemoved = --queue.end();
      cache.erase(toBeRemoved->first);
      queue.erase(toBeRemoved);
    }
    queue.push_front(make_pair(key, value));
    cache[key] = queue.begin();
  }
};
