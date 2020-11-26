#include "graph.h"

Graph* prim(Graph* graph) {
    int vertex = graph->vertex;
    int** matrix = graph->matrix;
    Graph* p = newGraph(vertex);
    int flag[vertex] = {1};
    int last = 0;
    int minWeight[vertex] = {0};
    int adjacency[vertex] = {0};
    for (int cnt = 1; cnt < vertex; cnt++) {
        // 更新集合外的点i到集合内的最小距离minWeight[i],
        // 和对应在集合内的邻接点adjacency[i]
        for (int i = 0; i < vertex; i++) {
            // 找到集合外的点
            if (flag[i]) {
                continue;
            }
            if (minWeight[i] == 0 || matrix[last][i] < minWeight[i]) {
                minWeight[i] = matrix[last][i];
                adjacency[i] = last;
            }
        }
        // 找到minWeight的最小值minW和对应的点minI
        int minI = 0;
        int minW = 0;
        for (int i = 0; i < vertex; i++) {
            // 找到集合外的点
            if (flag[i]) {
                continue;
            }
            if (minW == 0 || minWeight[i] != 0 && minWeight[i] < minW) {
                minW = minWeight[i];
                minI = i;
            }
        }
        last = minI;
        // 将点minI加入集合, 将对应边加入图
        flag[minI] = 1;
        p->matrix[minI][adjacency[minI]] = p->matrix[adjacency[minI]][minI] =
            minW;
    }
    return p;
}