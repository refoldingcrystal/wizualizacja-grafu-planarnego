#include "graph.h"
#include <getopt.h>
#include <stdio.h>

void help() {}

int main(int argc, char **argv) {
  int opt;
  char *input = NULL;
  char *output = NULL;
  int verbose = 0;

  while ((opt = getopt(argc, argv, "o:vh")) != -1) {
    switch (opt) {
    case 'o':
      output = optarg;
      break;
    case 'v':
      verbose = 1;
      break;
    case 'h':
      help();
      return 0;
    default:
      help();
      return 1;
    }
  }
  if (optind < argc) {
    input = argv[optind];
  } else {
    fprintf(stderr, "Blad: brak pliku wejsciowego\n");
    help();
    return 1;
  }

  graph_t *graph = init_graph();
  load_graph(graph, input);
  print_graph(graph, output);

  return 0;
}
