#ifndef GRAPH_H
#define GRAPH_H

#include <stdio.h>

typedef struct edge {
    char *name;
    int dest;
    double weight;
    struct edge *next;
} edge_list_t;

typedef struct {
    int vertices;
    edge_list_t **edges;
    int size;
} graph_t;

void init_graph(graph_t *graph);
void free_graph(graph_t *graph);
void print_graph(graph_t *graph, FILE *f);

#endif
