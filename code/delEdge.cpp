#include <stdlib.h>
#include "graph.h"

static int cmp(const void* a, const void* b) {
    return ((int*)b)[2] - ((int*)a)[2];
}
int dfs(Graph* d, int start, int* visited) {
    visited[start] = 1;
    int cnt = 1;
    for (int i = 0; i < d->vertex; i++) {
        if (!visited[i]) {
            visited[i] = 1;
            cnt += dfs(d, i, visited);
        }
    }
    return cnt;
}
// 是否连通
int connected(Graph* d) {
    int visited[d->vertex] = {0};
    return dfs(d, 0, visited) == d->vertex;
}

Graph* delEdge(Graph* graph) {
    Graph* d = copyGraph(graph);
    Triples* t = toTriple(d, d->vertex);
    // 降序排序三元组t->array
    qsort(t->array, t->rows, sizeof(t->array[0]), cmp);
    for (int i = 0; i < t->rows; i++) {
        // 删除array[i]在矩阵中的对应元素
        d->matrix[t->array[i][0]][t->array[i][1]] =
            d->matrix[t->array[i][1]][t->array[i][0]] = 0;
        if (!connected(d)) {
            // 不连通, 则还原
            d->matrix[t->array[i][0]][t->array[i][1]] =
                d->matrix[t->array[i][1]][t->array[i][0]] = t->array[i][2];
        }
    }
    return d;
}
