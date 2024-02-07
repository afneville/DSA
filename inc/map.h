#ifndef map_H
#define map_H

#define SIZE 10

typedef struct pair {

    char key;
    int value;

} pair;


typedef struct map_T {

    pair * table[SIZE];

} map;


int hash(char key);
void insert_map(map * map_p, char key, int value);
int search_map(map * map_p, char key);
map * create_map();

#endif // !map_H
