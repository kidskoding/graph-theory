#ifndef GRAPH_UTILITIES_H
#define GRAPH_UTILITIES_H

#include "graph.hpp"
#include <algorithm>
#include <map>
#include <utility>
#include <vector>

namespace graph_utilities {
    // test comment for gh profile readme

    template <typename T>
    int getEdges(Graph<T>& graph) {
        int nodes = graph.graph.size();
        return nodes * (nodes - 1) / 2;
    }

    template <typename T>
    int getNodes(Graph<T>& graph) {
        return graph.graph.size();
    }

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

    template <typename T>
    bool isValidGraph(Graph<T>& graph) {
        auto degrees = graph_utilities::getDegrees(graph);
        int sum = 0;
        for(auto& pair : degrees) {
            sum += pair.second;
        }
        return sum % 2 == 0;
    }

    template <typename T>
    std::vector<std::vector<GraphNode<T>*>> color(Graph<T>& graph) {
        std::vector<std::vector<GraphNode<T>*>> list;
        auto map = graph_utilities::getDegrees(graph); 
        std::vector<int> degrees;
        for(const auto& pair : map) {
            degrees.push_back(pair.second);
        }

        int i = degrees.size() - 1;
        while(i >= 0) {
            int maxDegree = *std::max_element(degrees.begin(), degrees.end());
            // find the key associated with maxDegree in map
            i -= 1;
        }

        return list;
    }
}

#endif //GRAPH_UTILITIES_H
