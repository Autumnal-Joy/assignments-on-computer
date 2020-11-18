#if !defined(GRAPH_H)
#define GRAPH_H

typedef struct {
    int vertex;
    int** matrix;
} Graph;

Graph* getGraph(int vertex);
void delGraph(Graph* graph);
Graph* fillGraph(Graph* graph, int directed);
void printGraph(Graph* graph);

#endif  // GRAPH_H
