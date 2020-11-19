#include <stdlib.h>
#include "graph.h"

int cmp(const void* a, const void* b) {
    return ((int*)b)[2] - ((int*)a)[2];
}

// 是否连通
int connected(Graph* graph) {}

Graph* delEdge(Graph* graph) {
    int vertex = graph->vertex;
    int** matrix = graph->matrix;
    Graph* d = copyGraph(graph);

    Triples* t = toTriple(d, d->vertex);

    qsort(t->array, t->rows, sizeof(t->array[0]), cmp);
    // 降序排序后的三元组t->array
    for (int i = 0, cnt = 1; cnt < vertex; i++) {
        // 删除array[i]在矩阵中的对应元素
        if (!connected(d)) {
            // 不连通, 则还原
        }
    }
    return d;
}
