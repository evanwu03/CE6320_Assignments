/* 

CE6320 HW1 
By Evan Wu
*/

// CPP libraries
#include <iostream>
#include "assert.h"

// User-defined files 
#include "singly_circular_ll.h"
#include "ulist.h" 
#include  "LRU.h"

static const int NUM_NODES = 5;

int main()
{

    // Problem 1 Test -> move This to a test file 
    /*
    int size = 0; 
    
    Node* cur = nullptr; 
    Node* head = buildCircle(NUM_NODES, cur, size);
    
    cur = head;

    nextK(cur, size, 2);
    delCurrent(cur, size);
    nextK(cur, size, 3);
    delCurrent(cur, size);
    nextK(cur, size, 1);

    printOnce(cur);
    deleteCircle(head, size);
    */


    /* Problem 2: Unrolled Linked List*/
    const int SIZE = 8;
    const int arr[SIZE] = {1,2,3,4,5,6,7,8};

    // buildFromArray Tests
    /*
    UList L = UList();

    buildFromArray(arr, SIZE, L);
    displayUList(L);
    assert(L.n == SIZE);

    // Test for getAt() function
    for (int i = 0; i < L.n; i++) {
        assert(getAt(L, i) == i+1);
    }

    // Expect error messages for both
    assert(getAt(L, -1) == -1); 
    assert(getAt(L, L.n) == -1);
    */


    // Insertion Tests
    /*
    UList L2 = UList();
    buildFromArray(arr, SIZE, L2);
    insertAt(L2, 7, 80);
    insertAt(L2, 6, 100);
    insertAt(L2, 5, 999);
    displayUList(L2);
    assert(getAt(L2, 5) == 999);
    assert(getAt(L2, 9) == 80);
    */


    // Erase At tests 
    /*
    UList L3 = UList();
    buildFromArray(arr, SIZE, L3);
    eraseAt(L3, 0);  
    assert(getAt(L3, 0) == 2);

    eraseAt(L3, 0);  // [3,4] [5,6,7,8]

    assert(getAt(L3,0) == 3);
    eraseAt(L3, 1); //  [3,5] [6,7,8]
    assert(getAt(L3, 1) == 5); 

    eraseAt(L3, 2); // [3,5] [7,8] 
    eraseAt(L3, 1); // [3,7,8]
    displayUList(L3);
    assert(getAt(L3, 0) == 3);
    assert(getAt(L3, 1) == 7);
    assert(getAt(L3, 2) == 8);
    */

    // Sample Program
    /*
    UList L4 = UList();
    buildFromArray(arr, SIZE, L4);
    insertAt(L4, 2, 99); // [1,2] [99,3,4] [5,6,7,8]
    insertAt(L4, 6,77);  // [1,2] [99,3,4] [5,77,6] [7,8]
    eraseAt(L4,3);       // [1,2] [99,4]   [5,77,6] [7,8]
    insertAt(L4, 8, 55); // [1,2] [99,4]   [5,77,6] [7,55,8]
    eraseAt(L4,0);       // [2,99,4] [5,77,6] [7,55,8]
    displayUList(L4);
    */


    /* Problem 3: LRU Cache Tests*/
    const int Ccap = 3;
    const int K = 10;
    LRU lru = LRU();
    initLRU(lru, Ccap, K);

    for(int i = 0; i < lru.K; i++) {
        assert(lru.dir[i] == nullptr);
    }

    int out = 0;
    put(lru, 2, 20);
    put(lru, 5, 50);
    put(lru, 7, 70);
    displayLRU(lru);
    
    assert(get(lru, 2, out));
    assert(out == 20);
    displayLRU(lru);

    put(lru, 9, 90);
    displayLRU(lru);

    
    assert(!get(lru, 5, out));
    
    put(lru, 2, 21);
    displayLRU(lru);

    
    assert(get(lru, 2, out));
    assert(out == 21);
    displayLRU(lru);
    
    assert(get(lru, 7, out));
    displayLRU(lru);

    return 0;
}