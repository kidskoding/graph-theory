#ifndef GRAPH_H
#define GRAPH_H

#include "graph_node.h"
#include <vector>

template <class T>
class Graph {
public:    
    std::vector<GraphNode<T>*> graph;

    ~Graph();

    void addNode(GraphNode<T>* graphNode);
    void removeNode(GraphNode<T>*& graphNode);
    void addEdge(GraphNode<T>*& a, GraphNode<T>*& b, T weight);
    void removeEdge(GraphNode<T>*& a, GraphNode<T>*& b);
};

#endif // GRAPH_H
