#include "graph.h"

static int cmp(const void* a, const void* b) {
    return ((int*)a)[2] - ((int*)b)[2];
}

static void sort(int** a, int length) {
    for (int i = 0; i < length; i++) {
        for (int j = i + 1; j < length; j++)
            if (a[i][2] > a[j][2]) {
                int* t = a[i];
                a[i] = a[j];
                a[j] = t;
            }
    }
}

int hasCircle(Graph* graph, int from, int start, int target) {
    if (start == target) {
        return 1;
    }
    for (int i = 0; i < graph->vertex; i++) {
        if (graph->matrix[start][i] && i != from &&
            hasCircle(graph, start, i, target)) {
            return 1;
        }
    }
    return 0;
}

Graph* kruskal(Graph* graph) {
    int vertex = graph->vertex;
    Graph* k = newGraph(vertex);
    Triples* t = toTriple(graph, vertex);
    sort(t->array, t->rows);
    // 排序后的三元组t->array
    for (int i = 0, cnt = 1; cnt < vertex; i++) {
        if (!hasCircle(k, vertex, t->array[i][0], t->array[i][1])) {
            // 没有回路
            k->matrix[t->array[i][0]][t->array[i][1]] =
                k->matrix[t->array[i][1]][t->array[i][0]] = t->array[i][2];
            cnt++;
        }
    }
    return k;
}
