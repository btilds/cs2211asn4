//
//  data.h
//  Assignment 4
//
//  Created by Ben Tilden on 2018-11-04.
//  Copyright © 2018 Ben Tilden. All rights reserved.
//

#ifndef data_h
#define data_h

#include <stdio.h>

typedef struct {
    char *name;
    int id;
} Key;

typedef struct {
    Key *key;
    int data;
} Node;

Key *key_construct(char *in_name, int in_id);
int key_comp (Key key1, Key key2);
void print_key(Key *key);
void print_node(Node node);

#endif /* data_h */
