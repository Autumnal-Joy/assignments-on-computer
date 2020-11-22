#if !defined(MINTREE_H)
#define MINTREE_H

#include "graph.h"

// 返回prim算法得到的邻接矩阵表示的最小生成树
Graph* prim(Graph* graph);

// 返回kruskal算法得到的邻接矩阵表示的最小生成树
Graph* kruskal(Graph* graph);

// 返回去边法得到的邻接矩阵表示的最小生成树
Graph* delEdge(Graph* graph);

#endif  // MINTREE_H
