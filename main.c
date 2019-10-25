//
//  main.c
//  Assignment 4
//
//  Created by Ben Tilden on 2018-11-04.
//  Copyright © 2018 Ben Tilden. All rights reserved.
//

#include <stdio.h>
#include "bst.h"

int main(void) {
    BStree bst;
    int size;
    int key_id;
    int data;
    char string[256];
    printf("Enter in binary search tree size: ");
    scanf("%d", &size);
    bst = bstree_ini(size);
    while ((scanf("%s %d %d", string, &key_id, &data)) == 3) {
        bstree_insert(bst, key_construct(string, key_id), data);
    }
    bstree_traversal(bst);
    bstree_free(bst);
    
}
