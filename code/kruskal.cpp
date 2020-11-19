#include <stdlib.h>
#include "graph.h"

int cmp(const void* a, const void* b) {
    return ((int*)a)[2] - ((int*)b)[2];
}

int find(Graph* graph, int from, int start, int target) {
    if (start == target) {
        return 1;
    }
    for (int i = 0; i < graph->vertex; i++) {
        if (graph->matrix[start][i] && i != from &&
            find(graph, start, i, target)) {
            return 1;
        }
    }
    return 0;
}

Graph* kruskal(Graph* graph) {
    int vertex = graph->vertex;
    int** matrix = graph->matrix;
    Graph* k = getGraph(vertex);
    int arc[vertex * vertex / 2][3] = {0}, length = 0;
    for (int i = 0; i < vertex; i++) {
        for (int j = i + 1; j < vertex; j++) {
            if (matrix[i][j]) {
                arc[length][0] = i;
                arc[length][1] = j;
                arc[length][2] = matrix[i][j];
                length++;
            }
        }
    }
    qsort(arc, length, sizeof(arc[0]), cmp);
    // 排序后的三元组arc
    for (int i = 0, cnt = 1; cnt < vertex; i++) {
        if (!find(k, vertex, arc[i][0], arc[i][1])) {
            // 没有回路
            k->matrix[arc[i][0]][arc[i][1]] = k->matrix[arc[i][1]][arc[i][0]] =
                arc[i][2];
            cnt++;
        }
    }
    return k;
}
