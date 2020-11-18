#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

Graph* prim(Graph* graph);
Graph* kruskal(Graph* graph);

FILE* fp = stdin;

int main(int argc, char const* argv[]) {
    fp = fopen("input", "r");
    int vertex;
    puts("number of vertex:");
    fscanf(fp, "%d%*c", &vertex);

    Graph* graph = fillGraph(getGraph(vertex), 0);
    Graph* pGraph = prim(graph);
    Graph* kGraph = kruskal(graph);

    printGraph(graph);
    printGraph(pGraph);
    printGraph(kGraph);

    delGraph(graph);
    delGraph(pGraph);
    delGraph(kGraph);
    return 0;
}

Graph* prim(Graph* graph) {
    int vertex = graph->vertex;
    int** matrix = graph->matrix;
    Graph* p = getGraph(vertex);
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
                    matrix[j][k] && matrix[j][k] < minWeight[j]) {
                    // 找到更短边
                    minWeight[j] = matrix[j][k];
                    adjacency[j] = k;
                }
            }
        }
        int loc = 0, min = 0;
        for (int j = 0; j < vertex; j++) {
            if (!min || minWeight[j] && minWeight[j] < min) {
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

/* input:
    8
    0 1 2
    0 2 3
    1 3 2
    2 3 1
    3 4 2
    3 5 4
    4 5 1
    4 6 2
    5 6 2
    5 7 1
    6 7 3


*/

/* stdout:

*/