#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 10
// these are the structures used in the hashmap

typedef struct pair {

    char key;
    int value;

} pair;


typedef struct map_T {

    pair * table[SIZE];

} map;

// behaviours associated with the hashmap


int hash(char key){

    int unicode = (int) key;
    int hashed = unicode % SIZE; 
    return hashed;

}

void insert(map * map_p, char key, int value) {

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

int search(map * map_p, char key) {

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

int main(int argc, char *argv[]){

    map * map1_p = create_map();

    insert(map1_p, 'a', 1);
    insert(map1_p, 'j', 2);
    insert(map1_p, 'b', 3);
    insert(map1_p, 'f', 1);
    insert(map1_p, 'd', 5);
    insert(map1_p, 'i', 2);
    insert(map1_p, 'c', 2);
    insert(map1_p, 'h', 3);
    insert(map1_p, 'e', 4);
    insert(map1_p, 'g', 8);

    printf("\n%c => %d\n", 'a', search(map1_p, 'a'));
    printf("\n%c => %d\n", 'e', search(map1_p, 'e'));
    /* printf("\n%c => %d\n", 'z', search(map1_p, 'z')); */

}
