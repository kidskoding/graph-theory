#ifndef TRAVERSALS_HPP
#define TRAVERSALS_HPP

#include "graph.h"
#include <vector>
#include <unordered_set>

namespace traversals {
    // Visits all nodes reachable from `start` by going as deep as possible before backtracking.
    // Order: visit a node, recurse into each unvisited neighbor before moving to the next.
    // Uses the call stack for recursion.
    template <typename T>
    void dfs_recursive(GraphNode<T>* start, std::unordered_set<GraphNode<T>*>& visited) {
        // TODO: implement
    }

    // Same traversal order as dfs_recursive but uses an explicit stack instead of recursion.
    // Useful for very deep graphs where recursion would overflow the call stack.
    template <typename T>
    void dfs_iterative(GraphNode<T>* start) {
        // TODO: implement
    }

    // Visits all nodes reachable from `start` level by level (closest nodes first).
    // Uses a queue. Good for finding shortest paths in unweighted graphs.
    template <typename T>
    void bfs(GraphNode<T>* start) {
        // TODO: implement
    }

    // Returns the order in which DFS visits all nodes in the graph (handles disconnected graphs).
    template <typename T>
    std::vector<GraphNode<T>*> dfs_order(Graph<T>& graph) {
        // TODO: implement
        return {};
    }

    // Returns the order in which BFS visits all nodes in the graph (handles disconnected graphs).
    template <typename T>
    std::vector<GraphNode<T>*> bfs_order(Graph<T>& graph) {
        // TODO: implement
        return {};
    }

} // namespace traversals

#endif // TRAVERSALS_HPP
