#include <stdio.h>
#include "graph.h"
#include "minTree.h"

FILE* fp = stdin;

int main(int argc, char const* argv[]) {
    fp = fopen("input", "r");
    int vertex;
    puts("number of vertex:");
    fscanf(fp, "%d%*c", &vertex);

    Graph* graph = fillGraph(getGraph(vertex), 0);
    Graph* pGraph = prim(graph);
    Graph* kGraph = kruskal(graph);

    printGraph(graph);
    printGraph(pGraph);
    printGraph(kGraph);

    delGraph(graph);
    delGraph(pGraph);
    delGraph(kGraph);
    return 0;
}