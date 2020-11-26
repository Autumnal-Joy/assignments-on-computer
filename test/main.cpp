#include <stdio.h>
#include "../code/graph.h"
#include "../code/minTree.h"

FILE *fp = stdin;

int main(int argc, char const *argv[])
{
    fp = fopen("test/input", "r");
    int vertex;
    puts("number of vertex:");
    fscanf(fp, "%d%*c", &vertex);

    Graph *graph = fillGraph(newGraph(vertex), 0);

    Graph *pGraph = prim(graph);
    Graph *kGraph = kruskal(graph);
    Graph *dGraph = delEdge(graph);

    printf("Graph:\n");
    printGraph(graph);

    printf("Prim:\n");
    printGraph(pGraph);
    printf("kruskal:\n");
    printGraph(kGraph);
    printf("delEdge:\n");
    printGraph(dGraph);

    delGraph(graph);
    delGraph(pGraph);
    delGraph(kGraph);
    delGraph(dGraph);

    fclose(fp);
    return 0;
}