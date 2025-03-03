#ifndef GRAPH_NODE_H
#define GRAPH_NODE_H

template <typename T>
class GraphNode {
public:
    T value;

    GraphNode(T value) : value(value) {}
};

#endif //GRAPH_NODE_H
