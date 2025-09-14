
#include "ulist.h"
#include <iostream>


void buildFromArray(const int* arr, int n, UList& L) { 
    
    if (n<= 0) { 
        L.head = nullptr;
        L.n = 0;
        std::cout << "Invalid array size, exiting function\n";        
        return; 
    } 

    if(!L.head) {
        // Create a head node if one does not exist 
        L.head = new Block{{0}, 0, nullptr};
    } 

    
    // Create ceil(n/B) blocks based on size of array
    int numBlocks = (n+B-1)/B;
    Block* cur = L.head;

    for(int i = 1; i < numBlocks; i++) { 

        Block* block = new Block{{0}, 0, nullptr};
        cur->next = block;
        cur = block;
    }
    cur->next = nullptr;

    
    // Populate from elements into each block made 
    cur = L.head;
    int idx = 0;
    while(idx < n) { 

        // Populates a block at a time until full 
        // or until end of array has been reached
        while (cur->cnt < B && idx < n) { 

            cur->a[cur->cnt] = arr[idx];
            cur->cnt++;
            idx++;
        }
        cur = cur->next;
    }

    L.n = n; 
}



void displayUList(const UList& L) { 

    if (L.n == 0) {
        std::cout << "List is empty, exiting function\n";
    }


    // Populate from elements into each block made 
    Block* cur = L.head;
    int idx = 0;

    while(idx < L.n) { 

        // Populates a block at a time until full 
        // or until end of array has been reached
        for (int i = 0; i < cur->cnt && idx < L.n; i++) { 
            
            if (i == 0 ) { 
                std::cout << "[ ";
            }
            
            std::cout << cur->a[i] << " ";
            idx++;
        }
        std::cout << "]\n";
        cur = cur->next;
    }
}

