#include <stdio.h>
#include "graph.h"
#include "minTree.h"

FILE* fp = stdin;

int main(int argc, char const* argv[]) {
    fp = fopen("code/input", "r");
    int vertex;
    puts("number of vertex:");
    fscanf(fp, "%d%*c", &vertex);

    Graph* graph = fillGraph(newGraph(vertex), 0);
    Graph* pGraph = prim(graph);
    Graph* kGraph = kruskal(graph);
    Graph* dGraph = delEdge(graph);

    putchar('\n');
    printGraph(graph);
    putchar('\n');
    printGraph(pGraph);
    putchar('\n');
    printGraph(kGraph);
    putchar('\n');
    printGraph(dGraph);
    putchar('\n');

    delGraph(graph);
    delGraph(pGraph);
    delGraph(kGraph);
    delGraph(dGraph);

    fclose(fp);
    return 0;
}