#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int vertex;
    int** matrix;
} Graph;

typedef struct {
    int rows;
    int** array;
} Triples;

extern FILE* fp;

Graph* newGraph(int vertex) {
    Graph* g = (Graph*)malloc(sizeof(Graph));
    g->vertex = vertex;
    g->matrix = (int**)malloc(sizeof(int*) * vertex);
    for (int i = 0; i < vertex; i++) {
        g->matrix[i] = (int*)calloc(sizeof(int), vertex);
    }
    return g;
}

void delGraph(Graph* graph) {
    for (int i = 0; i < graph->vertex; i++) {
        free(graph->matrix[i]);
    }
    free(graph->matrix);
    free(graph);
}

Graph* fillGraph(Graph* graph, int directed) {
    puts("relation of vertex(initial end weight)");
    char str[100];
    int n = 0, a, b, weight;
    while (1) {
        fgets(str, 100, fp);
        weight = 1;
        n = sscanf(str, "%d %d %d", &a, &b, &weight);
        if (n < 2) {
            break;
        }
        if (a >= graph->vertex || b >= graph->vertex || a < 0 || b < 0) {
            puts("out of range");
        } else if (a == b) {
            puts("illegal");
        } else {
            if (!directed) {
                graph->matrix[b][a] = weight;
            }
            graph->matrix[a][b] = weight;
        }
    }
    return graph;
}

void printGraph(Graph* graph) {
    printf("[");
    for (int i = 0; i < graph->vertex; i++) {
        printf("[");
        for (int j = 0; j < graph->vertex; j++) {
            printf("%d", graph->matrix[i][j]);
            if (j < graph->vertex - 1) {
                putchar(' ');
            }
        }
        printf("]");
        if (i < graph->vertex - 1) {
            printf(",\n");
        }
    }
    printf("]\n");
}

Graph* copyGraph(Graph* graph) {
    Graph* p = newGraph(graph->vertex);
    for (int i = 0; i < graph->vertex; i++) {
        for (int j = 0; j < graph->vertex; j++) {
            p->matrix[i][j] = graph->matrix[i][j];
        }
    }
    return p;
}

Triples* toTriple(Graph* graph) {
    int cnt = 0;
    for (int i = 0; i < graph->vertex; i++) {
        for (int j = i + 1; j < graph->vertex; j++) {
            if (graph->matrix[i][j]) {
                cnt++;
            }
        }
    }
    Triples* t = (Triples*)malloc(sizeof(Triples));
    t->rows = cnt;
    t->array = (int**)malloc(sizeof(int*) * cnt);
    int index = 0;
    for (int i = 0; i < graph->vertex; i++) {
        for (int j = i + 1; j < graph->vertex; j++) {
            if (graph->matrix[i][j]) {
                t->array[index] = (int*)malloc(sizeof(int) * 3);
                t->array[index][0] = i;
                t->array[index][1] = j;
                t->array[index++][2] = graph->matrix[i][j];
            }
        }
    }
    return t;
}

void delTriples(Triples* triples) {
    for (int i = 0; i < triples->rows; i++) {
        free(triples->array[i]);
    }
    free(triples->array);
    free(triples);
}