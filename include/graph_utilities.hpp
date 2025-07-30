#ifndef GRAPH_UTILITIES_HPP
#define GRAPH_UTILITIES_HPP

#include "graph.h"
#include <map>
#include <utility>
#include <set>

namespace graph_utilities {
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
