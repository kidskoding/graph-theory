#ifndef SPANNING_TREE_HPP
#define SPANNING_TREE_HPP

#include "graph.h"
#include <vector>
#include <tuple>
#include <map>

namespace spanning_tree {
    // Finds a Minimum Spanning Tree (MST) starting from `start`.
    // Works on connected, undirected, weighted graphs.
    // Strategy: greedily grow the MST by always picking the cheapest edge
    //           that connects an unvisited node to the current tree.
    // Returns the list of edges (node_a, node_b, weight) in the MST.
    template <typename T>
    std::vector<std::tuple<GraphNode<T>*, GraphNode<T>*, T>> prims(Graph<T>& graph, GraphNode<T>* start) {
        // TODO: implement
        return {};
    }

    // Finds a Minimum Spanning Tree using a Union-Find (disjoint set) approach.
    // Strategy: sort all edges by weight; add an edge if it connects two different components (no cycle).
    // Works on disconnected graphs — produces a Minimum Spanning Forest.
    // Returns the list of edges (node_a, node_b, weight) in the MST/MSF.
    template <typename T>
    std::vector<std::tuple<GraphNode<T>*, GraphNode<T>*, T>> kruskals(Graph<T>& graph) {
        // TODO: implement
        return {};
    }

    // Helper for Kruskal's: finds the root of a node's component with path compression.
    template <typename T>
    GraphNode<T>* find(std::map<GraphNode<T>*, GraphNode<T>*>& parent, GraphNode<T>* node) {
        // TODO: implement
        return nullptr;
    }

    // Helper for Kruskal's: merges two components by rank (union by rank).
    template <typename T>
    void unite(
        std::map<GraphNode<T>*, GraphNode<T>*>& parent,
        std::map<GraphNode<T>*, int>& rank,
        GraphNode<T>* a,
        GraphNode<T>* b
    ) {
        // TODO: implement
    }
} // namespace spanning_tree

#endif // SPANNING_TREE_HPP
