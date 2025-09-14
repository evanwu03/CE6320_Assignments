
#ifndef ULIST_H 
#define ULIST_H 

#define B 4 // Max number of elements per block

struct Block { 

    int a[B];       // items packed in a[0..cnt-1]
    int cnt;        // number of valid items in this block
    Block* next;    // pointer to next block
};


struct UList { 
    Block* head; // head block (nullptr if empty)
    int n;       // total number of itmes 
                      
    UList() : head(nullptr), n(0) {};
};


// Build list from arr[0..n-1], filling blocks left-to-right. 
void buildFromArray(const int* arr, int n, UList& L); 

// Display the contents of the entire list
void displayUList(const UList& L);

// Return the value at global index idx
int getAt(const UList& L, int idx);


#endif // ULIST_H