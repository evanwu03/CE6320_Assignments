
#ifndef LRU_H
#define LRU_H


struct CacheNode { 
    int key,val;
    CacheNode *prev, *next;
    CacheNode(int k, int v) : key(k), val(v), prev(nullptr), next(nullptr) { };
};

struct LRU { 
    int cap;
    int size;
    int K;
    CacheNode** dir;
    CacheNode* head;
    CacheNode* tail; 
    LRU(): cap(0),size(0), K(0), dir(nullptr), head(nullptr), tail(nullptr) {};
};

// Initialize the cache with capacity Ccap and key range K.
// Allocate dir on the heap and set all entries to nullptr.
void initLRU(LRU &C, const int Ccap, const int K);

// Return true and set outVal if present (and move node to MRU); else return false.
bool get(LRU &C, int key, int &outVal);


// Insert or update (key, val). If inserting and size==cap, evict LRU.
// Move the (possibly new) key to MRU position.
void put(LRU &C, const int key, const int val);



// (Helpers students should implement/and may call from get/put)
// Remove node u from list in O(1)
void detach(LRU &C, CacheNode *u);

// Insert node u at head (MRU) in O(1)
void pushFront(LRU &C, CacheNode *u);

// Evict the LRU (tail) node in O(1); update dir and size; delete the node.
void evictLRU(LRU &C);

void displayLRU(const LRU& C);

#endif // LRU_H