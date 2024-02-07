#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../inc/map.h"


int hash(char key){

    int unicode = (int) key;
    int hashed = unicode % SIZE; 
    return hashed;

}

void insert_map(map * map_p, char key, int value) {

    int index = hash(key);
    int counter = 0;
    bool inserted = false;

    /* Iterate over all positions & wrap around.
    Counter makes sure that only one pass is made. */
    /* while (map_p->table[index] != NULL && counter < SIZE){ */
    while (counter < SIZE && inserted == false){

        if (map_p->table[index] == NULL){

            map_p->table[index] = (pair *) malloc(sizeof(pair));
            map_p->table[index]->key = key;
            map_p->table[index]->value = value;
            printf("Key: %c => Value: %d; Index: %d\n", key, value, index);
            inserted = true;

        }

        index ++;
        counter ++;
        index = index % SIZE;

    }

}

int search_map(map * map_p, char key) {

    int index = hash(key);
    int counter = 0;
    bool located = false;
    /* int value = NULL; */
    int value = NULL;

    while (counter < SIZE && located == false) {

        if (map_p->table[index]->key == key) {

            value = map_p->table[index]->value;
            located = true;

        }

        index ++;
        index = index % SIZE;
        counter ++;
    }

    return value;

}

map * create_map(){

    map * new_map = (map *) malloc(sizeof(map)*1);

    for (int i = 0; i < SIZE; i ++) {

        ( * new_map ).table[i] = NULL;

    }
    return new_map;

}
