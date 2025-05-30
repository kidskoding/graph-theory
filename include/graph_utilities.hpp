#ifndef GRAPH_UTILITIES_H
#define GRAPH_UTILITIES_H

#include "graph.hpp"
#include <map>
#include <utility>

namespace graph_utilities {
    template <typename T>
    std::map<GraphNode<T>*, int> getDegrees(Graph<T>& graph) {
        std::map<GraphNode<T>*, int> map;

        for(GraphNode<T>*& node : graph.graph) {
            map.insert(std::make_pair(node, node->neighbors.size()));
        }

        return map;
    }

    template <typename T>
    int getDegree(GraphNode<T>*& node) {
        return node->neighbors.size();
    }
}

#endif //GRAPH_UTILITIES_H
