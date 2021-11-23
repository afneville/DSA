#ifndef graph_H
#define graph_H

typedef struct graph_T {
    int num_nodes;
    int ** nodes;
} graph;

graph * create_graph();

#endif // graph_H
