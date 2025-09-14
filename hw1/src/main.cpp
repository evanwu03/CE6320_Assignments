/* 

CE6320 HW1 
By Evan Wu
*/

// CPP libraries
#include <iostream>

// User-defined files 
#include "singly_circular_ll.h"
#include "ulist.h"  
#include "assert.h"

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

    UList L = UList();

    buildFromArray(arr, SIZE, L);
    displayUList(L);
    
    assert(L.n == SIZE);

    return 0;
}