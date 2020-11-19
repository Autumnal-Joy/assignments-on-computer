#include <stdlib.h>
#include "graph.h"

int cmp(const void* a, const void* b) {
    return ((int*)b)[2] - ((int*)a)[2];
}
int dfs(Triples* t, int start, int* visited) {
    visited[start] = 1;
    int cnt = 1;
    for (int i = 0; i < t->rows; i++) {
        if (t->array[i][0] == start && !visited[t->array[i][1]]) {
            cnt += dfs(t, i, visited);
        }
        if (t->array[i][1] == start && !visited[t->array[i][0]]) {
            cnt += dfs(t, i, visited);
        }
    }
    return cnt;
}
// 是否连通
int connected(Triples* t) {
    int visited[t->rows] = {0};
    return dfs(t, 0, visited) == t->rows;
}

Graph* delEdge(Graph* graph) {
    int vertex = graph->vertex;
    int** matrix = graph->matrix;
    Graph* d = copyGraph(graph);
    Triples* t = toTriple(d, d->vertex);
    // 降序排序三元组t->array
    qsort(t->array, t->rows, sizeof(t->array[0]), cmp);
    for (int i = 0; i < t->rows; i++) {
        // 删除array[i]在矩阵中的对应元素
        d->matrix[t->array[i][0]][t->array[i][1]] =
            d->matrix[t->array[i][1]][t->array[i][0]] = 0;
        if (!connected(t)) {
            // 不连通, 则还原
            d->matrix[t->array[i][0]][t->array[i][1]] =
                d->matrix[t->array[i][1]][t->array[i][0]] = t->array[i][2];
        }
    }
    return d;
}
