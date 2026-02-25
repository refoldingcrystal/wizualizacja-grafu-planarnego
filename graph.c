#include "graph.h"
#include <stdio.h>
#include <stdlib.h>

#define INIT_SIZE 16

void init_graph(graph_t *graph) {
    graph->vertices = 0;
    graph->size = INIT_SIZE;
    graph->edges = malloc(graph->size * sizeof(edge_list_t));
    for (int i = 0; i < graph->size; i++) {
        graph->edges[i] = NULL;
    }
}

void free_graph(graph_t *graph) {
    for (int i = 0; i < graph->size; i++) {
        edge_list_t *edge;
        while (edge != NULL) {
            edge_list_t *next = edge->next;
            free(edge->name);
            free(edge);
            edge = next;
        }
    }
    free(graph->edges);
}

void print_graph(graph_t *graph, FILE *f){
    for (int i=0; i<graph->vertices; i++){
        edge_list_t *v = graph->edges[i];
        fprintf(f, "%d : ", i);
        if (v == NULL){
            fprintf(f, "--");
        } else {
            while (v != NULL){
                fprintf(f, "(%g)->%d ", v->weight, v->dest);
                v = v->next;
            }
            fprintf(f, "\n");
        }
    }
}
