
#include "ulist.h"
#include <iostream>

// insertAt could probably be refactored for right shifts


void buildFromArray(const int *arr, int n, UList &L)
{

    if (n <= 0)
    {
        L.head = nullptr;
        L.n = 0;
        std::cout << "Invalid array size, exiting function\n";
        return;
    }

    if (!L.head)
    {
        // Create a head node if one does not exist
        L.head = new Block{{0}, 0, nullptr};
    }

    // Create ceil(n/B) blocks based on size of array
    int numBlocks = (n + B - 1) / B;
    Block *cur = L.head;

    for (int i = 1; i < numBlocks; i++)
    {

        Block *block = new Block{{0}, 0, nullptr};
        cur->next = block;
        cur = block;
    }
    cur->next = nullptr;

    // Populate from elements into each block made
    cur = L.head;
    int idx = 0;
    while (idx < n)
    {

        // Populates a block at a time until full
        // or until end of array has been reached
        while (cur->cnt < B && idx < n)
        {

            cur->a[cur->cnt] = arr[idx];
            cur->cnt++;
            idx++;
        }
        cur = cur->next;
    }

    L.n = n;
}

void displayUList(const UList &L)
{

    if (L.n == 0)
    {
        std::cout << "List is empty, exiting function\n";
    }

    // Populate from elements into each block made
    Block *cur = L.head;
    int idx = 0;

    while (idx < L.n)
    {

        // Populates a block at a time until full
        // or until end of array has been reached
        for (int i = 0; i < cur->cnt && idx < L.n; i++)
        {

            if (i == 0)
            {
                std::cout << "[ ";
            }

            std::cout << cur->a[i] << " ";
            idx++;
        }
        std::cout << "]\n";
        cur = cur->next;
    }
}

int getAt(const UList &L, int idx)
{

    int result = -1;

    if (idx < 0 || idx >= L.n)
    {
        std::cout << "ERROR: Invalid index specified\n";
        return result;
    }

    int localOffset = -1;

    Block *cur = findBlock(L, idx, localOffset);

    result = cur->a[localOffset];
    return result;
}


void insertAt(UList &L, int idx, int x)
{

    if (idx < 0 || idx >= L.n)
    {
        std::cout << "ERROR: Invalid index specified\n";
        return;
    }

    int localOffset = -1;
    Block *cur = findBlock(L, idx, localOffset);

    // If the block is full
    if (cur->cnt == B)
    {

        int split = B / 2;
        Block *block = new Block{}; // Create new block

        // Copy upperhalf elements in [B/2+1...B-1]
        for (int i = split, j = 0; i < cur->cnt; i++, j++)
        {
            block->a[j] = cur->a[i];
            block->cnt++;
        }

        // Assume we can discard by data we just copied by moving pointer
        // As this will get overwritten anyways. Half count of current block in 2
        // to reflect this split
        cur->cnt /= 2;

        if (localOffset > split)
        {                         // Place in new block
            localOffset -= split; // Index relative to new block

            // Shift all elements right of insertion point
            for (int i = cur->cnt - 1; i >= localOffset; i--)
            {
                block->a[i + 1] = block->a[i];
            }
            // Now insert data
            block->a[localOffset] = x;
            block->cnt++;
            
        }
        else
        { // Insert in current block

            // Shift all elements right of insertion point
            for (int i = cur->cnt - 1; i >= localOffset; i--)
            {
                cur->a[i + 1] = cur->a[i];
            }
            // Now insert data
            cur->a[localOffset] = x;
            cur->cnt++;
             
        }

        // Update next pointers
        block->next = cur->next;
        cur->next = block;
    }
    else
    { // Happy path, just insert the element at localOffset

        // If an element exists at point of insertion we need to shift all elements right of it 
        if(localOffset < cur->cnt) { 
            // Shift all elements right of insertion point
            for (int i = cur->cnt - 1; i >= localOffset; i--)
            {
                cur->a[i + 1] = cur->a[i];
            }
            cur->a[localOffset] = x;
        }
        else { 
            cur->a[localOffset] = x;
        }
        cur->cnt++;
    }
    
    
    L.n++;
}


void eraseAt(UList& L, int idx) { 

    if (idx < 0 || idx >= L.n)
    {
        std::cout << "ERROR: Invalid index specified\n";
        return;
        
    }


}


// Helper: find block containing index idx, return pointer and local offset
Block *findBlock(const UList &L, int idx, int &off)
{

    int blockIdx = idx / B; // Index of Block element at idx is located
    Block *cur = L.head;

    for (int i = 0; i < blockIdx; i++)
    {
        cur = cur->next;
    }

    off = idx % B;
    return cur;
}

