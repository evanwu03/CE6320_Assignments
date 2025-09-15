
#include "LRU.h"
#include <iostream>


void initLRU(LRU &C, const int Ccap, const int K) { 
    C.dir = new CacheNode*[K];
    C.cap = Ccap;
    C.K = K;

    for(int i = 0; i < C.K; i++) {
        C.dir[i] = nullptr;
    }
}


bool get(LRU &C, int key, int &outVal) {

    if(key < 0 || key >= C.K) { 
        std::cout << "ERROR: Invalid Array Index Specified\n";
        return false;
    }

    CacheNode* found = C.dir[key];

    if(found) { 
        outVal = found->val;

        // Move found node to the head and update pointers
        detach(C, found);
        pushFront(C, found);
        return true; 
    }


    // Return false otherwise
    return false;

}

void put(LRU &C, const int key, const int val) { 

    if (key < 0 || key >= C.K) {
        std::cout << "Invalid Key Specified\n";
        return; 
    }


    // If the list is empty insert at head
    // and update head and tail
    if(C.size == 0) { 
        CacheNode* node = new CacheNode(key,val);
        C.head = C.tail = node;
        C.head->next = C.tail;
        C.tail->prev = C.head;

        C.dir[key] = node;
        C.size++;
        return;
    }

    // If key,value pair already exists 
    // push node to front and update value
    CacheNode* found = C.dir[key];
    if(found) { 
        
        detach(C, found);
        pushFront(C, found);
        found->val = val;
        return;
    }

    // Node was not found but need
    // to check if LRU is full
    // Evict LRU if cache is full
    if (C.size == C.cap) { 
        evictLRU(C);
    }

    CacheNode* node = new CacheNode(key, val);
    pushFront(C, node);
    C.dir[key] = node;
    C.size++;
}


void detach(LRU &C, CacheNode *u) { 

    // Do nothing if node is the head
    if (C.head == u) return; 

    // Detach tail and make previous node the tail
    if (C.tail == u) { 

        C.tail = u->prev;
        if(C.tail) C.tail->next = nullptr;
        return;
    }

    // If found somewhere in middle we need to update pointers 
    // between previous and next


    if (u->prev) u->prev->next = u->next;
    if (u->next) u->next->prev = u->prev;

    u->prev = u->next = nullptr;
}

void pushFront(LRU &C, CacheNode *u) {
    
    if (C.head == u) return;

    u->next           = C.head;
    C.head->prev      = u;
    C.head            = u;
}

void evictLRU(LRU &C) { 

 
    // Unregister tail from dir 
    C.dir[C.tail->key] = nullptr;

    // Temporarily store current tail to be deleted
    CacheNode* temp = C.tail;

    // Move tail pointer back

    C.tail = C.tail->prev;
    if (C.tail) {
        C.tail->next = nullptr; // fix dangling pointer
    } else {
        // List is now empty
        C.head = nullptr;
    }

    delete temp;

    C.size--;

}


void displayLRU(const LRU& C) {

    CacheNode* cur = C.head;
    for(int i= 0; i < C.size; i++) { 
        
        if(cur) { 
            std::cout << cur->val << " ";
            cur = cur->next;
        }
    }
    std::cout << "\n";
}