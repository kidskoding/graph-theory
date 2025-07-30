#ifndef GRAPH_NODE_H
#define GRAPH_NODE_H

#include <vector>
#include <tuple>

template <typename T>
struct GraphNode {
    T data;
    std::vector<std::tuple<GraphNode<T>*, T>> neighbors;

    GraphNode(const T& data) : data(data) { }
};

#endif // GRAPH_NODE_H