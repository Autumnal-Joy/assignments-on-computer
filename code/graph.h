#if !defined(GRAPH_H)
#define GRAPH_H

typedef struct {
    int vertex;
    int** matrix;
} Graph;

typedef struct {
    int rows;
    int** array;
} Triples;

Graph* newGraph(int vertex);
Graph* copyGraph(Graph* graph);
void delGraph(Graph* graph);
Graph* fillGraph(Graph* graph, int directed);
void printGraph(Graph* graph);
Triples* toTriple(Graph* graph, int vertex);
void delTriples(Triples* triples);

#endif  // GRAPH_H
