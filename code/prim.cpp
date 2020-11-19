#include "graph.h"

Graph* prim(Graph* graph) {
    int vertex = graph->vertex;
    int** matrix = graph->matrix;
    Graph* p = newGraph(vertex);
    int flag[vertex] = {1};
    for (int i = 1; i < vertex; i++) {
        int minWeight[vertex] = {0};
        int adjacency[vertex] = {0};
        for (int j = 0; j < vertex; j++) {
            if (flag[j]) {
                continue;
            }
            // 找到没有包含在集合内的点
            for (int k = 0; k < vertex; k++) {
                if (!flag[k]) {
                    continue;
                }
                // 找到集合内的点
                if (!minWeight[j] ||
                    (matrix[j][k] && matrix[j][k] < minWeight[j])) {
                    // 找到更短边
                    minWeight[j] = matrix[j][k];
                    adjacency[j] = k;
                }
            }
        }
        int loc = 0, min = 0;
        for (int j = 0; j < vertex; j++) {
            if (!min || (minWeight[j] && minWeight[j] < min)) {
                min = minWeight[j];
                loc = j;
            }
        }
        // loc是与集合距离最近的点, adjacency[loc]是邻接点
        p->matrix[adjacency[loc]][loc] = p->matrix[loc][adjacency[loc]] = min;
        flag[loc] = 1;
    }
    return p;
}