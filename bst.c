//
//  bst.c
//  Assignment 4
//
//  Created by Ben Tilden on 2018-11-04.
//  Copyright © 2018 Ben Tilden. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bst.h"

// Input: ’size’: size of an array
// Output: a pointer of type BStree,
// i.e. a pointer to an allocated memory of BStree_struct type
// Effect: dynamically allocate memory of type BStree_struct
// allocate memory for a Node array of size+1 for member tree_nodes
// allocate memory for an unsigned char array of size+1 for member is_free
// set all entries of is_free to 1
// set member size to ’size’;

BStree bstree_ini(int size) {
    BStree_struct *bstree = (BStree_struct *) malloc(sizeof(BStree_struct));
    BStree tree = bstree;
    tree->tree_nodes = (Node *) malloc((size + 1)*sizeof(Node*));
    tree->is_free = (unsigned char *) malloc((size + 1)*sizeof(unsigned char*));
    for(int i=0; i < size + 1; i++){
        tree->is_free[i] = '1';
    }
    tree->size = size;
    return tree;
}

// Input: ’bst’: a binary search tree
// ’key’: a pointer to Key
// ’data’: an integer
// 'position': an interger
// Effect: ’data’ with ’key’ is inserted into ’bst’ recursively
// if ’key’ is already in ’bst’, do nothing

void bstree_insert_node_recursively(BStree bst, Key *key, int data, int position){
    if(bst->is_free[position] == '1'){
        Node newNode;
        newNode.key = key;
        newNode.data = data;
        bst->tree_nodes[position] = newNode;
        bst->is_free[position] = '0';
        return;
    }
    else if(key_comp(*key, *bst->tree_nodes[position].key) < 0){
        position = 2 * position;
        if(position > bst->size){
            printf("Array out of bounds error\n");
            exit(1);
        }
        bstree_insert_node_recursively(bst, key, data, position);
    }
    else if (key_comp(*key, *bst->tree_nodes[position].key) > 0){
        position = (2 * position) + 1;
        if(position > bst->size){
            printf("Array out of bounds error\n");
            exit(1);
        }
        bstree_insert_node_recursively(bst, key, data, position);
    }
    else{
        return;
    }
}

// Input: ’bst’: a binary search tree
// ’key’: a pointer to Key
// ’data’: an integer
// Effect: ’data’ with ’key’ is inserted into ’bst’
// if ’key’ is already in ’bst’, do nothing
void bstree_insert(BStree bst, Key *key, int data) {
    bstree_insert_node_recursively(bst, key, data, 1);
}

// Input: ’bst’: a binary search tree
// 'position': an integer
// Effect: print all the nodes recursively in bst using in order traversal
void bstree_traversal_recursive(BStree bst, int position) {
    if(bst->is_free[position] == '0'){
        if((position * 2) < bst->size + 1){
            bstree_traversal_recursive(bst, (position * 2));
        }
        print_node(bst->tree_nodes[position]);
        if((position * 2 + 1) < bst->size + 1){
            bstree_traversal_recursive(bst, ((position * 2) + 1));
        }
    }
}

// Input: ’bst’: a binary search tree
// Effect: print all the nodes in bst using in order traversal
void bstree_traversal(BStree bst) {
    bstree_traversal_recursive(bst, 1);
}

// Input: ’bst’: a binary search tree
// Effect: all memory used by bst are freed
void bstree_free(BStree bst) {
    free(bst->tree_nodes);
    free(bst->is_free);
    free(bst);
}

