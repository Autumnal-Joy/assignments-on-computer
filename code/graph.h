#if !defined(GRAPH_H)
#define GRAPH_H

// 图的邻接矩阵表示法
typedef struct {
    int vertex;
    int** matrix;
} Graph;

// 图的三元组表示法
typedef struct {
    int rows;
    int** array;
} Triples;

// 传顶点个数, 返回邻接矩阵表示的无边图
Graph* newGraph(int vertex);

/*
    graph: 复制的对象
    return: 复制的结果
    功能: 将图复制, 返回复制后的图
*/
Graph* copyGraph(Graph* graph);

/*
    graph: 删除的对象
    功能: 删除图,释放内存
*/
void delGraph(Graph* graph);

/*
    directed:1为有向图,0为无向图
    graph:传入的图
    功能:把关系与权值存入图
*/
Graph* fillGraph(Graph* graph, int directed);

/*
    graph:传入的图
    功能:打印邻接矩阵
*/
void printGraph(Graph* graph);

/*
    graph:传入的图
    功能:传邻接矩阵表示的图, 返回三元组表示的图
*/
Triples* toTriple(Graph* graph);

/*
    triples:传入的图
    功能删除三元组表示的图
*/
void delTriples(Triples* triples);

#endif  // GRAPH_H
