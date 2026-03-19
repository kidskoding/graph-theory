#ifndef GRAPH_UTILITIES_HPP
#define GRAPH_UTILITIES_HPP

#include "graph.h"
#include <map>
#include <utility>
#include <set>

namespace graph_utilities {
    // Returns the maximum number of edges possible in this graph (assumes complete graph).
    // Strategy: Use the handshaking lemma formula N*(N-1)/2 — the number of unique node pairs.
    //           Dividing by 2 avoids counting each undirected edge twice (once per endpoint).
    template <typename T>
    int getEdges(Graph<T>& graph) {
        int nodes = graph.graph.size();
        return nodes * (nodes - 1) / 2;
    }

    // Returns the number of nodes (order) in the graph.
    // Strategy: The graph stores all nodes in a vector — its size is the node count.
    template <typename T>
    int getNodes(Graph<T>& graph) {
        return graph.graph.size();
    }

    // Returns a map from every node to its degree (number of edges connected to it).
    // Strategy: Iterate every node and read the size of its neighbors list.
    //           Each entry in neighbors represents one edge, so neighbors.size() == degree.
    template <typename T>
    std::map<GraphNode<T>*, int> getDegrees(Graph<T>& graph) {
        std::map<GraphNode<T>*, int> map;

        for(GraphNode<T>*& node : graph.graph) {
            map.insert(std::make_pair(node, node->neighbors.size()));
        }

        return map;
    }

    // Returns the degree of a single node.
    // Strategy: A node's degree equals the number of entries in its neighbors list.
    template <typename T>
    int getDegree(GraphNode<T>*& node) {
        return node->neighbors.size();
    }

    // Returns true if the graph obeys the handshaking lemma (sum of all degrees must be even).
    // Concept: Every edge contributes exactly 2 to the total degree sum (one per endpoint).
    //          So the sum is always even in a valid undirected graph.
    // Strategy: Sum all node degrees; if the sum is odd, the graph is malformed.
    template <typename T>
    bool isValidGraph(Graph<T>& graph) {
        auto degrees = graph_utilities::getDegrees(graph);
        int sum = 0;
        for(auto& pair : degrees) {
            sum += pair.second;
        }
        return sum % 2 == 0;
    }

    // Assigns a color (integer) to each node so no two adjacent nodes share the same color.
    // Concept: Graph coloring — minimizing colors used is NP-hard, but a greedy approximation works well.
    // Strategy: Sort nodes by degree descending (highest-degree nodes are hardest to color, do them first).
    //           For each node, collect colors already used by its neighbors, then assign the smallest
    //           non-conflicting color (first non-negative integer not in the used-colors set).
    template <typename T>
    std::map<GraphNode<T>*, int> color(Graph<T>& graph) {
        auto degreesMap = graph_utilities::getDegrees(graph);
        std::vector<std::pair<GraphNode<T>*, int>> nodeDegrees(degreesMap.begin(), degreesMap.end());

        std::sort(nodeDegrees.begin(), nodeDegrees.end(),
                [](const auto& a, const auto& b) {
                    return a.second > b.second;
                });

        std::map<GraphNode<T>*, int> nodeColor;
        for(const auto& nd : nodeDegrees) {
            nodeColor[nd.first] = -1;
        }

        for(const auto& nd : nodeDegrees) {
            GraphNode<T>* node = nd.first;

            std::set<int> usedColors;
            for(const auto& neighborTup : node->neighbors) {
                GraphNode<T>* neighbor = std::get<0>(neighborTup);
                int c = nodeColor[neighbor];
                if(c != -1) {
                    usedColors.insert(c);
                }
            }

            int color = 0;
            while(usedColors.find(color) != usedColors.end()) {
                ++color;
            }

            nodeColor[node] = color;
        }

        return nodeColor;
    }
}

#endif //GRAPH_UTILITIES_HPP
