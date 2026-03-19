#ifndef SHORTEST_PATH_HPP
#define SHORTEST_PATH_HPP

#include "graph.h"
#include <map>
#include <vector>
#include <limits>

namespace shortest_path {
    // Finds the shortest distance from `start` to every other node.
    // Works on weighted graphs with NON-NEGATIVE edge weights only.
    // Strategy: greedily pick the unvisited node with the smallest known distance, then relax its edges.
    // Returns a map from each node to its shortest distance from `start`.
    template <typename T>
    std::map<GraphNode<T>*, T> dijkstra(Graph<T>& graph, GraphNode<T>* start) {
        // TODO: implement
        return {};
    }

    // Finds shortest distances from `start` to all other nodes.
    // Handles NEGATIVE edge weights. Detects negative-weight cycles.
    // Strategy: relax ALL edges (V-1) times; if any edge can still be relaxed, a negative cycle exists.
    // Returns empty map if a negative cycle is detected.
    template <typename T>
    std::map<GraphNode<T>*, T> bellman_ford(Graph<T>& graph, GraphNode<T>* start) {
        // TODO: implement
        return {};
    }

    // Finds shortest paths between ALL pairs of nodes.
    // Handles negative weights but not negative cycles.
    // Strategy: dynamic programming — for each intermediate node k, update dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]).
    // Returns a 2D map: dist[a][b] = shortest distance from a to b.
    template <typename T>
    std::map<GraphNode<T>*, std::map<GraphNode<T>*, T>> floyd_warshall(Graph<T>& graph) {
        // TODO: implement
        return {};
    }

    // Reconstructs the actual path (list of nodes) from `start` to `end` given a dijkstra/bellman-ford result.
    // Requires a `previous` map that records how each node was reached.
    template <typename T>
    std::vector<GraphNode<T>*> reconstruct_path(
        std::map<GraphNode<T>*, GraphNode<T>*>& prev,
        GraphNode<T>* start,
        GraphNode<T>* end
    ) {
        // TODO: implement
        return {};
    }

} // namespace shortest_path

#endif // SHORTEST_PATH_HPP
