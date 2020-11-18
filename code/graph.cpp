#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int vertex;
    int** matrix;
} Graph;

extern FILE* fp;

Graph* getGraph(int vertex) {
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
    char str[10];
    int n = 0, a, b, weight = 1;
    do {
        fgets(str, 100, fp);
        n = sscanf(str, "%d %d %d", &a, &b, &weight);
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
    } while (n > 1);
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