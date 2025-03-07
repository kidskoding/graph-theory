#ifndef GRAPH_H
#define GRAPH_H

#include "graph_node.h"
#include <unordered_map>
#include <unordered_set>
#include <tuple>

template <typename T>
class Graph {
public:
    std::unordered_map<std::shared_ptr<GraphNode<T>>, std::unordered_set<std::tuple<std::shared_ptr<GraphNode<T>>, std::shared_ptr<T>>>> graph;

    void addNode(std::shared_ptr<GraphNode<T>> node);
    void removeNode(std::shared_ptr<GraphNode<T>> node);
    void addEdge(std::shared_ptr<GraphNode<T>> a, std::shared_ptr<GraphNode<T>> b, std::shared_ptr<T> weight);
    void removeEdge(std::shared_ptr<GraphNode<T>> a, std::shared_ptr<GraphNode<T>> b);
};

#endif //GRAPH_H
